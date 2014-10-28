#include <QCoreApplication>

#include "entity/article.h"
#include "entity/revision.h"

#include "peerj.h"

#include <qjson/serializer.h>
#include <qjson/qobjecthelper.h>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QSettings>
#include <QUrl>
#include <QNetworkCookieJar>
#include <QNetworkCookie>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /*
    Article art;
    art.setTitle("Wow!");

    Revision r1; 
    r1.setRevisionNumber(0);
    r1.setVersionNumber(3);
    r1.setTitle("Adherence to an overweight and obesity treatment: how to motivate a patient?");
    r1.setArticle(&art);


    QJson::Serializer  serializer;
    qDebug() << serializer.serialize(art.toQVariant());
    */

    PeerJ pj;
    QNetworkAccessManager nam; // = new QNetworkAccessManager();
    nam.cookieJar()->setCookiesFromUrl(
                QNetworkCookie::parseCookies(QByteArray::fromBase64(QSettings("PeerJ").value("cookie").toByteArray())),
                QUrl("https://peerj.com/manuscripts/")
                );

    pj.getManuscriptsFiles(&nam);
    //pj.getFromSettings();

    /*
    // Article art;
    QSettings s("PeerJ");
    s.beginGroup("Article");

    Q_FOREACH(Article* art, Entity::fromSettings<Article>(&s)) {
        // qDebug() << art->toQVariant();
    }
    */
    return a.exec();
}
