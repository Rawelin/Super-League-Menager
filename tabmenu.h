#ifndef TABMENU_H
#define TABMENU_H

#include <QDialog>
#include "table.h"

namespace Ui {
class TabMenu;
}

class TabMenu : public QDialog
{
    Q_OBJECT

public:
    explicit TabMenu(QWidget *parent = 0);
    ~TabMenu();

private slots:
    void on_tabWidget_destroyed();

    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::TabMenu *ui;
};

#endif // TABMENU_H
