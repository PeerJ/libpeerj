#include "file.h"

#include <QVariant>
#include "qjson/qobjecthelper.h"

File::File(QObject *parent) :
    Entity(parent)
{
}

QVariant File::toQVariant(QStringList ignoredProperties) {
    return  QJson::QObjectHelper::qobject2qvariant(this, ignoredProperties );
}

bool File::fromQVariant(QVariant v)
{
    QJson::QObjectHelper::qvariant2qobject(v.toMap(), this);
    return true;
}

void File::toSettings(QSettings *s, QStringList ignoredProperties)
{
    Entity::toSettings(s, ignoredProperties);
}

