#include <QCoreApplication>

#include "entity/article.h"
#include "entity/revision.h"

#include <qjson/serializer.h>
#include <qjson/qobjecthelper.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    Article art;
    art.setTitle("Wow!");

    Revision r1; 
    r1.setRevisionNumber(0);
    r1.setVersionNumber(3);
    r1.setTitle("Adherence to an overweight and obesity treatment: how to motivate a patient?");
    r1.setArticle(&art);


    QJson::Serializer  serializer;
    qDebug() << serializer.serialize(art.toQVariant());

    return a.exec();
}
