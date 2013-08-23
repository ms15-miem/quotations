#ifndef DIARYPOSTER_H
#define DIARYPOSTER_H

#include "../InternetPoster/internetposter.h"
#include "../app/ISecureQuotePoster.h"
#include <QString>
#include <QMap>
#include <QTimer>

class DiaryPoster : public InternetPoster
{
    Q_OBJECT
    Q_INTERFACES(ISecureQuotePoster)

public:
    DiaryPoster();
    void test();

protected:
    QString getAuthRequestString();
    QString getPostRequestString(Quote &quote);

    void parseResponse(const QString &response);

    bool requestSuccessful(QString &errortext);
    void processAuthResponse();
    void processPostResponse();

protected slots:
    void sidIntervalExpired();

private:
    QString sid;
    QTimer *timer;
    const QString appkey = "";
    //here public key
    //here private key
    QString encryptedPassword();
    QMap parsedResponse;
};

#endif // DIARYPOSTER_H
