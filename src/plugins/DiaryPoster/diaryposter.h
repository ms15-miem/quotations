#ifndef DIARYPOSTER_H
#define DIARYPOSTER_H

#include "../posting/InternetPoster/internetposter.h"
#include "../app/ISecureQuotePoster.h"
#include <QString>

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

    void processAuthResponse(QString &response);
    void processPostResponse(QString &response);

protected slots:
    void sidIntervalExpired();

private:
    QString sid;
    QString appkey;
    //here public key
    //here private key
    QString encryptedPassword();
};

#endif // DIARYPOSTER_H
