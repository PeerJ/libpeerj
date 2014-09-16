#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QSettings>
#include <QStringList>

class Entity : public QObject
{
    Q_OBJECT
    Q_PROPERTY (int     id READ getId  WRITE setId)

private:
    int m_id;
public:
    explicit Entity(QObject *parent = 0);

    int getId() const { return m_id; }
    void setId(const int id) {
        mapById[metaObject()->className()].insert(id, this);
        m_id = id;
    }

    QString configId() {
        QString objectID;
        //objectID.append(this->metaObject()->className());
        objectID.append(QString::number(getId()));
        return objectID;
    }


    void toSettings(QSettings *s, QStringList ignoredProperties=QStringList(QString("objectName")));
    virtual void fromSettings(QSettings *s, QString cID=QString());

    static QList<Entity*> fromSettings(QSettings *s);

    template <class EDerived>
    static QList<EDerived*> fromSettings(QSettings *s) {
        QList<EDerived*> rval;
        Q_FOREACH(QString name, s->childGroups()) {
            EDerived* e = new EDerived();
            e->fromSettings(s, name);
            rval.append(e);
        }
        return rval;
    }

protected:
    static QMap<const char*, QMap<int, Entity*> > mapById;

signals:

public slots:

};

#endif // ENTITY_H
