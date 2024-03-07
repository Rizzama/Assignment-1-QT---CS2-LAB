#include "welcomewindow.h"
#include "loginwindow.h"
#include "ui_welcomewindow.h"

WelcomeWindow::WelcomeWindow(QString username, int age, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QString age_str = QString::number(age);
    ui->Hello_label->setText("Hello " + username + " " + age_str);
    QPixmap pix ("D:\\AUC-CPP\\QT\\CinemaProject\\RJ-Feature- HighHolidaysFilms.jpg");
    int w = ui->WelcomePic_label->width();
    int h = ui->WelcomePic_label->height();
    ui->WelcomePic_label->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_Signout_Button_clicked()
{
    hide();
    LoginWindow *loginWindow = new LoginWindow(this);
    loginWindow->show();
}

