#include "registerwindow.h"
#include "Users.h"
#include "ui_registerwindow.h"
#include "welcomewindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->Password_Error_label_reg->setVisible(false);
    ui->PasswordRetype_Error_label_reg->setVisible(false);
    ui->Age_Error_label_reg->setVisible(false);
    ui->Username_Error_label_reg->setVisible(false);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_Register_pushButton_reg_clicked()
{
    QString Username = ui->Username_lineEdit_reg->text();
    QString Password;
    if(ui->Password_lineEdit_reg->text() == ui->PasswordRetype_lineEdit_reg->text()){
        Password = ui->Password_lineEdit_reg->text();
    } else{
        ui->Password_Error_label_reg->setVisible(true);
        ui->PasswordRetype_Error_label_reg->setVisible(true);
    }
    QString DOB = ui->Month_comboBox_reg->currentText() + "/" + ui->Day_comboBox_reg->currentText() + "/" + ui->Year_comboBox_reg->currentText();
    int age = 2024 - ui->Year_comboBox_reg->currentText().toInt();
    if(age <= 12){
        ui->Age_Error_label_reg->setVisible(true);
    }
    QString Gender;
    if(ui->Male_radioButton_reg->isChecked()){
       Gender = "Male";
    } else{
        Gender = "Female";
    }
    QString UserType;
    if(ui->User_radioButton_reg->isChecked()){
        UserType = "User";
    } else{
        UserType = "Admin";
    }
    int index = 0;
    for(int i = 0; i < usernames->size(); i++){
        if(usernames[i] != ""){
            index++;
        }
    }

    usernames[index + 1] = Username;
    passwords[index + 1] = Password;
    ages[index + 1] = age;
    WelcomeWindow *welcome = new WelcomeWindow(Username, age, this);
    welcome->show();
}

