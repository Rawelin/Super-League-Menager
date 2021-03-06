#include <QDebug>
#include "fixture.h"
#include "ui_fixture.h"

extern Container *container;

Fixture::Fixture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fixture)
{
    ui->setupUi(this);
    this->showFullScreen();

    fixture_number = container->league->getFixture();
    p1 = 0;
    p2 = 1;

    ui->label_number->setNum(fixture_number);

    setGraphic();
    setFixture();

    connect(ui->next, SIGNAL(clicked(bool)), this, SLOT(next()));
    connect(ui->previous, SIGNAL(clicked(bool)), this, SLOT(previous()));
}

Fixture::~Fixture()
{
    delete ui;
}

void Fixture::setGraphic()
{
    QPalette palette;
    palette.setBrush(QPalette::Background,*(new QBrush(*(new QPixmap("Background/back2.jpg")))));
    setPalette(palette);

    ui->next->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->previous->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->back->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

    ui->frame->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame_2->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame_3->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame_4->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame_5->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame_6->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame_7->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame_8->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    ui->frame_9->setStyleSheet("background-color: rgba(255, 255, 255, 10);");

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

    ui->teamname->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->label_number->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs1->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs4->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs5->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs6->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs7->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->vs8->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

}

void Fixture::setFixture()
{

    Versus versus(fixture_number);

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

    ui->t1->setText(container->teams[h1].getName() + " " + container->teams[h1].getCity());
    ui->t2->setText(container->teams[a1].getName() + " " + container->teams[a1].getCity());
    container->functions->setIcon(container->teams[h1].getLogo(), ui->l1);
    container->functions->setIcon(container->teams[a1].getLogo(), ui->l2);

    ui->t3->setText(container->teams[h2].getName() + " " + container->teams[h2].getCity());
    ui->t4->setText(container->teams[a2].getName() + " " + container->teams[a2].getCity());
    container->functions->setIcon(container->teams[h2].getLogo(), ui->l3);
    container->functions->setIcon(container->teams[a2].getLogo(), ui->l4);

    ui->t5->setText(container->teams[h3].getName() + " " + container->teams[h3].getCity());
    ui->t6->setText(container->teams[a3].getName() + " " + container->teams[a3].getCity());
    container->functions->setIcon(container->teams[h3].getLogo(), ui->l5);
    container->functions->setIcon(container->teams[a3].getLogo(), ui->l6);

    ui->t7->setText(container->teams[h4].getName() + " " + container->teams[h4].getCity());
    ui->t8->setText(container->teams[a4].getName() + " " + container->teams[a4].getCity());
    container->functions->setIcon(container->teams[h4].getLogo(), ui->l7);
    container->functions->setIcon(container->teams[a4].getLogo(), ui->l8);

    ui->t9->setText(container->teams[h5].getName() + " " + container->teams[h5].getCity());
    ui->t10->setText(container->teams[a5].getName() + " " + container->teams[a5].getCity());
    container->functions->setIcon(container->teams[h5].getLogo(), ui->l9);
    container->functions->setIcon(container->teams[a5].getLogo(), ui->l10);

    ui->t11->setText(container->teams[h6].getName() + " " + container->teams[h6].getCity() );
    ui->t12->setText(container->teams[a6].getName() + " " + container->teams[a6].getCity());
    container->functions->setIcon(container->teams[h6].getLogo(), ui->l11);
    container->functions->setIcon(container->teams[a6].getLogo(), ui->l12);

    ui->t13->setText(container->teams[h7].getName() + " " + container->teams[h7].getCity() );
    ui->t14->setText(container->teams[a7].getName() + " " + container->teams[a7].getCity());
    container->functions->setIcon(container->teams[h7].getLogo(), ui->l13);
    container->functions->setIcon(container->teams[a7].getLogo(), ui->l14);

    ui->t15->setText(container->teams[h8].getName() + " " + container->teams[h8].getCity() );
    ui->t16->setText(container->teams[a8].getName() + " " + container->teams[a8].getCity());
    container->functions->setIcon(container->teams[h8].getLogo(), ui->l15);
    container->functions->setIcon(container->teams[a8].getLogo(), ui->l16);
}

void Fixture::next()
{
    if(fixture_number < 30)
    {
       fixture_number++;
       ui->label_number->setNum(fixture_number);
    }
    setFixture();
}

void Fixture::previous()
{

    if(fixture_number > 1)
    {
        fixture_number--;
        ui->label_number->setNum(fixture_number);
    }
    setFixture();
}

void Fixture::on_back_clicked()
{
    Fixture::close();
}
