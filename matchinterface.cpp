#include "matchinterface.h"
#include "ui_matchinterface.h"
#include <QGlobal.h>
#include <QTime>
#include <QDebug>

extern Container *container;

MatchInterface::MatchInterface(QDialog *parent) :
    matchDialog(parent),
    ui(new Ui::MatchInterface)
{

    ui->setupUi(this);
    this->showFullScreen();

   // setWindowFlags(Qt::FramelessWindowHint);

    fixture = 0;
    value = 0;

    locker = false;
   //   this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);

    setGraphics();
    setting();
}

MatchInterface::~MatchInterface()
{
    delete ui;
}

void MatchInterface::setGraphics()
{

    QPalette palette;
    palette.setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Background/back2.jpg")))));
    setPalette(palette);

    ui->back->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->play->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    setStyleSheet("QListWidget {background-color: transparent;}");

    //QVector<QListWidget*>list ={ui->lista1};

    ui->listh1->setFrameShape(QFrame::NoFrame);
    ui->lista1->setFrameShape(QFrame::NoFrame);
    ui->listh2->setFrameShape(QFrame::NoFrame);
    ui->lista2->setFrameShape(QFrame::NoFrame);
    ui->listh3->setFrameShape(QFrame::NoFrame);
    ui->lista3->setFrameShape(QFrame::NoFrame);
    ui->listh4->setFrameShape(QFrame::NoFrame);
    ui->lista4->setFrameShape(QFrame::NoFrame);
    ui->listh5->setFrameShape(QFrame::NoFrame);
    ui->lista5->setFrameShape(QFrame::NoFrame);
    ui->listh6->setFrameShape(QFrame::NoFrame);
    ui->lista6->setFrameShape(QFrame::NoFrame);
    ui->listh7->setFrameShape(QFrame::NoFrame);
    ui->lista7->setFrameShape(QFrame::NoFrame);
    ui->listh8->setFrameShape(QFrame::NoFrame);
    ui->lista8->setFrameShape(QFrame::NoFrame);

    ui->frame->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame2->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame3->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame4->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame5->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame6->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame7->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame8->setStyleSheet("background-color: rgba(255, 255, 255, 10);");


    ui->listh1->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->lista1->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->listh2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->lista2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->listh3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->lista3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->listh4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->lista4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->listh5->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->lista5->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->listh6->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->lista6->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->listh7->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->lista7->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->listh8->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->lista8->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->t1->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t5->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t6->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t7->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t8->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t9->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t10->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t11->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t12->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t13->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t14->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t15->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->t16->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->h1->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->a1->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->h2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->a2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->h3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->a3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->h4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->a4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->h5->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->a5->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->h6->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->a6->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->h7->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->a7->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->h8->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->a8->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->vs1->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs5->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs6->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs7->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs8->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    ui->progressBar->setStyleSheet("QProgressBar{"
                                "border: 1px solid transparent;"
                                "text-align: center;"
                                "color:rgba(255,255,255,100);"
                                "border-radius: 5px;"
                                "background-color: rgba(255, 255, 255, 10);"
                                    "}"
                                "QProgressBar::chunk{"
                                "background-color: rgba(0, 200, 0, 20);"
                                "}");
      ui->back->setVisible(false);

}

void MatchInterface::setData(int home, int away, QLabel *homelabel, QLabel *awaylabel, QListWidget *listhome, QListWidget *listaway)
{
    if(!(container->teams[home].getStrikerList().isEmpty()))
    {
        for(int i = 0; i < container->teams[home].getStrikerList().size(); ++i)
           listhome->addItem(container->teams[home].getStrikerList()[i]);
    }
    if(!(container->teams[away].getStrikerList().isEmpty()))
    {
        for(int i = 0; i < container->teams[away].getStrikerList().size(); ++i)
           listaway->addItem(container->teams[away].getStrikerList()[i]);
    }

    homelabel->setNum(container->teams[home].getScore());
    awaylabel->setNum(container->teams[away].getScore());
}

