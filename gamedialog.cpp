#include "gamedialog.h"
#include "ui_gamedialog.h"
#include "mainmenu.h"


extern Container *container;

GameDialog::GameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameDialog)
{
    ui->setupUi(this);

    this->showFullScreen();

    mouseTracking();
    setIco();

    ui->progressBar->setValue(container->musicPlayer->getVolume());

    connect(ui->start, SIGNAL(clicked(bool)), this, SLOT(start()));
    connect(ui->stop, SIGNAL(clicked(bool)), this, SLOT(stop()));
    connect(ui->pause, SIGNAL(clicked(bool)), this, SLOT(pause()));
    connect(ui->forward,SIGNAL(clicked(bool)),this, SLOT(forward()));
    connect(ui->previous,SIGNAL(clicked(bool)),this, SLOT(previous()));
    connect(ui->up, SIGNAL(clicked(bool)), this, SLOT(volumeUp()));
    connect(ui->down, SIGNAL(clicked(bool)), this, SLOT(volumeDown()));

    connect(this, SIGNAL(hovered()), this, SLOT(highLight()));



}

GameDialog::~GameDialog()
{
    delete ui;
}

void GameDialog::setIco()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Background/back2.jpg")))));
    setPalette(palette);

    container->functions->setIcon(container->setMultimedia->getButtons(0), ui->forward, "Naprzód");
    container->functions->setIcon(container->setMultimedia->getButtons(1), ui->previous, "Do tyłu");
    container->functions->setIcon(container->setMultimedia->getButtons(2), ui->start, "Graj");
    container->functions->setIcon(container->setMultimedia->getButtons(3), ui->stop, "Stop");
    container->functions->setIcon(container->setMultimedia->getButtons(4), ui->pause, "Pauza");
    container->functions->setIcon(container->setMultimedia->getButtons(5), ui->down, "Ścisz");
    container->functions->setIcon(container->setMultimedia->getButtons(6), ui->up, "Podgłośnij");


    ui->gameMenu->setVisible(false);

    QString semitransparent = "background-color: rgba(255, 255, 255, 70);";
    QString transparent = "background-color: rgba(255, 255, 255, 0);";

    ui->table->setStyleSheet(semitransparent);
    ui->mainmenu->setStyleSheet(semitransparent);
    ui->exit->setStyleSheet(semitransparent);
    ui->stats->setStyleSheet(semitransparent);
    ui->nextday->setStyleSheet(semitransparent);
    ui->teams->setStyleSheet(semitransparent);
    ui->squad->setStyleSheet(semitransparent);
    ui->fixture->setStyleSheet(semitransparent);
    ui->save->setStyleSheet(semitransparent);
    ui->load->setStyleSheet(semitransparent);
    ui->gameMenu->setStyleSheet(semitransparent);

   // ui->progressBar->setStyleSheet("background-color: rgba(0, 0, 0, 10);");


    ui->progressBar->setStyleSheet("QProgressBar{"
                                "border: 1px solid transparent;"
                                "text-align: center;"
                                "color:rgba(0,0,255,100);"
                                "border-radius: 5px;"
                                "background-color: rgba(255, 255, 255, 10);"
                                    "}"
                                "QProgressBar::chunk{"
                                "background-color: rgba(0, 150, 0, 20);"
                                "}");

    ui->squad->setToolTip("Skład twojej drużyny");
    ui->teams->setToolTip("Składy innych drużyn");
    ui->nextday->setToolTip("Następny dzień");
    ui->fixture->setToolTip("Terminarz rozgrywek");
    ui->table->setToolTip("Tabela ligi");
    ui->mainmenu->setToolTip("Wyjscie do main menu");
    ui->exit->setToolTip("Wyjście z gry");
    ui->stats->setToolTip("Statystyki zespołów");
    ui->gameMenu->setToolTip("Powrót do menu gry");
}

void GameDialog::mouseTracking()
{
    setMouseTracking(true);

    ui->table->setMouseTracking(true);
    ui->fixture->setMouseTracking(true);
    ui->squad->setMouseTracking(true);
    ui->teams->setMouseTracking(true);
    ui->nextday->setMouseTracking(true);
    ui->mainmenu->setMouseTracking(true);
    ui->exit->setMouseTracking(true);
    ui->stats->setMouseTracking(true);
    ui->save->setMouseTracking(true);
    ui->load->setMouseTracking(true);
    ui->gameMenu->setMouseTracking(true);

    ui->start->setMouseTracking(true);
    ui->stop->setMouseTracking(true);
    ui->pause->setMouseTracking(true);
    ui->forward->setMouseTracking(true);
    ui->previous->setMouseTracking(true);
    ui->up->setMouseTracking(true);
    ui->down->setMouseTracking(true);
}

void GameDialog::addWidgets()
{
    if(widgetsAdded)
    {
        ui->stackedWidget->insertWidget(1, new Table());
        ui->stackedWidget->insertWidget(2, new UserSquad());
        ui->stackedWidget->insertWidget(3, new SelectShowSquad());
        ui->stackedWidget->insertWidget(4, new Data());
        ui->stackedWidget->insertWidget(5, new Fixture());
        ui->stackedWidget->insertWidget(6, new Match());

        widgetsAdded = false;
    }
}

void GameDialog::on_table_clicked()
{
    //container->functions->delay(100);
    //Table table(this);
    //table.exec();

    //table = new Table();


    addWidgets();
    ui->stackedWidget->setCurrentIndex(1);
}

