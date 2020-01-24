#include "treeviewtest.h"
#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    TreeViewTest w;
    w.show();


    return a.exec();
}
