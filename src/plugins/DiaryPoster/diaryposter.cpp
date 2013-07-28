#include "diaryposter.h"
#include <QDebug>

DiaryPoster::DiaryPoster() : InternetPoster(QString("www.diary.ru"), 80)
{
}

void DiaryPoster::test()
{
    qDebug() << "DiaryPosterTest" << endl;
}

QString DiaryPoster::getAuthRequestString()
{
    return QString();
}

QString DiaryPoster::getPostRequestString(Quote &quote)
{
    return QString();
}

void DiaryPoster::processAuthResponse(QString &response)
{}

void DiaryPoster::processPostResponse(QString &response)
{}

void DiaryPoster::sidIntervalExpired()
{
    setAuthenticated(false);
}

QString DiaryPoster::encryptedPassword()
{
    return QString();
}

Q_EXPORT_PLUGIN2(p_diaryposter, DiaryPoster)
