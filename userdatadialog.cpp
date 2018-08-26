#include "userdatadialog.h"
#include "ui_userdatadialog.h"

extern Container *container;

UserDataDialog::UserDataDialog(QDialog *parent) :
    choseteam(parent),
    ui(new Ui::UserDataDialog)
{
    ui->setupUi(this);
    //this->showFullScreen();
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowOpacity(0.9);
    setGraphic();

}

UserDataDialog::~UserDataDialog()
{
    delete ui;
}

void UserDataDialog::setGraphic()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Background/back2.jpg")))));
    setPalette(palette);

    ui->play->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->teamchoice->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    ui->frame->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->dataLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->nameLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->nameLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->surnameLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->ageLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->natLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->name->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->age->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->nationality->setStyleSheet("background-color: rgba(255, 255, 255, 50);");

    int id = container->userData->getId();
    container->functions->setIcon(container->teams[id].getLogo(), ui->logo, 100, 100);

}

void UserDataDialog::on_play_clicked()
{

    container->userData->setFname(ui->name->text());
    container->userData->setLname(ui->surname->text());
    container->userData->setAge(ui->age->text().toInt());
    container->userData->setNationality(ui->nationality->currentText());

    if(ui->name->text().isEmpty())
       container->userData->setFname("Marian");

    if(ui->surname->text().isEmpty())
       container->userData->setLname("Koniuszko");

   // ContextMenu contextmenu(0, "Zatwierdzono");
   // contextmenu.exec();


    choseteam->close();
    GameDialog gamedialog;
    UserDataDialog::close();

    gamedialog.exec();
}



void UserDataDialog::on_teamchoice_clicked()
{
    UserDataDialog::close();
}