void GameDialog::on_squad_clicked()
{
//    container->functions->delay(100);
//    UserSquad usersquad(0, false);
//    usersquad.exec();

    ui->gameMenu->setVisible(true);
    ui->stats->setVisible(false);
    ui->fixture->setVisible(false);
    ui->load->setVisible(false);
    ui->mainmenu->setVisible(false);
    ui->exit->setVisible(false);

    addWidgets();
    ui->stackedWidget->setCurrentIndex(2);
}

void GameDialog::on_exit_clicked()
{
//    container->musicPlayer->stop();
//    QApplication::quit();
  //  GameDialog::close();

    emit exitClicked();
}

void GameDialog::on_teams_clicked()
{
//    SelectShowSquad selectshowsquad;
//    selectshowsquad.exec();
    addWidgets();
    ui->stackedWidget->setCurrentIndex(3);
}

void GameDialog::on_stats_clicked()
{
//    Data data;
//    data.exec();
     addWidgets();
     ui->stackedWidget->setCurrentIndex(4);
}

void GameDialog::on_fixture_clicked()
{
//    Fixture fixture;
//    fixture.exec();
     addWidgets();
     ui->stackedWidget->setCurrentIndex(5);
}

void GameDialog::on_nextday_clicked()
{
//    Match match(this);
//    match.exec();

     addWidgets();
     ui->stackedWidget->setCurrentIndex(6);
     ui->stats->setVisible(false);
     ui->fixture->setVisible(false);
     ui->load->setVisible(false);
     ui->mainmenu->setVisible(false);
     ui->exit->setVisible(false);
}

void GameDialog::on_mainmenu_clicked()
{
    container->musicPlayer->stop();
   // container->memeoryHarvester();
    container->loadDefaultData();

   // MainMenu mainmenu;
   // GameDialog::close();
   // mainmenu.exec();

    emit dialogClicked();
}

void GameDialog::start()
{
    container->musicPlayer->start();
}

void GameDialog::stop()
{
    container->musicPlayer->stop();
}

void GameDialog::pause()
{
    container->musicPlayer->pause();
}

void GameDialog::forward()
{
    container->musicPlayer->forward();
}

void GameDialog::previous()
{
    container->musicPlayer->previous();
}

void GameDialog::volumeUp()
{
    if(container->musicPlayer->getVolume() < 100)
    {
        container->musicPlayer->volumeTurnUp();
        ui->progressBar->setValue(container->musicPlayer->getVolume());
    }
}

void GameDialog::volumeDown()
{
    if(container->musicPlayer->getVolume() > 0)
    {
        container->musicPlayer->volumeTurnDown();
        ui->progressBar->setValue(container->musicPlayer->getVolume());
    }
}

void GameDialog::highLight()
{
    QRect table = ui->table->geometry();
    QRect mainmenu = ui->mainmenu->geometry();
    QRect exit = ui->exit->geometry();
    QRect stats = ui->stats->geometry();
    QRect nextday = ui->nextday->geometry();
    QRect teams = ui->teams->geometry();
    QRect squad = ui->squad->geometry();
    QRect fixture = ui->fixture->geometry();
    QRect save = ui->save->geometry();
    QRect load = ui->load->geometry();
    QRect gameMenu = ui->gameMenu->geometry();

    QRect forward = ui->forward->geometry();
    QRect previous = ui->previous->geometry();
    QRect start = ui->start->geometry();
    QRect stop = ui->stop->geometry();
    QRect pause = ui->pause->geometry();
    QRect up = ui->up->geometry();
    QRect down = ui->down->geometry();

    QString highlight = "background-color: rgba(255, 255, 255, 70);";
    QString normal = "background-color: rgba(255, 255, 255, 30);";

    container->functions->setHighLight(table, ui->table, highlight, normal);
    container->functions->setHighLight(mainmenu, ui->mainmenu, highlight, normal);
    container->functions->setHighLight(exit, ui->exit, highlight, normal);
    container->functions->setHighLight(stats, ui->stats, highlight, normal);
    container->functions->setHighLight(nextday, ui->nextday, highlight, normal);
    container->functions->setHighLight(teams, ui->teams, highlight, normal);
    container->functions->setHighLight(squad, ui->squad, highlight, normal);
    container->functions->setHighLight(fixture, ui->fixture, highlight, normal);
    container->functions->setHighLight(save, ui->save, highlight, normal);
    container->functions->setHighLight(load, ui->load, highlight, normal);
    container->functions->setHighLight(gameMenu, ui->gameMenu, highlight, normal);
    container->functions->setHighLight(forward, ui->forward, highlight, normal);
    container->functions->setHighLight(previous, ui->previous, highlight, normal);
    container->functions->setHighLight(start, ui->start, highlight, normal);
    container->functions->setHighLight(stop, ui->stop, highlight, normal);
    container->functions->setHighLight(pause, ui->pause, highlight, normal);
    container->functions->setHighLight(up, ui->up, highlight, normal);
    container->functions->setHighLight(down, ui->down, highlight, normal);


    //container->hovered->setHighLight(table, ui->table, highlight, normal);

}

void GameDialog::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug() << event->pos();

    Q_EMIT hovered();
    QWidget::enterEvent(event);
}

void GameDialog::on_save_clicked()
{
    container->saveData();
}

void GameDialog::on_load_clicked()
{
    container->loadData();
}


void GameDialog::on_gameMenu_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
     ui->stats->setVisible(true);
     ui->fixture->setVisible(true);
     ui->load->setVisible(true);
     ui->mainmenu->setVisible(true);
     ui->exit->setVisible(true);
}
