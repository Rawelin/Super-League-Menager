#ifndef MATCHINTERFACE_H
#define MATCHINTERFACE_H

#include <QDialog>
#include <QObject>
#include <QMutex>
#include <QWaitCondition>
#include <thread>
#include "container.h"
#include "livematch.h"
#include "matchsimulation.h"
#include "versus.h"

class LiveMatch;

namespace Ui {
class MatchInterface;
}

class MatchInterface : public QDialog
{
    Q_OBJECT

public:
    explicit MatchInterface(QDialog *parent = 0);
    ~MatchInterface();
    void setGraphics();
    void setting();
    void setData(int, int,  QLabel *, QLabel *, QListWidget *, QListWidget *);
    void confrontation(int, int);

private slots:
    void on_back_clicked();
    void on_play_clicked();

private:
    QDialog *matchDialog;
    Ui::MatchInterface *ui;
    QMutex mutex;
    QWaitCondition sleepSimulator;

    bool locker;
    double value;
    int fixture; 
};

#endif // MATCHINTERFACE_H
