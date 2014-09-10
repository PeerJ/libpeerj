#ifndef ARTICLE_H
#define ARTICLE_H

#include <QObject>
#include <QList>
#include <QMetaType>
#include <qjson/qobjecthelper.h>

#include <QDebug>

#include "../peerj_global.h"

#include "entity.h"

class Revision;

/**
 * @todo[qdot, LOW] Doctrine2Qt could be a nice utility to develop.
 *
 */

/**
 * Each article has multiple revisions.
 * The current revision of each article is set as the article's "revision" prope
rty.
 * Each revision has an article property, for the inverse relationship.
 *
 * @ORM\HasLifecycleCallbacks
 * @ORM\Table(name="article_revision", indexes={
 * @ORM\Index(name="preprint", columns={"preprint"}),
 * @ORM\Index(name="status", columns={"status"})
 * })
 * @ORM\Entity(repositoryClass="peerj\ApiBundle\Repository\ArticleRepository")
 * @Gedmo\Loggable
 */
class PEERJSHARED_EXPORT Article : public Entity
{
    Q_OBJECT
    Q_PROPERTY (int     versionNumber  READ getVersionNumber  WRITE setVersionNumber )

    Q_PROPERTY (QString title          READ getTitle          WRITE setTitle         )
    Q_PROPERTY (QList<Revision*> revisions READ getRevisions WRITE setRevisions) 


private:
    int     m_versionNumber;
    QString m_title;
    QList<Revision*> m_revisions;

public:
    explicit Article(QObject *parent = 0);

    inline int  getVersionNumber()                          { return m_versionNumber;            }
    inline void setVersionNumber(const int versionNumber)   { m_versionNumber = versionNumber;   }

    inline QString getTitle()                               { return m_title;                    }
    inline void    setTitle(const QString title)            { m_title = title;    }

    inline QList<Revision*> getRevisions() { return m_revisions; } 
    inline void setRevisions(const QList<Revision*> revisions) { m_revisions = revisions; } 

    inline void addRevision(Revision* revision)       { m_revisions.append(revision); }

    QVariant toQVariant(QStringList ignoredProperties = QStringList(QString(QLatin1String("objectName"))));
    bool fromQVariant(QVariant v);

    void toSettings(QSettings *s, QStringList ignoredProperties=QStringList(QString("objectName")));
    void fromSettings(QSettings *s, QString cID=QString());

    //QList<Article*> getFromSettings(QSettings *a);

signals:

public slots:

};

Q_DECLARE_METATYPE(Article*)
Q_DECLARE_METATYPE(QList<Article*>)

#endif // ARTICLE_H
