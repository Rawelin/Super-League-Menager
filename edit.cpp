#include "edit.h"
#include "ui_edit.h"

Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowTitleHint);
    this->showFullScreen();

//    palette = new QPalette();
//    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Stadiony/lech.jpg")))));
//    setPalette(*palette);

    QString style = "background-color: rgba(0, 127, 255, 30);";

    ui->add->setStyleSheet(style);
    ui->remove->setStyleSheet(style);
    ui->edit->setStyleSheet(style);
    ui->option->setStyleSheet(style);

    addPlayer = new EditChooseTeam(0 ,1);
    removePlayer = new EditChooseTeam(0 ,2);
    editPlayer = new EditChooseTeam(0 ,3);

    ui->stackedWidget->insertWidget(1, addPlayer);
    ui->stackedWidget->insertWidget(2, removePlayer);
    ui->stackedWidget->insertWidget(3, editPlayer);

    connect(addPlayer, SIGNAL(dialogClicked()), this, SLOT(bakToMainMenu()));
    connect(removePlayer, SIGNAL(dialogClicked()), this, SLOT(bakToMainMenu()));
    connect(editPlayer, SIGNAL(dialogClicked()), this, SLOT(bakToMainMenu()));

}

Edit::~Edit()
{
    delete ui;
    delete palette;
    delete addPlayer;
    delete removePlayer;
    delete editPlayer;
}

void Edit::on_option_clicked()
{
     emit dialogClicked();
}

void Edit::on_add_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Edit::on_remove_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void Edit::on_edit_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void Edit::bakToMainMenu()
{
    ui->stackedWidget->setCurrentIndex(0);
}
