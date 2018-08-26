#include "contextmenu.h"
#include "ui_contextmenu.h"

ContextMenu::ContextMenu(QWidget *parent, const QString txt) :
    QDialog(parent),
    ui(new Ui::ContextMenu)
{
    text = txt;

    setWindowFlags(Qt::WindowTitleHint);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->label->setText(text);


    QPixmap lotto("Background/lotto.jpg");
    QIcon logo(lotto);
    ui->pause->setIcon(logo);
    ui->pause->setIconSize(lotto.rect().size());
    ui->pause->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
}

ContextMenu::~ContextMenu()
{
    delete ui;
}
