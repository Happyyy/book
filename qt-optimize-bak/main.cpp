#include <QtGui>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Main w;
           // w.setAutoFillBackground(true);
           // w.setStyleSheet("Main{border-image:url(:/home/test/Downlods/bg.png);}");
           // QPalette palette;
           // QPixmap pixmap(":/home/Downloads/bg.png");
    w.setWindowFlags(Qt::FramelessWindowHint);//去标题栏
           // palette.setBrush(QPalette::Window, QBrush(pixmap));
           // w.setPalette(palette);
    w.showMaximized();

    return a.exec();
}
