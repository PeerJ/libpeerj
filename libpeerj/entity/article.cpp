#include "article.h"
#include "revision.h"
#include "file.h"

Article::Article(QObject *parent) :
    QObject(parent)
{
    qRegisterMetaType< Revision* >();
    qRegisterMetaType< QList<Revision*> >();
}

QVariant Article::toQVariant(QStringList ignoredProperties) {       
    ignoredProperties.append("revisions");
    QVariantMap v = QJson::QObjectHelper::qobject2qvariant(this, ignoredProperties ); 
    QVariantList revisions;
    Q_FOREACH(Revision* r, m_revisions) {
        revisions.append(r->toQVariant());
    }
    v["revisions"] = revisions;
    return v;
}

bool Article::fromQVariant(QVariant v)
{
    QJson::QObjectHelper::qvariant2qobject(v.toMap(), this);

    Q_FOREACH(QVariant fv, v.toMap()["files"].toList()) {
        File *f = new File();
        f->fromQVariant(fv);
    }
//    Q_FOREACH(QVariant m, v.toMap()["revisions
    return true;
}

