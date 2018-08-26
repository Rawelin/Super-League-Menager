#include "edit.h"
#include "ui_edit.h"

Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowTitleHint);
    this->showFullScreen();

    palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Stadiony/lech.jpg")))));
    setPalette(*palette);

    ui->add->setStyleSheet("background-color: rgba(0, 127, 255, 170);");
    ui->remove->setStyleSheet("background-color: rgba(0, 127, 255, 170);");
    ui->edit->setStyleSheet("background-color: rgba(0, 127, 255, 170);");
    ui->option->setStyleSheet("background-color: rgba(0, 127, 255, 170);");
}

Edit::~Edit()
{
    delete ui;
    delete palette;
}

void Edit::on_option_clicked()
{
    Options options;
    Edit::close();
    options.exec();
}

void Edit::on_add_clicked()
{
    EditChooseTeam editchoseteam(0, 1);
    Edit::close();
    editchoseteam.exec();
}

void Edit::on_remove_clicked()
{
    EditChooseTeam editchoseteam(0, 2);
    Edit::close();
    editchoseteam.exec();
}

void Edit::on_edit_clicked()
{
    EditChooseTeam editchoseteam(0, 3);
    Edit::close();
    editchoseteam.exec();
}
