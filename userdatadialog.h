#ifndef USERDATADIALOG_H
#define USERDATADIALOG_H

#include <QDialog>
#include "container.h"
#include "gamedialog.h"
#include "choseteam.h"

namespace Ui {
class UserDataDialog;
}

class UserDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDataDialog(QDialog *parent = 0);
    ~UserDataDialog();
    void setGraphic();

private slots:

    void on_play_clicked();
    void on_teamchoice_clicked();

private:
    QDialog *choseteam;
    Ui::UserDataDialog *ui;

};

#endif // USERDATADIALOG_H
