#include "table.h"
#include "ui_table.h"
#include <qalgorithms.h>

extern Container *container;

Table::Table(QDialog *parent) :
    gameDialog(parent),
    ui(new Ui::Table)
{
    // setWindowFlags(Qt::WindowTitleHint);
    // setWindowFlags(Qt::WindowStaysOnTopHint);

     ui->setupUi(this);
     this->showFullScreen();
     setWindowFlags(Qt::FramelessWindowHint);
     setGraphic();
     table();
}

Table::~Table()
{
    delete ui;
}

void Table::setGraphic()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Background/back2.jpg")))));
    setPalette(palette);

    ui->tableWidget->setFrameShape(QFrame::NoFrame);
   // ui->tableWidget->setGridStyle(Qt::SolidLine);

    setStyleSheet("QTableWidget {background-color: transparent;}"
                  "QTableWidget {selection-background-color: rgb(255, 255, 255, 0);}"
                  "QHeaderView::section {background-color: rgb(0, 0, 255, 100);}"
                  "QHeaderView {background-color: transparent;}"
                  "QTableCornerButton::section {background-color: rgb(0, 0, 255, 100);}"
                  "QHeaderView { font-size: 14pt; }");

    ui->tableWidget->horizontalHeader()->setStyleSheet("color: white");
    ui->tableWidget->verticalHeader()->setStyleSheet("color: white");
}

void Table::table()
{


   QList<Team> temporaryTeams =  container->teams;
//   qSort(temporaryTeams.begin(), temporaryTeams.end(), [](const Team &t1, const Team &t2)->bool{
//                                       return ((t1.getPoint() > t2.getPoint()) ||
//                                       (t1.getPoint() == t2.getPoint() && t1.getDiffer() > t2.getDiffer()) ||
//                                       (t1.getPoint() == t2.getPoint() && t1.getDiffer() == t2.getDiffer() && t1.getGoalScored() > t2.getGoalScored()));});

   qSort(temporaryTeams.begin(), temporaryTeams.end(), worseTeam);

   ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
   ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
   //qSort(team.begin(), team.end(), worseTeam);
   //QList<int> list = {1 ,5, 7, 3};
   /*qStableSort(list.begin(), list.end(), qLess<int>());
   foreach (int elem,  list)
   {
       qDebug() << elem;
   }*/

   int fila;
   QStringList tytuly;

   ui->tableWidget->setColumnCount(10);
   ui->tableWidget->setColumnWidth(0,300);
   ui->tableWidget->setColumnWidth(1,40);
   ui->tableWidget->setColumnWidth(2,30);
   ui->tableWidget->setColumnWidth(3,30);
   ui->tableWidget->setColumnWidth(4,30);
   ui->tableWidget->setColumnWidth(5,30);
   ui->tableWidget->setColumnWidth(6,15);
   ui->tableWidget->setColumnWidth(7,30);
   ui->tableWidget->setColumnWidth(8,40);
   ui->tableWidget->setColumnWidth(9,40);
  // ui->tableWidget->setColumnWidth(10,40);

   tytuly << "DRUZYNA" << "KOL" <<"Z" << "R" << "P" << "BZ" << "-" << "BS" << "+/-" << "PTS";
   ui->tableWidget->setHorizontalHeaderLabels(tytuly);

   ui->tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
   ui->tableWidget->horizontalHeaderItem(1)->setTextAlignment(Qt::AlignLeft);

  // ui->tableWidget->horizontalHeader()->setStyleSheet("background-color: rgb(0, 255, 0);");

  // ui->tableWidget->horizontalHeader()->setStyleSheet("color: rgb(255, 255, 255);");

   for(int i = 0, j = 0; i < container->teams.size(); ++i, ++j)
   {
       ui->tableWidget->insertRow(ui->tableWidget->rowCount());
       fila = ui->tableWidget->rowCount() - 1;

       ui->tableWidget->setItem(fila, TEAM, new QTableWidgetItem(temporaryTeams[i].getName() + "  " + temporaryTeams[i].getCity()));
       ui->tableWidget->setItem(fila, ROUND, new QTableWidgetItem(QString::number(temporaryTeams[i].getRound())));
       ui->tableWidget->setItem(fila, WIN, new QTableWidgetItem(QString::number(temporaryTeams[i].getWin())));
       ui->tableWidget->setItem(fila, DRAW, new QTableWidgetItem(QString::number(temporaryTeams[i].getDraw())));
       ui->tableWidget->setItem(fila, LOST, new QTableWidgetItem(QString::number(temporaryTeams[i].getLost())));
       ui->tableWidget->setItem(fila, GS, new QTableWidgetItem(QString::number(temporaryTeams[i].getGoalScored())));
       ui->tableWidget->setItem(fila, SEP, new QTableWidgetItem(temporaryTeams[i].getSeparator()));
       ui->tableWidget->setItem(fila, GL, new QTableWidgetItem(QString::number(temporaryTeams[i].getGoalLost())));
       ui->tableWidget->setItem(fila, DIF, new QTableWidgetItem(QString::number(temporaryTeams[i].getDiffer())));
       ui->tableWidget->setItem(fila, POINTS, new QTableWidgetItem(QString::number(temporaryTeams[i].getPoint())));

       container->functions->delay(5);
       for(int i = 1; i < 10; ++i)
       {
           ui->tableWidget->item(j, i)->setTextAlignment(Qt::AlignCenter);
       }
   }

   setLogoAtTable(temporaryTeams);

   for(int i= 0; i < 10; ++i)
   {
        ui->tableWidget->item(0, i)->setBackground(QColor(0, 160, 0, 50));
        ui->tableWidget->item(1, i)->setBackground(QColor(0, 255, 0, 50));
        ui->tableWidget->item(2, i)->setBackground(QColor(0, 255, 0, 50));
        ui->tableWidget->item(14, i)->setBackground(QColor(255, 0, 0, 150));
        ui->tableWidget->item(15, i)->setBackground(QColor(255, 0, 0, 150));

        for(int j = 3; j < 14; j++)
             ui->tableWidget->item(j, i)->setBackgroundColor(QColor(0, 0, 255, 120));
   }
}