void MatchInterface::setting()
{
    int fixture = container->league->getFixture();
    ui->fix_number->setNum(container->league->getFixture());

    Versus versus(fixture);

    int h1 = versus.getTeamsPaired(0);
    int a1 = versus.getTeamsPaired(1);
    int h2 = versus.getTeamsPaired(2);
    int a2 = versus.getTeamsPaired(3);
    int h3 = versus.getTeamsPaired(4);
    int a3 = versus.getTeamsPaired(5);
    int h4 = versus.getTeamsPaired(6);
    int a4 = versus.getTeamsPaired(7);
    int h5 = versus.getTeamsPaired(8);
    int a5 = versus.getTeamsPaired(9);
    int h6 = versus.getTeamsPaired(10);
    int a6 = versus.getTeamsPaired(11);
    int h7 = versus.getTeamsPaired(12);
    int a7 = versus.getTeamsPaired(13);
    int h8 = versus.getTeamsPaired(14);
    int a8 = versus.getTeamsPaired(15);

    ui->t1->setText(container->teams[h1].getShortName());
    ui->t2->setText(container->teams[a1].getShortName());
    container->functions->setIcon(container->teams[h1].getLogo(), ui->l1);
    container->functions->setIcon(container->teams[a1].getLogo(), ui->l2);

    ui->t3->setText(container->teams[h2].getShortName());
    ui->t4->setText(container->teams[a2].getShortName());
    container->functions->setIcon(container->teams[h2].getLogo(), ui->l3);
    container->functions->setIcon(container->teams[a2].getLogo(), ui->l4);

    ui->t5->setText(container->teams[h3].getShortName());
    ui->t6->setText(container->teams[a3].getShortName());
    container->functions->setIcon(container->teams[h3].getLogo(), ui->l5);
    container->functions->setIcon(container->teams[a3].getLogo(), ui->l6);

    ui->t7->setText(container->teams[h4].getShortName());
    ui->t8->setText(container->teams[a4].getShortName());
    container->functions->setIcon(container->teams[h4].getLogo(), ui->l7);
    container->functions->setIcon(container->teams[a4].getLogo(), ui->l8);

    ui->t9->setText(container->teams[h5].getShortName());
    ui->t10->setText(container->teams[a5].getShortName());
    container->functions->setIcon(container->teams[h5].getLogo(), ui->l9);
    container->functions->setIcon(container->teams[a5].getLogo(), ui->l10);

    ui->t11->setText(container->teams[h6].getShortName());
    ui->t12->setText(container->teams[a6].getShortName());
    container->functions->setIcon(container->teams[h6].getLogo(), ui->l11);
    container->functions->setIcon(container->teams[a6].getLogo(), ui->l12);

    ui->t13->setText(container->teams[h7].getShortName());
    ui->t14->setText(container->teams[a7].getShortName());
    container->functions->setIcon(container->teams[h7].getLogo(), ui->l13);
    container->functions->setIcon(container->teams[a7].getLogo(), ui->l14);

    ui->t15->setText(container->teams[h8].getShortName());
    ui->t16->setText(container->teams[a8].getShortName());
    container->functions->setIcon(container->teams[h8].getLogo(), ui->l15);
    container->functions->setIcon(container->teams[a8].getLogo(), ui->l16);

   confrontation(h1, a1);
   setData(h1, a1, ui->h1, ui->a1, ui->listh1, ui->lista1);

   confrontation(h2, a2);
   setData(h2, a2, ui->h2, ui->a2, ui->listh2, ui->lista2);

   confrontation(h3, a3);
   setData(h3, a3, ui->h3, ui->a3, ui->listh3, ui->lista3);

   confrontation(h4, a4);
   setData(h4, a4, ui->h4, ui->a4, ui->listh4, ui->lista4);

   confrontation(h5, a5);
   setData(h5, a5, ui->h5, ui->a5, ui->listh5, ui->lista5);

   confrontation(h6, a6);
   setData(h6, a6, ui->h6, ui->a6, ui->listh6, ui->lista6);

   confrontation(h7, a7);
   setData(h7, a7, ui->h7, ui->a7, ui->listh7, ui->lista7);

   confrontation(h8, a8);
   setData(h8, a8, ui->h8, ui->a8, ui->listh8, ui->lista8);

   ui->play->setVisible(false);
   ui->back->setVisible(true);

   if(value == 100)
   {

      ui->progressBar->setStyleSheet("QProgressBar{"
                                     "border: 1px solid transparent;"
                                     "text-align: center;"
                                     "color:rgba(255,255,255,100);"
                                     "border-radius: 5px;"
                                     "background-color: rgba(255, 255, 255, 100);"
                                         "}"
                                     "QProgressBar::chunk{"
                                     "background-color: rgba(0, 255, 0, 20);"
                                     "}");

      container->functions->delay(1000);

      ui->progressBar->setStyleSheet("QProgressBar{"
                                     "border: 1px solid transparent;"
                                     "text-align: center;"
                                     "color:rgba(255,255,255,100);"
                                     "border-radius: 5px;"
                                     "background-color: rgba(255, 255, 255, 10);"
                                     "}"
                                     "QProgressBar::chunk{"
                                     "background-color: rgba(0, 200, 0, 20);"
                                     "}");
     }
}

void MatchInterface::confrontation(int home, int away)
{
   int id = container->userData->getId();
   int default_pressing = 0;

   container->artificialInteligence->resetVariable();

   if(container->teams[home].getTeamId() != id)                  // ustala ktory zespol z pary jest sterowany przez computer
   {
        default_pressing = container->teams[home].getPressing();
        container->artificialInteligence->setId(home);
        container->artificialInteligence->setHome(true);
        container->artificialInteligence->setAway(false);

   }
   if(container->teams[away].getTeamId() != id)
   {
        default_pressing = container->teams[away].getPressing();
        container->artificialInteligence->setId(away);
        container->artificialInteligence->setAway(true);
        container->artificialInteligence->setHome(false); 
   }

   if(container->teams[home].getTeamId() == id ||
      container->teams[away].getTeamId() == id)
   {
      ContextMenu contextmenu(0, "TWOJA KOLEJ");
      contextmenu.exec();

      container->functions->delay(100);
      UserSquad squad(0, false);
      squad.exec();

      LiveMatch livematch(0, home, away);
      livematch.exec();

   }
   else
   {
       MatchSimulation matchsimulation(home, away);
       matchsimulation.matchProgress();

   }

   value += 12.5;
   ui->progressBar->setValue(value);

}


void MatchInterface::on_back_clicked()
{

    for(int i = 0; i < container->teams.size(); i++)
        container->teams[i].clearStrikerList();

    MatchInterface::close();
}


void MatchInterface::on_play_clicked()
{
    locker = true;
     ui->play->setVisible(false);
    setting();
}
