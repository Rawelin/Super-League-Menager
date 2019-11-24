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

    //container->music_player->setPlayer();
    ui->progressBar->setValue(container->music_player->getVolume());

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

    container->functions->setIcon(container->set_multimedia->getButtons(0), ui->forward, "Naprzód");
    container->functions->setIcon(container->set_multimedia->getButtons(1), ui->previous, "Do tyłu");
    container->functions->setIcon(container->set_multimedia->getButtons(2), ui->start, "Graj");
    container->functions->setIcon(container->set_multimedia->getButtons(3), ui->stop, "Stop");
    container->functions->setIcon(container->set_multimedia->getButtons(4), ui->pause, "Pauza");
    container->functions->setIcon(container->set_multimedia->getButtons(5), ui->down, "Ścisz");
    container->functions->setIcon(container->set_multimedia->getButtons(6), ui->up, "Podgłośnij");


    QString semitransparent = "background-color: rgba(255, 255, 255, 70);";
    QString transparent = "background-color: rgba(255, 255, 255, 0);";

    ui->table->setStyleSheet(semitransparent);
    ui->mainmenu->setStyleSheet(semitransparent);
    ui->exit->setStyleSheet(semitransparent);
    ui->stats->setStyleSheet(semitransparent);
    ui->nextday->setStyleSheet(semitransparent);
    ui->teams->setStyleSheet(semitransparent);
    ui->squad->setStyleSheet(semitransparent);
    ui->menu->setStyleSheet(transparent);
    ui->fixture->setStyleSheet(semitransparent);
    ui->save->setStyleSheet(semitransparent);
    ui->load->setStyleSheet(semitransparent);
    ui->tabMenu->setStyleSheet(semitransparent);

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
    ui->tabMenu->setMouseTracking(true);

    ui->start->setMouseTracking(true);
    ui->stop->setMouseTracking(true);
    ui->pause->setMouseTracking(true);
    ui->forward->setMouseTracking(true);
    ui->previous->setMouseTracking(true);
    ui->up->setMouseTracking(true);
    ui->down->setMouseTracking(true);
}

void GameDialog::on_table_clicked()
{
    container->functions->delay(100);
    Table table(this);
    table.exec();
}

void GameDialog::on_squad_clicked()
{
    container->functions->delay(100);
    UserSquad usersquad(0, false);
    usersquad.exec();
}

void GameDialog::on_exit_clicked()
{
    container->music_player->stop();
     QApplication::quit();
  //  GameDialog::close();
}

void GameDialog::on_teams_clicked()
{
    SelectShowSquad selectshowsquad;
    selectshowsquad.exec();
}

void GameDialog::on_stats_clicked()
{
    Data data;
    data.exec();
}

void GameDialog::on_fixture_clicked()
{
    Fixture fixture;
    fixture.exec();
}

void GameDialog::on_nextday_clicked()
{
    Match match(this);
    match.exec();
}

void GameDialog::on_mainmenu_clicked()
{
    container->music_player->stop();
   // container->memeoryHarvester();
    container->loadDefaultData();

   // MainMenu mainmenu;
   // GameDialog::close();
   // mainmenu.exec();

    emit dialogClicked();
}

void GameDialog::start()
{
    container->music_player->start();
}

void GameDialog::stop()
{
    container->music_player->stop();
}

void GameDialog::pause()
{
    container->music_player->pause();
}

void GameDialog::forward()
{
    container->music_player->forward();
}

void GameDialog::previous()
{
    container->music_player->previous();
}

void GameDialog::volumeUp()
{
    if(container->music_player->getVolume() < 100)
    {
        container->music_player->volumeTurnUp();
        ui->progressBar->setValue(container->music_player->getVolume());
    }
}

void GameDialog::volumeDown()
{
    if(container->music_player->getVolume() > 0)
    {
        container->music_player->volumeTurnDown();
        ui->progressBar->setValue(container->music_player->getVolume());
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
    QRect tabmenu = ui->tabMenu->geometry();

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
    container->functions->setHighLight(tabmenu, ui->tabMenu, highlight, normal);
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

void GameDialog::on_tabMenu_clicked()
{
    TabMenu tabmenu;
    tabmenu.exec();

  //  GameDialog::close();
}
