#ifndef ARTICLE_H
#define ARTICLE_H

#include <QObject>


/**
 * @todo[qdot, LOW] Doctrine2Qt could be a nice utility to develop.
 *
 */

class Article : public QObject
{
    Q_OBJECT

private:

public:
    explicit Article(QObject *parent = 0);

signals:

public slots:

};

#endif // REVISION_H
