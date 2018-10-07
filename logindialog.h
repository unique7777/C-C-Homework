#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "maindlg.h"

namespace Ui {
    class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
    MainDlg* dlg;

private:
    Ui::LoginDialog *ui;

private slots:
    void on_pbtReg_clicked();
    void on_pbtLogin_clicked();
protected:
    virtual void closeEvent(QCloseEvent *);

};

#endif // LOGINDIALOG_H
