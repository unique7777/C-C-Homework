#include "maindlg.h"
#include "ui_maindlg.h"
#include <QCloseEvent>

MainDlg::MainDlg(QString UserName,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDlg)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);//设置窗口属性

    ui->label->setText(UserName+QString::fromUtf8(",欢迎你"));
}

MainDlg::~MainDlg()
{
    delete ui;
}
void MainDlg::closeEvent(QCloseEvent * event)
{
    /*
    hide();

    event->ignore();
    */
    exit(0);
}
