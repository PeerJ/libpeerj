#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QStringList>

#include "util.h"

class File : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString  name READ getName WRITE setName)
    Q_PROPERTY(QString  sha1 READ getSha1 WRITE setSha1)
    Q_PROPERTY(QString  url  READ getUrl  WRITE setUrl)

    DEFINE_ACCESSORS(QString, name, Name)
    DEFINE_ACCESSORS(QString, sha1, Sha1)
    DEFINE_ACCESSORS(QString,  url,  Url)
    
public:
    explicit File(QObject *parent = 0);

    QVariant toQVariant(QStringList ignoredProperties = QStringList(QString(QLatin1String("objectName"))));
    bool fromQVariant(QVariant v);
    
signals:

public slots:

};

#endif // FILE_H
