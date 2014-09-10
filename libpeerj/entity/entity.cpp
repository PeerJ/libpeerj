#include "entity.h"

#include "qjson/qobjecthelper.h"

#include <QMetaProperty>

Entity::Entity(QObject *parent) :
    QObject(parent)
{
    m_id = 0;
}

void Entity::toSettings(QSettings *s, QStringList ignoredProperties)
{
    if (getId() <=0) return;

    s->beginGroup(configId());
    const QMetaObject *meta = metaObject();

    for (int i = 0; i < meta->propertyCount(); i++)
    {
        QMetaProperty property = meta->property(i);
        // int j = meta->indexOfClassInfo(property.name());
        if (ignoredProperties.contains(property.name()))
            continue;

        s->setValue(property.name(), this->property(property.name()));
    }
    s->endGroup();
}

void Entity::fromSettings(QSettings *s, QString cID)
{
    if (cID.length() > 0)
        s->beginGroup(cID);
    Q_FOREACH(QString name, s->childKeys()) {
        this->setProperty(name.toLatin1().constData(), s->value(name));
    }
    if (cID.length() > 0)
        s->endGroup();
}

QList<Entity *> Entity::fromSettings(QSettings *s)
{
    QList<Entity*> rval;
    Q_FOREACH(QString name, s->childGroups()) {
        Entity* e = new Entity();
        e->fromSettings(s, name);
        rval.append(e);
    }
    return rval;
}

