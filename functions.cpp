#include "QDebug"
#include "functions.h"

Functions::Functions()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
}

int Functions::randInt(int min, int max)
{
    return qrand() % ((max + 1) - min) + min;
}

void Functions::delay(double millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait);

    while(QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void Functions::setIcon(QPixmap pixmap, QLabel *label, int x, int y)
{
    QPixmap newPixmap = pixmap.scaled(QSize(x, y),  Qt::KeepAspectRatio);
    label->setPixmap(newPixmap);

    label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

}

void Functions::setIcon(QPixmap pixmap, QPushButton *button, QString team_name)
{
    QIcon icon(pixmap);
    button->setIcon(icon);
    button->setIconSize(QSize(50, 50));
    button->setStyleSheet("background-color: rgba(255, 255, 255, 10);");
    button->setToolTip(team_name);
}

void Functions::setIcon(QPixmap pixmap, QLabel *label, int x, int y, int time)
{
    QPixmap newPixmap = pixmap.scaled(QSize(x, y),  Qt::KeepAspectRatio);
    label->setPixmap(newPixmap);

    label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    delay(time);
}

void Functions::setHighLight(QRect rect, QPushButton *button, QString &highlight_1, QString &highlight_2)
{
    if(rect.contains(QCursor::pos()))
       button->setStyleSheet(highlight_1);
    else
        button->setStyleSheet(highlight_2);
}

void Functions::showFrame(QTableWidget *widget, QRect rect)
{
    if(rect.contains(QCursor::pos()))
      widget->setVisible(true);
    else
      widget->setVisible(false);

}

void Functions::showTeamStats(ShowTeamStats *showteamstats, QRect rect, int id)
{
    showteamstats->setTeamId(id);
    showteamstats->showStats();

    if(rect.contains(QCursor::pos()))
      showteamstats->setVisible(true);
    else
      showteamstats->close();
}

void Functions::showPlayerStats(ShowPlayerStats *showplayerstats, QRect rect, int id)
{
    showplayerstats->setPlayerId(id);
    showplayerstats->showStats();

    if(rect.contains(QCursor::pos()))
      showplayerstats->setVisible(true);
    else
        showplayerstats->close();
}
void Functions::setBackground(QMainWindow *window, QPixmap pixmap)
{
    pixmap = pixmap.scaled(window->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pixmap);
    window->setPalette(palette);
}

void Functions::setBackground(QDialog *dialog, QPixmap pixmap)
{
    pixmap = pixmap.scaled(dialog->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pixmap);
    dialog->setPalette(palette);
}

void Functions::setLabelTextColor(QLabel *label, int number)
{
    QPalette palette;

    if(number >= 95)
        palette.setColor(QPalette::WindowText, QColor(120, 0, 0));
    else if(number < 95 && number >= 90)
        palette.setColor(QPalette::WindowText, QColor(255, 0, 0));
    else if(number < 90 && number >= 80)
        palette.setColor(QPalette::WindowText, QColor(255, 69, 0));
    else if(number < 80 && number >= 70)
        palette.setColor(QPalette::WindowText, QColor(0, 255, 0));
    else if(number < 70)
        palette.setColor(QPalette::WindowText, QColor(255, 255, 255));

    label->setPalette(palette);
}

void Functions::setLabelTextColor(QLabel *label, QString position)
{
    QPalette palette;

    if(position == "GK")
        palette.setColor(QPalette::WindowText, QColor(255, 255, 0));
    else if(position == "CB" || position == "RB" || position == "LB")
        palette.setColor(QPalette::WindowText, QColor(0, 255, 0));
    else if(position == "DM" || position == "CM" || position == "RM" || position == "LM" || position == "AM")
        palette.setColor(QPalette::WindowText, QColor(0, 0, 255));
    else if(position == "LW" || position == "RW" || position == "SS" || position == "CF")
            palette.setColor(QPalette::WindowText, QColor(255, 0, 0));

    label->setPalette(palette);
}



