#include "loginwindow.h"
#include "registerwindow.h"
#include "ui_loginwindow.h"
#include "Users.h"
#include "welcomewindow.h"

LoginWindow::LoginWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->Password_Error_label->setVisible(false);
    ui->Name_Error_label->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_Login_Button_clicked()
{
    bool LoginFlag = false;
    int index = 0;
    for (int var = 0; var < usernames->size(); ++var) {
        if(ui->Username_lineEdit->text() == usernames[var] && ui->Passwird_lineEdit->text() == passwords[var]){
            LoginFlag = true;
            index = var;
        }
    }
    if(LoginFlag){
        hide();
        WelcomeWindow * welcomeWindow = new WelcomeWindow(usernames[index], ages[index], this);
        welcomeWindow->show();
    } else{
        ui->Name_Error_label->setVisible(true);
        ui->Password_Error_label->setVisible(true);
    }
}


void LoginWindow::on_Register_Button_clicked()
{
    hide();
    RegisterWindow * registerWindow = new RegisterWindow(this);
    registerWindow->show();
}

