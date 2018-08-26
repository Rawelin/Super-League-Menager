#include "data.h"
#include "ui_data.h"

Data::Data(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Data)
{
    ui->setupUi(this);
    this->showFullScreen();
    setWindowFlags(Qt::FramelessWindowHint);

    setGraphics();
}

Data::~Data()
{
    delete ui;
}

void Data::setGraphics()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Background/back2.jpg")))));
    setPalette(palette);

    ui->back->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->topscorers->setStyleSheet("background-color: rgba(255, 255, 255, 30);");
    ui->stats->setStyleSheet("background-color: rgba(255, 255, 255, 30);");

}

void Data::on_back_clicked()
{
    Data::close();
}

void Data::on_topscorers_clicked()
{
    TopScorer topscorer;
    topscorer.exec();
}

void Data::on_stats_clicked()
{
    Stats stats;
    stats.exec();
}
