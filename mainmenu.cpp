#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QDebug>

extern Container* container;

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    //ui->stackedWidget->insertWidget(0, choseteam);

    setWindowFlags(Qt::WindowTitleHint);
    setWindowFlags(Qt::FramelessWindowHint);

    container->music_player->setPlayer();
    container->music_player->setTrack(1);
  // container->music_player->start();

   // setAttribute(Qt::WA_TranslucentBackground);
   // setAttribute(Qt::WA_TransparentForMouseEvents);
    this->showFullScreen();

    setGraphics();
    mouseTracking();

    connect(this, SIGNAL(hovered()),this, SLOT(highLight()));
}

MainMenu::~MainMenu()
{
     delete ui;
}

void MainMenu::setGraphics()
{
    QPixmap bkgnd("Stadiony/alianz.jpg");
    container->functions->setBackground(this, bkgnd);

    ui->newGame->setStyleSheet("background-color: rgba(0, 127, 255, 70);");
    ui->load->setStyleSheet("background-color: rgba(0, 127, 255, 70);");
    ui->option->setStyleSheet("background-color: rgba(0, 127, 255, 70);");
    ui->abaut->setStyleSheet("background-color: rgba(0, 127, 255, 70);");
    ui->quit->setStyleSheet("background-color: rgba(0, 127, 255, 70);");
}

void MainMenu::mouseTracking()
{
    setMouseTracking(true);

    ui->newGame->setMouseTracking(true);
    ui->load->setMouseTracking(true);
    ui->option->setMouseTracking(true);
    ui->abaut->setMouseTracking(true);
    ui->quit->setMouseTracking(true);
}

void MainMenu::on_newGame_clicked()
{
    container->music_player->stop();
    ChoseTeam choseteam;
    MainMenu::close();
    choseteam.exec();
    //MainMenu::destroy(true);
    //setAttribute(Qt::WA_DeleteOnClose);

}

void MainMenu::on_abaut_clicked()
{
  // container->music_player->stop();
    ui->stackedWidget->setCurrentIndex(1);
}

void MainMenu::on_option_clicked()
{
    Options options;
    container->music_player->stop();
    MainMenu::close();
    options.exec();
}

void MainMenu::on_load_clicked()
{
    container->music_player->stop();
    container->loadData();

    GameDialog gamedialog;
    MainMenu::close();
    gamedialog.exec();
}

void MainMenu::highLight()
{
    QRect newGame = ui->newGame->geometry();
    QRect load = ui->load->geometry();
    QRect option = ui->option->geometry();
    QRect abaut = ui->abaut->geometry();
    QRect quit = ui->quit->geometry();

    QString highlight = "background-color: rgba(0, 127, 255, 70);";
    QString normal = "background-color: rgba(0, 127, 255, 30);";

    container->functions->setHighLight(newGame, ui->newGame, highlight, normal);
    container->functions->setHighLight(load, ui->load, highlight, normal);
    container->functions->setHighLight(option, ui->option, highlight, normal);
    container->functions->setHighLight(abaut, ui->abaut, highlight, normal);
    container->functions->setHighLight(quit, ui->quit, highlight, normal);
}

void MainMenu::mouseMoveEvent(QMouseEvent *event)
{
    Q_EMIT hovered();

    QWidget::enterEvent(event);
}

void MainMenu::on_quit_clicked()
{
    container->music_player->stop();
    MainMenu::close();
}
