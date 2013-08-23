#include "diaryposter.h"
#include <QDebug>

DiaryPoster::DiaryPoster() : InternetPoster(QString("www.diary.ru"), 80)
{
    timer = new QTimer();
    timer->setSingleShot(true);
    connect(timer, SIGNAL(timeout()), this, SLOT(sidIntervalExpired()));
}

void DiaryPoster::test()
{
    qDebug() << "DiaryPosterTest" << endl;
}

QString DiaryPoster::getAuthRequestString()
{
    return QString("GET www.diary.ru/api/?method=user.auth")
            + "&username=" + user
            + "&password=" + encryptedPassword()
            + "&appkey=" + appkey;
}

QString DiaryPoster::getPostRequestString(const Quote &quote)
{
    return QString("POST www.diary.ru/api/?method=post.create")
            + "&sid=" + sid
            + "&message=" + quote.getText();
}

void DiaryPoster::parseResponse(const QString &response)
{
    QString resp = response.remove(0,1).chop(1); //remove { and }
    QStringList pairs = resp.split(',');
    foreach (pair, pairs)
    {
        parsedResponse.insert(pair.section(':', 0,0), pair.section(':',1,1));
    }
}

bool DiaryPoster::requestSuccessful(QString &errortext)
{
    if (parsedResponse.value("\"result\"") == "\"0\"")
        return true;
    else
    {
        errortext = parsedResponse.value("\"error\"");
        return false;
    }
}

void DiaryPoster::processAuthResponse()
{
    sid = parsedResponse.value("\"sid\"");
    sid = sid.remove(0,1).chop(1);
    timer->start(1200000);
}

void DiaryPoster::processPostResponse()
{
    timer->setInterval(1200000);
}

void DiaryPoster::sidIntervalExpired()
{
    setAuthenticated(false);
}

QString DiaryPoster::encryptedPassword()
{
    return QString();
}

Q_EXPORT_PLUGIN2(p_diaryposter, DiaryPoster)
