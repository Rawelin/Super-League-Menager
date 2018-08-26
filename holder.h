#ifndef HOLDER_H
#define HOLDER_H

#include <QDialog>

namespace Ui {
class Holder;
}

class Holder : public QDialog
{
    Q_OBJECT

public:
    explicit Holder(QWidget *parent = 0);
    ~Holder();

private:
    Ui::Holder *ui;
};

#endif // HOLDER_H
