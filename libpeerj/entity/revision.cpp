#include "revision.h"
#include "file.h"

Revision::Revision(QObject *parent) :
    Entity(parent)
{
    qRegisterMetaType< File* >();
    qRegisterMetaType< QList<File*> >();
    m_revisionNumber = 0;
    m_versionNumber  = 0;
}

QVariant Revision::toQVariant(QStringList ignoredProperties) {
    ignoredProperties.append("files");
    QVariantMap v = QJson::QObjectHelper::qobject2qvariant(this, ignoredProperties );
    QVariantList files;
    Q_FOREACH(File* r, m_files) {
        files.append(r->toQVariant());
    }
    v["files"] = files;
    return v;}

bool Revision::fromQVariant(QVariant v)
{
    QJson::QObjectHelper::qvariant2qobject(v.toMap(), this);

    Q_FOREACH(QVariant fv, v.toMap()["files"].toList()) {
        File *f = new File();
        f->fromQVariant(fv);
        this->addFile(f);
        qDebug() << f;
    }
//    Q_FOREACH(QVariant m, v.toMap()["revisions
    return true;
}

void Revision::toSettings(QSettings *s, QStringList ignoredProperties)
{
    ignoredProperties << "article" << "files";
    Entity::toSettings(s, ignoredProperties);

    s->beginGroup(configId());
    Q_FOREACH(File *f, m_files) {
        s->beginGroup("files");
        f->toSettings(s);
        s->endGroup();
    }
    s->endGroup();
}

void Revision::fromSettings(QSettings *s, QString cID)
{
    Entity::fromSettings(s, cID);
    if (cID.length() > 0)
        s->beginGroup(cID);
    s->beginGroup("files");
    Q_FOREACH(QString fs, s->childGroups()) {
        File *f = new File();
        f->fromSettings(s, fs);
        f->setRevision(this);
    }
    s->endGroup();
    if (cID.length() > 0)
        s->endGroup();
}

