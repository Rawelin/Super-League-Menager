#include "options.h"
#include "ui_options.h"

Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowTitleHint);
    this->showFullScreen();

    QPalette palette;
    palette.setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Stadiony/lechia.jpg")))));
    setPalette(palette);

    ui->mainmenu->setStyleSheet("background-color: rgba(0, 127, 255, 70);");
    ui->edit->setStyleSheet("background-color: rgba(0, 127, 255, 70);");
    ui->settings->setStyleSheet("background-color: rgba(0, 127, 255, 70);");
}

Options::~Options()
{
    delete ui;
}

void Options::on_mainmenu_clicked()
{
    MainMenu mainmenu;
    Options::close();
    mainmenu.exec();
}

void Options::on_edit_clicked()
{
    Edit edit;
    Options::close();
    edit.exec();
}
