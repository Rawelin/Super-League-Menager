#include "options.h"
#include "ui_options.h"

extern Container* container;

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowTitleHint);
    this->showFullScreen();

    ui->stackedWidget->insertWidget(1, &edit);

    connect(&edit, SIGNAL(dialogClicked()), this, SLOT(bakToMainMenu()));

    QPalette palette;
    palette.setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Stadiony/lechia.jpg")))));
    setPalette(palette);

    //ui->mainmenu->setStyleSheet("background-color: rgba(0, 127, 255, 70);");
    ui->edit->setStyleSheet("background-color: rgba(0, 127, 255, 30);");
    ui->settings->setStyleSheet("background-color: rgba(0, 127, 255, 30);");


}

Options::~Options()
{
    delete ui;
}

void Options::on_mainmenu_clicked()
{
    emit dialogClicked();
}

void Options::on_edit_clicked()
{
    QPixmap bkgnd("Background/narodowy.jpg");
    container->functions->setBackground(this, bkgnd);
    ui->stackedWidget->setCurrentIndex(1);
}

void Options::bakToMainMenu()
{
     ui->stackedWidget->setCurrentIndex(0);

    QPixmap bkgnd("Stadiony/narodowy.jpg");
    container->functions->setBackground(this, bkgnd);
}

