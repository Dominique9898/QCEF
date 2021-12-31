#include "wwlocalregister.h"
#include <QApplication>
#include <cef_app.h>
#include "include/cef_app.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WWLOCALREGISTER w;
    w.show();
    return a.exec();
}
