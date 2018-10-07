#include "diareg.h"
#include "ui_diareg.h"
#include <QLineEdit>
#include <QMessageBox>
#include <string.h>
#include "md5.h"
#include <QFile>

DiaReg::DiaReg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DiaReg)
{
    ui->setupUi(this);

    ui->LEUserName->setMaxLength(30);
    ui->LEPassWD1->setEchoMode(QLineEdit::Password);

    ui->cbDegree->addItem("本科");
    ui->cbDegree->addItem("硕士");
    ui->cbDegree->addItem("博士");

    ui->rbMan->setChecked(true);
    ui->cbDegree->setCurrentIndex(3);
}

DiaReg::~DiaReg()
{
    delete ui;
}

void DiaReg::on_pbtReg_clicked()//注册
{
    UserInfo UInfo;

    QString userName = ui->LEUserName->text();//获取用户名

    userName = userName.trimmed();//去除字符串开头和结尾的空白
    if(userName.length() == 0)//用户名为空
    {
        QMessageBox::critical(this,"温馨提示","用户名不能为空");
        ui->LEUserName->setFocus();
        return;
    }

    char user[30];
    strcpy(user,userName.toUtf8().data());
    if(strchr(user,'\r') || strchr(user,' ') || strchr(user,'#'))
    {
        QMessageBox::critical(this,"温馨提示","用户名不能含有空格，#，等非法字符");
        ui->LEUserName->clear();
        ui->LEUserName->setFocus();
        return;
    }

    QString pass = ui->LEPassWD->text();
    if(pass.length() == 0)//密码为空
    {
        QMessageBox::critical(this,"温馨提示","密码不能为空");
        ui->LEPassWD->setFocus();
        return;
    }
    QString pass1 = ui->LEPassWD1->text();
    if(pass1.length() == 0)//确认密码为空
    {
        QMessageBox::critical(this,"温馨提示","确认密码不能为空");
        ui->LEPassWD1->setFocus();
        return;
    }
    if(pass != pass1)
    {
        QMessageBox::critical(this,"温馨提示","两次输入的密码不一致");
        ui->LEPassWD1->clear();
        ui->LEPassWD1->setFocus();
        return ;
    }

    if(pass.length()!=6)
    {
        QMessageBox::critical(this,"温馨提示","密码长度只能为6");
        ui->LEPassWD->setFocus();
        return;
    }

    char sex = '0';
    if(ui->rbWeman->isChecked())//获取性别
    {
        sex = '1';
    }

    QString degree = ui->cbDegree->currentText();//获取学历

    QString fav = " ";//获取兴趣爱好
    if(ui->cbLanQiu->isChecked())
        fav+=" 篮球";
    if(ui->cbFootBall->isChecked())
        fav+=" 足球";
    if(ui->cbPingPang->isChecked())
        fav+=" 乒乓球";
    if(ui->cbMusic->isChecked())
        fav+=" 听音乐";
    if(ui->cbPlay->isChecked())
        fav+=" 玩游戏";
    if(ui->cbYouyong->isChecked())
        fav+=" 游泳";
    fav = fav.trimmed();

    QString birth = ui->DEBirth->date().toString("yyyy-MM-dd");//获取生日

    strcpy(UInfo.birth,birth.toUtf8().data());
    strcpy(UInfo.fav,fav.toUtf8().data());
    strcpy(UInfo.degree,degree.toUtf8().data());
    strcpy(UInfo.sex,sex=='0'?"男":"女");
    strcpy(UInfo.pass,md5_encrypt(pass.toUtf8().data(),pass.length()));//加密
    strcpy(UInfo.name,user);

    qDebug("%s %s %s %s %s %s",UInfo.name,UInfo.pass,UInfo.sex,UInfo.degree,UInfo.fav,UInfo.birth);

    QFile f("UserInfo.txt");
    f.open(QIODevice::ReadOnly);
    UserInfo U;
    int ret = 1;
    while(ret>0)
    {
        ret = f.read((char*)&U,sizeof(U));
        if(strcmp(U.name,UInfo.name) ==0 )
        {
            QMessageBox::critical(this,"温馨提示","用户名已经存在");
            ui->LEUserName->clear();
            ui->LEUserName->setFocus();
            return;
        }
    }
    f.close();

    f.open(QIODevice::Append);
    f.write((const char*)&UInfo,sizeof(UInfo));
    f.close();


    QMessageBox::information(this,"温馨提示","注册成功");
    accept();

}
