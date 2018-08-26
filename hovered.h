#ifndef HOVERED_H
#define HOVERED_H

#include <QDialog>
#include <QMouseEvent>
#include <QEvent>
#include <QtWidgets>

namespace Ui {
class Hovered;
}

class Hovered : public QDialog
{
    Q_OBJECT

public:
    explicit Hovered(QWidget *parent = 0);
    ~Hovered();

    void setHighLight(QRect, QPushButton *, QString &, QString &);

private:
    Ui::Hovered *ui;

protected:
     void mouseMoveEvent(QMouseEvent *event);

public: Q_SIGNALS:
    void hovered();
};

#endif // HOVERED_H
