#include "publicador.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Publicador w;
    w.show();
    return a.exec();
}
