#include "stats.h"
#include "ui_stats.h"

extern Container *container;

Stats::Stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats)
{
    ui->setupUi(this);
    this->showFullScreen();
    setWindowFlags(Qt::FramelessWindowHint);

    setGraphic();
    table();
}

Stats::~Stats()
{
    delete ui;
}

void Stats::setGraphic()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Background/back2.jpg")))));
    setPalette(palette);

    ui->tableWidget->setFrameShape(QFrame::NoFrame);
    ui->tableWidget->setGridStyle(Qt::SolidLine);

    setStyleSheet("QTableWidget {background-color: transparent;}"
                  "QTableWidget {color: rgb(255, 255, 255);}"
                  "QTableWidget {selection-background-color: rgb(0, 255, 0, 50);}"
                  "QHeaderView::section {background-color: transparent;}"
                  "QHeaderView {background-color: transparent;}"
                  "QTableCornerButton::section {background-color: transparent;}"
                  "QHeaderView { font-size: 14pt; }");

    ui->tableWidget->horizontalHeader()->setStyleSheet("color: blue");
    ui->tableWidget->verticalHeader()->setStyleSheet("color: blue");
    ui->back->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
}

void Stats::table()
{
    QList<Team> temp_teams;


    for(int i = 0; i < container->teams.size(); i++)
        temp_teams.push_back(container->teams[i]);

    for(int i = 0; i < temp_teams.size(); ++i)
        temp_teams[i].setStrength(team->teamStrength(temp_teams[i].getPlayer(), temp_teams[i].getFormation()));


    qSort(temp_teams.begin(), temp_teams.end(), [](const Team &t1,  const Team &t2){return t1.getStrength() > t2.getStrength();});

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    int fila;
    QStringList titles;

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setColumnWidth(0,300);
    ui->tableWidget->setColumnWidth(1,50);


    titles << "DRUZYNA" << "SILA";

    ui->tableWidget->setHorizontalHeaderLabels(titles);

    ui->tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeaderItem(1)->setTextAlignment(Qt::AlignLeft);

    for(int i = 0, j = 0; i < temp_teams.size(); ++i, ++j)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        fila = ui->tableWidget->rowCount()-1;

        ui->tableWidget->setItem(fila, TEAM, new QTableWidgetItem(temp_teams[i].getName() + " " + temp_teams[i].getCity()));
        ui->tableWidget->setItem(fila, STRENGTH, new QTableWidgetItem(QString::number(temp_teams[i].getStrength())));

        container->functions->delay(100);

        ui->tableWidget->item(j, 1)->setTextAlignment(Qt::AlignCenter);

    }

}

void Stats::on_pushButton_clicked()
{
    //ui->label->setNum(container->team[0].strength);
    ui->tableWidget->setRowCount(0);
    table();
}

void Stats::on_back_clicked()
{
    Stats::close();
}