void Table::setLogoAtTable(QList<Team> &list)
{
   /* int a, b, c, d, e, f, g, h,
        i, j, k, l, m, n, o, p;

    a = list[0].getTeamId();
    b = list[1].getTeamId();
    c = list[2].getTeamId();
    d = list[3].getTeamId();
    e = list[4].getTeamId();
    f = list[5].getTeamId();
    g = list[6].getTeamId();
    h = list[7].getTeamId();
    i = list[8].getTeamId();
    j = list[9].getTeamId();
    k = list[10].getTeamId();
    l = list[11].getTeamId();
    m = list[12].getTeamId();
    n = list[13].getTeamId();
    o = list[14].getTeamId();
    p = list[15].getTeamId();

    container->functions->setIcon(container->teams[a].getLogo(),ui->t1, 30, 30, 20);
    container->functions->setIcon(container->teams[b].getLogo(),ui->t2, 30, 30, 20);
    container->functions->setIcon(container->teams[c].getLogo(),ui->t3, 30, 30, 20);
    container->functions->setIcon(container->teams[d].getLogo(),ui->t4, 30, 30, 20);
    container->functions->setIcon(container->teams[e].getLogo(),ui->t5, 30, 30, 20);
    container->functions->setIcon(container->teams[f].getLogo(),ui->t6, 30, 30, 20);
    container->functions->setIcon(container->teams[g].getLogo(),ui->t7, 30, 30, 20);
    container->functions->setIcon(container->teams[h].getLogo(),ui->t8, 30, 30, 20);
    container->functions->setIcon(container->teams[i].getLogo(),ui->t9, 30, 30, 20);
    container->functions->setIcon(container->teams[j].getLogo(),ui->t10, 30, 30, 20);
    container->functions->setIcon(container->teams[k].getLogo(),ui->t11, 30, 30, 20);
    container->functions->setIcon(container->teams[l].getLogo(),ui->t12, 30, 30, 20);
    container->functions->setIcon(container->teams[m].getLogo(),ui->t13, 30, 30, 20);
    container->functions->setIcon(container->teams[n].getLogo(),ui->t14, 30, 30, 20);
    container->functions->setIcon(container->teams[o].getLogo(),ui->t15, 30, 30, 20);
    container->functions->setIcon(container->teams[p].getLogo(),ui->t16, 30, 30, 20);

    */

    QList<QLabel*> labels;
    labels << ui->t1 << ui->t2 << ui->t3 <<  ui->t4 << ui->t5 << ui->t6 << ui->t7 << ui->t8
           << ui->t9 << ui->t10 << ui->t11 << ui->t12 << ui->t13 << ui->t14 << ui->t15 << ui->t16;

    for(int i = 0; i < list.size(); i++)
        container->functions->setIcon(container->teams[list[i].getTeamId()].getLogo(),labels[i], 30, 30, 20);


}

void Table::on_powrot_clicked()
{
    Table::close();
}

bool worseTeam(const Team &t1, const Team &t2)
{
    return (t1.getPoint() > t2.getPoint()) ||
           (t1.getPoint() == t2.getPoint() && t1.getDiffer() > t2.getDiffer()) ||
           ((t1.getPoint() == t2.getPoint() && t1.getDiffer() == t2.getDiffer()) && (t1.getGoalScored() > t2.getGoalScored()));
}
