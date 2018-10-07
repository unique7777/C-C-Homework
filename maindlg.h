#ifndef MAINDLG_H
#define MAINDLG_H

#include <QDialog>

namespace Ui {
    class MainDlg;
}

class MainDlg : public QDialog
{
    Q_OBJECT

public:
    explicit MainDlg(QString,QWidget *parent = 0);
    ~MainDlg();

private:
    Ui::MainDlg *ui;
protected:
    virtual void closeEvent ( QCloseEvent * event) ;
};

#endif // MAINDLG_H
