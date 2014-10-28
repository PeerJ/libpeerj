#include "article.h"
#include "revision.h"
#include "file.h"

Article::Article(QObject *parent) :
    Entity(parent)
{
    qRegisterMetaType< Revision* >();
    qRegisterMetaType< QList<Revision*> >();
    m_versionNumber = 0;
}

QVariant Article::toQVariant(QStringList ignoredProperties) {
    qDebug() << "HERE?";
    ignoredProperties.append("revisions");
    QVariantMap v = QJson::QObjectHelper::qobject2qvariant(this, ignoredProperties ); 
    QVariantList revisions;
    qDebug() << "OR HERE?";
    Q_FOREACH(Revision* r, m_revisions) {
        revisions.append(r->toQVariant());
    }
    v["revisions"] = revisions;
    qDebug() << "MAYBE HERE?";
    return v;
}

bool Article::fromQVariant(QVariant v)
{
    QJson::QObjectHelper::qvariant2qobject(v.toMap(), this);
    /*
    Q_FOREACH(QVariant fv, v.toMap()["files"].toList()) {
        File *f = new File();
        f->fromQVariant(fv);
    }
    */
    Q_FOREACH(QVariant m, v.toMap()["revisions"].toList()) {
        Revision *r = new Revision();
        r->fromQVariant(m);
        r->setArticle(this);
    }

    return true;
}

void Article::toSettings(QSettings *s, QStringList ignoredProperties)
{
    ignoredProperties.append("revisions");
    Entity::toSettings(s, ignoredProperties);
    s->beginGroup(configId());
    Q_FOREACH(Revision *r, m_revisions) {
        s->beginGroup("revisions");
        r->toSettings(s);
        s->endGroup();
    }
    s->endGroup();
}

void Article::fromSettings(QSettings *s, QString cID)
{
    Entity::fromSettings(s, cID);
    if (cID.length() > 0)
        s->beginGroup(cID);
    s->beginGroup("revisions");
    Q_FOREACH(QString rs, s->childGroups()) {
        Revision *r = new Revision();
        r->fromSettings(s, rs);
        r->setArticle(this);
    }
    s->endGroup();
    if (cID.length() > 0)
        s->endGroup();
}


