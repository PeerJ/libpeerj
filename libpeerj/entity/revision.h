#ifndef REVISION_H
#define REVISION_H

#include <QObject>


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
 * @ORM\Entity(repositoryClass="peerj\ApiBundle\Repository\RevisionRepository")
 * @Gedmo\Loggable
 */
class Revision : public QObject
{
    Q_OBJECT
    Q_PROPERTY (int     revisionNumber READ getRevisionNumber WRITE setRevisionNumber)
    Q_PROPERTY (int     versionNumber  READ getVersionNumber  WRITE setVersionNumber )

    Q_PROPERTY (QString title          READ getTitle          WRITE setTitle         )


private:
    int     m_revisionNumber;
    int     m_versionNumber;
    QString m_title;

public:
    explicit Revision(QObject *parent = 0);

    inline int  getRevisionNumber()                         { return m_revisionNumber;           }
    inline void setRevisionNumber(const int revisionNumber) { m_revisionNumber = revisionNumber; }

    inline int  getVersionNumber()                          { return m_versionNumber;            }
    inline void setVersionNumber(const int versionNumber)   { m_versionNumber = versionNumber;   }

    inline QString getTitle()                               { return m_title;                    }
    inline void    setTitle(const QString title)            { m_title = title;                   }

signals:

public slots:

};

#endif // REVISION_H
