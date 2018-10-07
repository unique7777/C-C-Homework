#include <QtGui/QApplication>
#include "logindialog.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));

    QApplication a(argc, argv);
    LoginDialog w;
    w.show();

    return a.exec();
}
