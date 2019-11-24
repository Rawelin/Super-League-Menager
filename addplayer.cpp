#include "addplayer.h"
#include "ui_addplayer.h"
#include <QDebug>
#include <QMessageBox>

extern Container *container;

AddPlayer::AddPlayer(QWidget *parent, int sqn, const QString save) :
    QDialog(parent),
    ui(new Ui::AddPlayer)
{
    squad_number = sqn;
    save_path = save;
    formation_color = container->teams[squad_number].getFormation();

    ui->setupUi(this);
    this->showFullScreen();
    //setWindowFlags(Qt::WindowTitleHint);
    setGraphics();
    squad();

    connect(ui->gkSlider, SIGNAL(valueChanged(int)), ui->goalkeeper, SLOT(setValue(int)));
    connect(ui->defSlider, SIGNAL(valueChanged(int)), ui->defence, SLOT(setValue(int)));
    connect(ui->midSlider, SIGNAL(valueChanged(int)), ui->midfield, SLOT(setValue(int)));
    connect(ui->attSlider, SIGNAL(valueChanged(int)), ui->attack, SLOT(setValue(int)));
    connect(ui->tackSlider, SIGNAL(valueChanged(int)), ui->tackling, SLOT(setValue(int)));
    connect(ui->techSlider, SIGNAL(valueChanged(int)), ui->technic, SLOT(setValue(int)));
    connect(ui->shotSlider, SIGNAL(valueChanged(int)), ui->shotting, SLOT(setValue(int)));
    connect(ui->pasSlider, SIGNAL(valueChanged(int)), ui->pass, SLOT(setValue(int)));
    connect(ui->headSlider, SIGNAL(valueChanged(int)), ui->head, SLOT(setValue(int)));
    connect(ui->spdSlider, SIGNAL(valueChanged(int)), ui->speed, SLOT(setValue(int)));
    connect(ui->endSlider, SIGNAL(valueChanged(int)), ui->endurance, SLOT(setValue(int)));
    connect(ui->staSlider, SIGNAL(valueChanged(int)), ui->stamina, SLOT(setValue(int)));
}

AddPlayer::~AddPlayer()
{
    delete ui;
}

void AddPlayer::setGraphics()
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
    //ui->tableWidget->setGridStyle(Qt::SolidLine);

    QString style = "background-color: rgba(0, 127, 255, 30);";

    ui->add->setStyleSheet(style);
    ui->editchooseteam->setStyleSheet(style);

    setSpinBoxGraphics();
}

void AddPlayer::squad()
{
    int fila;
    QStringList tytuly;

    ui->tableWidget->setColumnCount(19);
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
    ui->tableWidget->setColumnWidth(16,35);
    ui->tableWidget->setColumnWidth(17,35);
    ui->tableWidget->setColumnWidth(18,35);
    //setWindowTitle("Tabela");

    tytuly << "IMIE" << "NAZWISKO" << "POZ"  << "KRAJ" << "WIEK" << "GK" << "DEF" << "MID"
           << "ATT" << "ODB" << "TEC" << "STR" <<"PAS" << "HEA" << "PRE" << "END" << "STA"
           << "OVE" << "GOL";

    ui->tableWidget->setHorizontalHeaderLabels(tytuly);

    //QString CustomStyle = QString("QTableWidget::item {" "background-color: rgba(162, 186, 60);" "}");
   // ui->tableWidget->setStyleSheet(CustomStyle);

    ui->tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeaderItem(1)->setTextAlignment(Qt::AlignLeft);

    for(int i = 0, j = 0; i < container->player[squad_number].size(); ++i, ++j)
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
        ui->tableWidget->setItem(fila, PASS, new QTableWidgetItem(QString::number(container->player[squad_number][i].getPass())));
        ui->tableWidget->setItem(fila, HEAD, new QTableWidgetItem(QString::number(container->player[squad_number][i].getHeader())));
        ui->tableWidget->setItem(fila, SPEED, new QTableWidgetItem(QString::number(container->player[squad_number][i].getSpeed())));
        ui->tableWidget->setItem(fila, ENDURANCE, new QTableWidgetItem(QString::number(container->player[squad_number][i].getEndurance())));
        ui->tableWidget->setItem(fila, STAMINA, new QTableWidgetItem(QString::number(container->player[squad_number][i].getStamina())));
        ui->tableWidget->setItem(fila, OVERALL, new QTableWidgetItem(QString::number(container->player[squad_number][i].getOverall(i, formation_color))));
        ui->tableWidget->setItem(fila, GOALS, new QTableWidgetItem(QString::number(container->player[squad_number][i].getGoals())));

       //container->livematch->delay(10);

        for(int i = 2; i < 19; ++i)
        {
            ui->tableWidget->item(j, i)->setTextAlignment(Qt::AlignCenter);
        }
    }

}

