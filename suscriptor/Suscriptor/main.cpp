#include "suscriptor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Suscriptor w;
    w.show();
    return a.exec();
}
