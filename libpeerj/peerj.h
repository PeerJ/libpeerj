#ifndef PEERJ_H
#define PEERJ_H

#include "peerj_global.h"

#include <QObject>
#include <QSslError>
#include <QList>

class QNetworkAccessManager;
class QNetworkReply;

class PEERJSHARED_EXPORT PeerJ : public QObject
{
Q_OBJECT

public:
    PeerJ();
    void getManuscriptsOwned(QNetworkAccessManager *nam);

public slots:
    void onGetManuscriptsOwned();
    void onSSLErrors(QNetworkReply* r, const QList<QSslError> & errors);
    void onNAMFinished(QNetworkReply *r);
};

#endif // PEERJ_H
