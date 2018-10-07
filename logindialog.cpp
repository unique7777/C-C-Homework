#include "logindialog.h"
#include "ui_logindialog.h"
#include "maindlg.h"
#include "diareg.h"


LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    dlg = NULL;
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pbtLogin_clicked()//登录
{
    hide();

    dlg = new MainDlg(ui->LEUserName->text());
    dlg->show();

    /*
    MainDlg dlg;
    dlg.exec();
    qDebug("test");
    */
    /*
    MainDlg* dlg = new MainDlg;
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置窗口属性
    dlg->setModal(true);
    dlg->show();
    qDebug("test");
 //   delete dlg;
    */
    /*
    MainDlg* dlg = new MainDlg;
    dlg->setAttribute(Qt::WA_DeleteOnClose);//设置窗口属性
 //   dlg->setModal(true);
    dlg->show();
    qDebug("test");
    */
    /*
    if(dlg == NULL)
    {
        dlg = new MainDlg;
        dlg->show();

    }
    else
    {
        dlg->show();
    }
    */
}

void LoginDialog::closeEvent(QCloseEvent * event)
{
    exit(0);
}

void LoginDialog::on_pbtReg_clicked()//注册
{
    DiaReg d;
    d.exec();
}
