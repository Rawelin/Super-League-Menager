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

     this->showFullScreen();

     mouseTracking();

     setGraphics();


    //setWindowFlags(Qt::WindowTitleHint);
    //setWindowFlags(Qt::FramelessWindowHint);

    container->musicPlayer->setPlayer();
    container->musicPlayer->setTrack(1);
    container->musicPlayer->start();

//    choseTeam = new ChoseTeam(this);
    userDataDialog = new UserDataDialog();
    gameDialog = new GameDialog();
    
    ui->stackedWidget->insertWidget(1, &about);
    ui->stackedWidget->insertWidget(2, &options);
    ui->stackedWidget->insertWidget(3, &choseTeam);
    ui->stackedWidget->insertWidget(4, userDataDialog);
    ui->stackedWidget->insertWidget(5, gameDialog);

    //connect(&about, SIGNAL(dialogClicked()), this, SLOT(bakToMainMenu()));
   // connect(&options, SIGNAL(dialogClicked()), this, SLOT(bakToMainMenu()));
   // connect(choseTeam, SIGNAL(dialogClicked()), this, SLOT(bakToMainMenu()));
    connect(&choseTeam, SIGNAL(dialogClickedGo()), this, SLOT(goToUserDataDialog()));
    connect(userDataDialog, SIGNAL(dialogClicked()), this, SLOT(bakToChoseTeam()));
    connect(userDataDialog, SIGNAL(dialogClickedGo()), this, SLOT(goToGameDialog()));
    connect(gameDialog, SIGNAL(dialogClicked()), this, SLOT(bakToMainMenu()));

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

    ui->mainMenu->setStyleSheet("background-color: rgba(0, 127, 255, 30);");
    ui->newGame->setStyleSheet("background-color: rgba(0, 127, 255, 30);");
    ui->load->setStyleSheet("background-color: rgba(0, 127, 255, 30);");
    ui->option->setStyleSheet("background-color: rgba(0, 127, 255, 30);");
    ui->abaut->setStyleSheet("background-color: rgba(0, 127, 255, 30);");
    ui->quit->setStyleSheet("background-color: rgba(0, 127, 255, 30);");

    ui->mainMenu->setFlat(true);
}

void MainMenu::mouseTracking()
{
    setMouseTracking(true);

    ui->mainMenu->setMouseTracking(true);
    ui->newGame->setMouseTracking(true);
    ui->load->setMouseTracking(true);
    ui->option->setMouseTracking(true);
    ui->abaut->setMouseTracking(true);
    ui->quit->setMouseTracking(true);
}

void MainMenu::highLight()
{
    QRect mainMenu = ui->mainMenu->geometry();
    QRect newGame = ui->newGame->geometry();
    QRect load = ui->load->geometry();
    QRect option = ui->option->geometry();
    QRect abaut = ui->abaut->geometry();
    QRect quit = ui->quit->geometry();

    QString highlight = "background-color: rgba(0, 127, 255, 70);";
    QString normal = "background-color: rgba(0, 127, 255, 30);";

    container->functions->setHighLight(mainMenu, ui->mainMenu, highlight, normal);
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

void MainMenu::on_mainMenu_clicked()
{
    container->musicPlayer->setTrack(1);
    container->musicPlayer->start();
    ui->stackedWidget->setCurrentIndex(0);
    ui->mainMenu->setStyleSheet("background-color: rgba(0, 127, 255, 70);");
    QPixmap bkgnd("Stadiony/alianz.jpg");
    container->functions->setBackground(this, bkgnd);
    ui->mainMenu->setFlat(true);
    ui->newGame->setFlat(false);
    ui->abaut->setFlat(false);
    ui->option->setFlat(false);

}

void MainMenu::on_newGame_clicked()
{

    //container->music_player->setTrack(5);
    //container->music_player->stop();

   // ChoseTeam choseteam;
   // MainMenu::close();
   // choseteam.exec();
   // MainMenu::destroy(true);
    //setAttribute(Qt::WA_DeleteOnClose);


    container->musicPlayer->setTrack(5);
    container->musicPlayer->start();
    ui->newGame->setFlat(true);
    ui->mainMenu->setFlat(false);
    ui->abaut->setFlat(false);
    ui->option->setFlat(false);

    QPixmap bkgnd("Stadiony/realfuture.jpg");
    container->functions->setBackground(this, bkgnd);
     ui->stackedWidget->setCurrentIndex(3);

}

void MainMenu::on_abaut_clicked()
{
  // container->music_player->stop();

    QPixmap bkgnd("Background/black.jpg");
    container->functions->setBackground(this, bkgnd);
    ui->stackedWidget->setCurrentIndex(1);
    ui->abaut->setFlat(true);
    ui->newGame->setFlat(false);
    ui->mainMenu->setFlat(false);
    ui->option->setFlat(false);

}

void MainMenu::on_option_clicked()
{
    QPixmap bkgnd("Background/black.jpg");
    container->functions->setBackground(this, bkgnd);
    ui->stackedWidget->setCurrentIndex(2);
    ui->option->setFlat(true);
    ui->mainMenu->setFlat(false);
    ui->abaut->setFlat(false);
    ui->newGame->setFlat(false);

}

void MainMenu::on_quit_clicked()
{
    container->musicPlayer->stop();
    MainMenu::close();
}

void MainMenu::on_load_clicked()
{
    container->musicPlayer->stop();
    container->loadData();

    ui->option->setVisible(false);
    ui->load->setVisible(false);
    ui->quit->setVisible(false);
    ui->mainMenu->setVisible(false);
    ui->abaut->setVisible(false);
    ui->newGame->setVisible(false);

    ui->stackedWidget->setCurrentIndex(5);
    QPixmap bkgnd("Background/back2.jpg");
    container->functions->setBackground(this, bkgnd);

    //GameDialog gamedialog;
    //MainMenu::close();
    //gamedialog.exec();
}

void MainMenu::bakToMainMenu()
{
    ui->option->setVisible(true);
    ui->load->setVisible(true);
    ui->quit->setVisible(true);
    ui->mainMenu->setVisible(true);
    ui->abaut->setVisible(true);
    ui->newGame->setVisible(true);

    ui->mainMenu->setFlat(true);
    ui->newGame->setFlat(false);

    container->musicPlayer->setPlayer();
    container->musicPlayer->setTrack(1);
    container->musicPlayer->start();
    ui->stackedWidget->setCurrentIndex(0);
    QPixmap bkgnd("Stadiony/alianz.jpg");
    container->functions->setBackground(this, bkgnd);
}

void MainMenu::bakToChoseTeam()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainMenu::goToGameDialog()
{
    container->musicPlayer->stop();
    container->musicPlayer->setTrack(0);
    container->musicPlayer->start();

    ui->option->setVisible(false);
    ui->load->setVisible(false);
    ui->quit->setVisible(false);
    ui->mainMenu->setVisible(false);
    ui->abaut->setVisible(false);
    ui->newGame->setVisible(false);

    ui->stackedWidget->setCurrentIndex(5);
    QPixmap bkgnd("Background/back2.jpg");
    container->functions->setBackground(this, bkgnd);
}

void MainMenu::goToUserDataDialog()
{
    ui->stackedWidget->setCurrentIndex(4);
}








