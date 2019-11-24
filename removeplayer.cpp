#include "removeplayer.h"
#include "ui_removeplayer.h"
#include <QDebug>

extern Container *container;

RemovePlayer::RemovePlayer(QWidget *parent, int sqn, const QString save) :
    QDialog(parent),
    ui(new Ui::RemovePlayer)
{
    squad_number = sqn;
    save_path = save;
    formation_color = container->teams[squad_number].getFormation();

    ui->setupUi(this);
    this->showFullScreen();
    //setWindowFlags(Qt::WindowTitleHint);
    setGraphics();
    squad();
}

RemovePlayer::~RemovePlayer()
{
    delete ui;
}

void RemovePlayer::setGraphics()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Background/back2.jpg")))));
    setPalette(palette);

    setStyleSheet("QTableWidget {background-color: transparent;}"
                  "QTableWidget {selection-background-color: rgb(0, 200, 0, 50);}"
                  "QTableWidget {selection-color: rgb(255, 255, 255);}"
                  "QHeaderView::section {background-color: transparent;}"
                  "QHeaderView {background-color: transparent;}"
                  "QTableCornerButton::section {background-color: transparent;}");

    ui->tableWidget->horizontalHeader()->setStyleSheet("color: blue");
    ui->tableWidget->verticalHeader()->setStyleSheet("color: blue");

    QSize icon_size(5,5);
    ui->tableWidget->verticalHeader()->setIconSize(icon_size);

    ui->tableWidget->setFrameShape(QFrame::NoFrame);

    QString style = "background-color: rgba(0, 127, 255, 30);";

    ui->pushButton->setStyleSheet(style);
    ui->editchooseteam->setStyleSheet(style);
}
void RemovePlayer::squad()
{
    int fila;
    QStringList tytuly;

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->tableWidget->setColumnCount(16);
    ui->tableWidget->setColumnWidth(0,150);
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(2,40);
    ui->tableWidget->setColumnWidth(3,40);
    ui->tableWidget->setColumnWidth(4,40);
    ui->tableWidget->setColumnWidth(5,30);
    ui->tableWidget->setColumnWidth(6,30);
    ui->tableWidget->setColumnWidth(7,30);
    ui->tableWidget->setColumnWidth(8,35);
    ui->tableWidget->setColumnWidth(9,35);
    ui->tableWidget->setColumnWidth(10,35);
    ui->tableWidget->setColumnWidth(11,35);
    ui->tableWidget->setColumnWidth(12,35);
    ui->tableWidget->setColumnWidth(13,35);
    ui->tableWidget->setColumnWidth(14,35);
    ui->tableWidget->setColumnWidth(15,35);

    //setWindowTitle("Tabela");
    ui->tableWidget->setColumnCount(16);
    tytuly << "IMIE" << "NAZWISKO" << "POZ"  << "KRAJ" << "WIEK" << "GK" << "DEF" << "MID"
           << "ATT" << "ODB" << "TEC" << "STR" << "PRE" << "ENE" << "OVE" << "GOL";

    ui->tableWidget->setHorizontalHeaderLabels(tytuly);

    /*QString CustomStyle = QString("QTableWidget::item {" "background-color: rgba(162, 186, 60);" "}");

    QString yellow = QString("QTableWidget::item {" "background-color: yellow;" "}");
    QString darkgreen = QString("QTableWidget::item {" "background-color: darkgreen;" "}");
    QString darkblue = QString("QTableWidget::item {" "background-color: darkblue;" "}");
    QString red = QString("QTableWidget::item {" "background-color: red;" "}");
    QString darkcyan = QString("QTableWidget::item {" "background-color: adrkcyan;" "}");

    ui->tableWidget->item(8, 2)->setBackground(Qt::red);
    ui->tableWidget->setStyleSheet(yellow);*/

    //ui->tableWidget->setTextElideMode(Qt::ElideLeft);

    ui->tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeaderItem(1)->setTextAlignment(Qt::AlignLeft);

    for(int i = 0, j= 0; i < container->player[squad_number].size(); ++i, ++j)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        fila = ui->tableWidget->rowCount() - 1;

        ui->tableWidget->setItem(fila, NAME, new QTableWidgetItem(container->player[squad_number][i].getFname()));
        ui->tableWidget->setItem(fila, SURNAME, new QTableWidgetItem(container->player[squad_number][i].getLname()));
        ui->tableWidget->setItem(fila, POSITION, new QTableWidgetItem(container->player[squad_number][i].getPosition()));
        ui->tableWidget->setItem(fila, NATIONALITY, new QTableWidgetItem(container->player[squad_number][i].getNationality()));
        ui->tableWidget->setItem(fila, AGE, new QTableWidgetItem(QString::number(container->player[squad_number][i].getAge())));
        ui->tableWidget->setItem(fila, GK, new QTableWidgetItem(QString::number(container->player[squad_number][i].getGkeeper())));
        ui->tableWidget->setItem(fila, DEF, new QTableWidgetItem(QString::number(container->player[squad_number][i].getDefence())));
        ui->tableWidget->setItem(fila, MID, new QTableWidgetItem(QString::number(container->player[squad_number][i].getMidfield())));
        ui->tableWidget->setItem(fila, ATT, new QTableWidgetItem(QString::number(container->player[squad_number][i].getAttack())));
        ui->tableWidget->setItem(fila, TACKLE, new QTableWidgetItem(QString::number(container->player[squad_number][i].getTackle())));
        ui->tableWidget->setItem(fila, TECHNIK, new QTableWidgetItem(QString::number(container->player[squad_number][i].getTechnik())));
        ui->tableWidget->setItem(fila, SHOT, new QTableWidgetItem(QString::number(container->player[squad_number][i].getShot())));
        ui->tableWidget->setItem(fila, SPEED, new QTableWidgetItem(QString::number(container->player[squad_number][i].getSpeed())));
        ui->tableWidget->setItem(fila, STAMINA, new QTableWidgetItem(QString::number(container->player[squad_number][i].getEndurance())));
        ui->tableWidget->setItem(fila, OVERALL, new QTableWidgetItem(QString::number(container->player[squad_number][i].getOverall(i, formation_color))));
        ui->tableWidget->setItem(fila, GOALS, new QTableWidgetItem(QString::number(container->player[squad_number][i].getGoals())));

       //container->livematch->delay(10);

        for(int i = 2; i < 16; ++i)
        {
            ui->tableWidget->item(j, i)->setTextAlignment(Qt::AlignCenter);
        }
    }

}

void RemovePlayer::on_editchooseteam_clicked()
{
    //EditChooseTeam editchoseteam(0, 2);
    //RemovePlayer::close();
    //editchoseteam.exec();

    emit dialogClicked();
}

void RemovePlayer::on_pushButton_clicked()
{
    int number = 2000;
    number = ui->tableWidget->currentRow()+1;

    int index = container->player[squad_number].size();

    if(number <= index && number != 0)
    {
        container->player[squad_number].remove(number-1);

        container->serialization->saveSquad(save_path, container->player[squad_number]);
        ui->tableWidget->setRowCount(0);
        squad();
    }
    else
    {
        ui->tableWidget->setRowCount(0);
        squad();
    }

}
