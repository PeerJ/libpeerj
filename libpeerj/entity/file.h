#ifndef FILE_H
#define FILE_H

#include <QObject>
#include <QStringList>
#include <QList>
#include <QMetaType>

#include "revision.h"
#include "util.h"
#include "entity.h"


class PEERJSHARED_EXPORT File : public Entity
{
    Q_OBJECT

    Q_PROPERTY(QString  name     READ getName     WRITE setName)
    Q_PROPERTY(QString  filename READ getFileName WRITE setFileName)
    Q_PROPERTY(QString  type     READ getType     WRITE setType)
    Q_PROPERTY(QString  sha1     READ getSha1     WRITE setSha1)
    Q_PROPERTY(QString  url      READ getUrl      WRITE setUrl)

    Q_PROPERTY(int      size     READ getSize     WRITE setSize)    // WARNING @todo @why 32bit int .. Qt?

    Q_PROPERTY(Revision* revision READ getRevision WRITE setRevision)


    DEFINE_ACCESSORS(QString, name, Name)
    DEFINE_ACCESSORS(QString, filename, FileName)

    DEFINE_ACCESSORS(QString, type, Type)
    DEFINE_ACCESSORS(QString, sha1, Sha1)
    DEFINE_ACCESSORS(QString,  url,  Url)

    DEFINE_ACCESSORS(int,     size, Size)
    
private:
    Revision *m_revision;

public:
    explicit File(QObject *parent = 0);

    inline Revision *getRevision() { return m_revision; }
    inline void setRevision(Revision* revision) { m_revision = revision; m_revision->addFile(this); }


    QVariant toQVariant(QStringList ignoredProperties = QStringList(QString(QLatin1String("objectName"))));
    bool fromQVariant(QVariant v);
    void toSettings(QSettings *s, QStringList ignoredProperties=(QStringList()<<"objectName"<<"revision"));

signals:

public slots:

};

Q_DECLARE_METATYPE(File*)
Q_DECLARE_METATYPE(QList<File*>)

#endif // FILE_H
