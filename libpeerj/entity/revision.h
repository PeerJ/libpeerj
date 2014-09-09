#ifndef REVISION_H
#define REVISION_H

#include <QObject>



#include "article.h"



#include <QMetaType>
/**
 * @todo[qdot, LOW] Doctrine2Qt could be a nice utility to develop.
 *
 */


class File;
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
class Revision : public Entity
{
    Q_OBJECT
    Q_PROPERTY (int     revisionNumber READ getRevisionNumber WRITE setRevisionNumber)
    Q_PROPERTY (int     versionNumber  READ getVersionNumber  WRITE setVersionNumber )

    Q_PROPERTY (QString title          READ getTitle          WRITE setTitle         )
    Q_PROPERTY (Article* article READ getArticle WRITE setArticle) 

    Q_PROPERTY (QList<File*>     files READ getFiles WRITE setFiles)

private:
    int     m_revisionNumber;
    int     m_versionNumber;
    QString m_title;

    Article *m_article; 
    QList<File*> m_files;


public:
    explicit Revision(QObject *parent = 0);

    inline int  getRevisionNumber()                         { return m_revisionNumber;           }
    inline void setRevisionNumber(const int revisionNumber) { m_revisionNumber = revisionNumber; }

    inline int  getVersionNumber()                          { return m_versionNumber;            }
    inline void setVersionNumber(const int versionNumber)   { m_versionNumber = versionNumber;   }

    inline QString getTitle()                               { return m_title;                    }
    inline void    setTitle(const QString title)            { m_title = title;                   }

    inline Article *getArticle() { return m_article; }
    inline void setArticle(Article* article) { m_article = article; m_article->addRevision(this); }

    inline QList<File*> getFiles() { return m_files; }
    inline void setFiles(const QList<File*> files) { m_files = files; }

    inline void addFile(File* file)       { m_files.append(file); }

    QVariant toQVariant(QStringList ignoredProperties = QStringList(QString(QLatin1String("objectName"))));
    bool fromQVariant(QVariant v);

    void toSettings(QSettings *s, QStringList ignoredProperties=(QStringList()<<"objectName"<<"article"));
    void fromSettings(QSettings *s, QString cID=QString());


signals:

public slots:

};

Q_DECLARE_METATYPE(Revision*)
Q_DECLARE_METATYPE(QList<Revision*>)

#endif // REVISION_H
