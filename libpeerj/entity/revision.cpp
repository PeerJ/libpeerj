#include "revision.h"
#include "file.h"

Revision::Revision(QObject *parent) :
    QObject(parent)
{
}

bool Revision::fromQVariant(QVariant v)
{
    QJson::QObjectHelper::qvariant2qobject(v.toMap(), this);

    Q_FOREACH(QVariant fv, v.toMap()["files"].toList()) {
        File *f = new File();
        f->fromQVariant(fv);
    }
//    Q_FOREACH(QVariant m, v.toMap()["revisions
    return true;
}

