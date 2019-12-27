#include "topscorer.h"
#include "ui_topscorer.h"
#include <QDebug>
#include <algorithm>

extern Container *container;

TopScorer::TopScorer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TopScorer)
{
    ui->setupUi(this);
    this->showFullScreen();
    setWindowFlags(Qt::FramelessWindowHint);

    setGraphic();
    table();
}

TopScorer::~TopScorer()
{
    delete ui;
}

void TopScorer::setGraphic()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Background/back2.jpg")))));
    setPalette(palette);

    ui->tableWidget->setFrameShape(QFrame::NoFrame);

    ui->stats->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    setStyleSheet("QTableWidget {background-color: transparent;}"
                  "QTableWidget {color: rgb(255, 255, 255);}"
                  "QTableWidget {selection-background-color: rgb(0, 255, 0, 50);}"
                  "QHeaderView::section {background-color: transparent;}"
                  "QHeaderView {background-color: transparent;}"
                  "QTableCornerButton::section {background-color: transparent;}"
                  "QHeaderView { font-size: 14pt; }");

    ui->tableWidget->horizontalHeader()->setStyleSheet("color: green");
    ui->tableWidget->verticalHeader()->setStyleSheet("color: green");
    ui->stats->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
}

void TopScorer::table()
{
    QVector<Player>top_scorer;
    for(int j = 0; j < container->teams.size(); j++)    //   16
    {
        for(int i = 0; i < container->teams[j].getPlayer().size(); ++i)
        {
            top_scorer.push_back(container->teams[j].getPlayer()[i]);
        }
    }

    //qSort(top_scorer.begin(), top_scorer.end(), [](const Player &p1, const Player &p2)
    //                                              {return p1.getPosition() > p2.getPosition();});

    //std::random_shuffle(top_scorer.begin(), top_scorer.end());

    int count = std::count_if(top_scorer.begin(), top_scorer.end(), findeScorer);

   /* int count = std::count_if(top_scorer.begin(), top_scorer.end(), [](const Player &p)
                                                                        {if(p.getGoals() > 0)
                                                                            return p.getGoals();
                                                                         else
                                                                            return 0;});*/

    qSort(top_scorer.begin(), top_scorer.end(), [](const Player &p1, const Player &p2)
                                                  {return p1.getGoals() > p2.getGoals();});

    if(count >= 10)
        count = 10;

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setColumnWidth(0, 60);
    ui->tableWidget->setColumnWidth(1, 200);
    ui->tableWidget->setColumnWidth(2, 250);
    ui->tableWidget->setColumnWidth(3, 150);
    ui->tableWidget->setColumnWidth(4, 70);

    int fila;
    int index;
    QStringList tytuly;

    tytuly << "POS" << "IMIE" << "NAZWISKO" << "DRUZYNA" << "GOLE";
    ui->tableWidget->setHorizontalHeaderLabels(tytuly);

    ui->tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeaderItem(1)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeaderItem(2)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeaderItem(3)->setTextAlignment(Qt::AlignLeft);

    for(int i = 0, j = 0; i < count; ++i, ++j)
    {
        index = matcher(top_scorer[i]);
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        fila = ui->tableWidget->rowCount() - 1;

        ui->tableWidget->setItem(fila, POSITION, new QTableWidgetItem(top_scorer[i].getPosition()));
        ui->tableWidget->setItem(fila, NAME, new QTableWidgetItem(top_scorer[i].getFname()));
        ui->tableWidget->setItem(fila, SURNAME, new QTableWidgetItem(top_scorer[i].getLname()));
        ui->tableWidget->setItem(fila, TEAM, new QTableWidgetItem(container->teams[index].getShortName()));
        ui->tableWidget->setItem(fila, GOALS, new QTableWidgetItem(QString::number(top_scorer[i].getGoals())));

        container->functions->delay(100);

            for(int i = 4; i < 5; ++i)
            {
                ui->tableWidget->item(j, i)->setTextAlignment(Qt::AlignCenter);
            }
    }
}

int TopScorer::matcher(const Player &player)
{
    int size = container->teams.size();
    int index;

    for(int i = 0; i < size; ++i)
    {
        if(player.getId() == container->teams[i].getTeamId())
        {
            index = player.getId();
        }
    }
    return index;
}

void TopScorer::on_stats_clicked()
{
    TopScorer::close();
}

int findeScorer(const Player &p)
{
    if(p.getGoals() > 0)
        return p.getGoals();
     else
        return 0;
}
