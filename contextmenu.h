#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H

#include <QDialog>

namespace Ui {
class ContextMenu;
}

class ContextMenu : public QDialog
{
    Q_OBJECT

public:
    explicit ContextMenu(QWidget *parent = 0, const QString txt = "Text");
    ~ContextMenu();

private:
    Ui::ContextMenu *ui;
    QString text;
};

#endif // CONTEXTMENU_H
