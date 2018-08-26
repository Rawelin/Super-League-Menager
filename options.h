#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include "mainmenu.h"
#include "edit.h"

namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = 0);
    ~Options();

private slots:
    void on_mainmenu_clicked();
    void on_edit_clicked();

private:
    Ui::Options *ui;
   // QPalette *palette;
};

#endif // OPTIONS_H
