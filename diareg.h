#ifndef DIAREG_H
#define DIAREG_H

#include <QDialog>

namespace Ui {
    class DiaReg;
}

struct UserInfo
{
    char name[30];
    char pass[33];
    char sex[5];
    char degree[7];
    char fav[50];//用空白隔开,兴趣1 兴趣2 ....
    char birth[12];
};

class DiaReg : public QDialog
{
    Q_OBJECT

public:
    explicit DiaReg(QWidget *parent = 0);
    ~DiaReg();

private:
    Ui::DiaReg *ui;

private slots:
    void on_pbtReg_clicked();
};

#endif // DIAREG_H
