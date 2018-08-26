#ifndef ABAUT_H
#define ABAUT_H

#include <QDialog>

namespace Ui {
class Abaut;
}

class Abaut : public QDialog
{
    Q_OBJECT

public:
    explicit Abaut(QWidget *parent = 0);
    ~Abaut();

private:
    Ui::Abaut *ui;
};

#endif // ABAUT_H
