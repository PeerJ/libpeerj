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

private:
    bool m_save;

public:
    PeerJ();
    void getManuscriptsOwned(QNetworkAccessManager *nam, bool save=true);


public slots:
    void onGetManuscriptsOwned();
    void onSSLErrors(QNetworkReply* r, const QList<QSslError> & errors);
    void onNAMFinished(QNetworkReply *r);
};

#endif // PEERJ_H
