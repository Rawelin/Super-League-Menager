#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include "editchooseteam.h"
#include "options.h"

namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = 0);
    ~Edit();

private slots:
    void on_option_clicked();
    void on_add_clicked();
    void on_remove_clicked();
    void on_edit_clicked();

private:
    Ui::Edit *ui;
    QPalette *palette;
};

#endif // EDIT_H
