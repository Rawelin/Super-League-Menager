#ifndef FIXTURE_H
#define FIXTURE_H

#include <QDialog>
#include "container.h"
#include "league.h"
#include "versus.h"

namespace Ui {
class Fixture;
}

class Fixture : public QDialog
{
    Q_OBJECT

public:
    explicit Fixture(QWidget *parent = 0);
    ~Fixture();
    void setGraphic();
    void setFixture();

private:
    Ui::Fixture *ui;
    int fixture_number;
    int p1;
    int p2;

private slots:
    void next();
    void previous();
    void on_back_clicked();
};

#endif // FIXTURE_H
