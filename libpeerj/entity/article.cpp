#include "article.h"
#include "revision.h"

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
    return true;
}

