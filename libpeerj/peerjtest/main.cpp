#include <QCoreApplication>

#include "entity/article.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    Article art;

    return a.exec();
}
