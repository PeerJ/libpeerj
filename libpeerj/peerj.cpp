#include "peerj.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QDebug>

#include <qjson/parser.h>

#define HOST_URL "http://peerj.com/"

#include "entity/article.h"
#include "entity/revision.h"

PeerJ::PeerJ()
{
}

void PeerJ::getManuscriptsOwned(QNetworkAccessManager *nam)
{
    qDebug() << __FUNCTION__;

/*
    connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(onNAMFinished(QNetworkReply *)));// , Qt::UniqueConnection);
    connect(nam, SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError> &)), this, SLOT(onSSLErrors(QNetworkReply*, const QList<QSslError> &)));
*/
    connect(nam->get(QNetworkRequest(QUrl("https://peerj.com/manuscripts/owned.json"))),
        SIGNAL(finished()), this, SLOT(onGetManuscriptsOwned()));
}

void PeerJ::onSSLErrors(QNetworkReply* reply, const QList<QSslError> & errors) {
    qDebug() << __FUNCTION__;
    reply->ignoreSslErrors(errors);
}

void PeerJ::onGetManuscriptsOwned() {
    QNetworkReply * const r = qobject_cast<QNetworkReply*>(sender()); 

    QJson::Parser parser; bool ok;
    QByteArray ba = r->readAll();

    qDebug() << ba;

    QVariant result = parser.parse(ba, &ok);

    Q_FOREACH(QVariant m, result.toList()) {
        // qDebug() << "AAAAAAAA" << m;
        Article *a = new Article();
        a->fromQVariant(m);
        Revision *r = new Revision();
        r->fromQVariant(m);
        qDebug() << "IIIIIIII" << a->toQVariant();
        qDebug() << "EEEEEEEE" << r->toQVariant();
    }

    r->deleteLater();
}

void PeerJ::onNAMFinished(QNetworkReply *r)
{
    r->deleteLater();
}
