#ifndef DATA_H
#define DATA_H

#include <QDialog>
#include "stats.h"
#include "topscorer.h"

namespace Ui {
class Data;
}

class Data : public QDialog
{
    Q_OBJECT

public:
    explicit Data(QWidget *parent = 0);
    ~Data();
    void setGraphics();

private slots:
    void on_back_clicked();
    void on_topscorers_clicked();
    void on_stats_clicked();

private:
    Ui::Data *ui;
};

#endif // DATA_H
