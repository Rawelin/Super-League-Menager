#ifndef ABAUT_H
#define ABAUT_H

#include <QDialog>
#include <QtWidgets>

namespace Ui {
class Abaut;
}

class Abaut : public QDialog
{
    Q_OBJECT

public:
    explicit Abaut(QWidget *parent = 0);
    ~Abaut();
    void setGraphics();

private slots:
      void highLight();

private:
    Ui::Abaut *ui;


public: Q_SIGNALS:
     void hovered();

protected:
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // ABAUT_H