void AddPlayer::setSpinBoxGraphics()
{
    ui->name->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->surname->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->position->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->nationality->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->age->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->goalkeeper->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->defence->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->midfield->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->attack->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->tackling->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->technic->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->shotting->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->pass->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->head->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->speed->setStyleSheet("background-color : rgba(255, 255, 255, 10);");
    ui->endurance->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->stamina->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
}

void AddPlayer::on_editchooseteam_clicked()
{
     emit dialogClicked();
    //EditChooseTeam editchooseteam(0, 1);
   // AddPlayer::close();
   // editchooseteam.exec();
}

void AddPlayer::on_add_clicked()
{
    int id;
    QString name;
    QString surname;
    QString nationality;
    QString position;
    int age;
    double gkeeper;
    double defence;
    double midfield;
    double attack;
    double tackle;
    double technik;
    double shot;
    double pass;
    double head;
    double speed;
    double endurance;
    int goals;
    double stamina;

    //Serialization serialization;
    //QVector<Player> player;
    Player tmp;

    name = ui->name->text();
    surname = ui->surname->text();
    nationality = ui->nationality->currentText();
    position = ui->position->currentText();
    age = ui->age->text().toInt();
    gkeeper = ui->goalkeeper->text().toInt();
    defence = ui->defence->text().toInt();
    midfield = ui->midfield->text().toInt();
    attack = ui->attack->text().toInt();
    tackle = ui->tackling->text().toInt();
    technik = ui->technic->text().toInt();
    shot = ui->shotting->text().toInt();
    speed = ui->speed->text().toInt();
    pass = ui->pass->text().toInt();
    head = ui->pass->text().toInt();
    endurance = ui->endurance->text().toInt();
    goals = 0;
    stamina = ui->stamina->text().toInt();
    id = container->teams[squad_number].getTeamId();

    if(ui->name->text().isEmpty() || ui->surname->text().isEmpty())
    {
         QMessageBox::information(this, "Informacja", "Imie I Nazwisko nie moga byc puste");
    }

    else
    {
        //serialization.loadSquad(path, player);

        tmp.setId(id);
        tmp.setFname(name);
        tmp.setLname(surname);
        tmp.setNationality(nationality);
        tmp.setPosition(position);
        tmp.setAge(age);
        tmp.setGkeeper(gkeeper);
        tmp.setDefence(defence);
        tmp.setMidfield(midfield);
        tmp.setAttack(attack);
        tmp.setTackle(tackle);
        tmp.setTechnik(technik);
        tmp.setShot(shot);
        tmp.setPass(pass);
        tmp.setHeader(head);
        tmp.setSpeed(speed);
        tmp.setEndurance(endurance);
        tmp.setGoals2(goals);
        tmp.setPower(stamina);


        container->player[squad_number].push_back(tmp);

        container->serialization->saveSquad(save_path, container->player[squad_number]);

        QMessageBox::information(this, "Informacja", "Gracz zostal dodany");

        ui->name->setText("");
        ui->surname->setText("");
        ui->nationality->setCurrentIndex(0);
        ui->position->setCurrentIndex(0);
        ui->age->setValue(16);
        ui->goalkeeper->setValue(1);
        ui->defence->setValue(1);
        ui->midfield->setValue(1);
        ui->attack->setValue(1);
        ui->tackling->setValue(1);
        ui->technic->setValue(1);
        ui->shotting->setValue(1);
        ui->pass->setValue(1);
        ui->head->setValue(1);
        ui->speed->setValue(1);
        ui->endurance->setValue(1);
        ui->stamina->setValue(1);

        ui->goalkeeper->setValue(ui->gkSlider->value());
        ui->defence->setValue(ui->defSlider->value());
        ui->midfield->setValue(ui->midSlider->value());
        ui->attack->setValue(ui->attSlider->value());
        ui->tackling->setValue(ui->tackSlider->value());
        ui->technic->setValue(ui->techSlider->value());
        ui->shotting->setValue(ui->shotSlider->value());
        ui->pass->setValue(ui->pasSlider->value());
        ui->head->setValue(ui->headSlider->value());
        ui->speed->setValue(ui->spdSlider->value());
        ui->endurance->setValue(ui->endSlider->value());
        ui->stamina->setValue(ui->staSlider->value());

        ui->gkSlider->setValue(ui->goalkeeper->value());
        ui->defSlider->setValue(ui->defence->value());
        ui->midSlider->setValue(ui->midfield->value());
        ui->attSlider->setValue(ui->attack->value());
        ui->tackSlider->setValue(ui->tackling->value());
        ui->techSlider->setValue(ui->technic->value());
        ui->shotSlider->setValue(ui->shotting->value());
        ui->pasSlider->setValue(ui->pass->value());
        ui->headSlider->setValue(ui->head->value());
        ui->spdSlider->setValue(ui->speed->value());
        ui->endSlider->setValue(ui->endurance->value());
        ui->stamina->setValue(ui->staSlider->value());

        ui->tableWidget->setRowCount(0);
        setGraphics();
        squad();
    }

}
