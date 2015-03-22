#include "main_window.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QFile file("/home/nowax/workspaces/qt_workspace/modbook/modbook/resources/levelfour.qss");
//    file.open(QFile::ReadOnly);
//    QString styleSheet = QLatin1String(file.readAll());
    a.setStyle("plastique");
//    a.setStyleSheet(styleSheet);
    main_window w;
    w.show();

    return a.exec();
}
