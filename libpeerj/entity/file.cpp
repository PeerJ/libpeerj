#include "file.h"

#include <QVariant>
#include "qjson/qobjecthelper.h"

File::File(QObject *parent) :
    QObject(parent)
{
}

bool File::fromQVariant(QVariant v)
{
    QJson::QObjectHelper::qvariant2qobject(v.toMap(), this);
    return true;
}

