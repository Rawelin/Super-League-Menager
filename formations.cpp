#include "formations.h"

Formations::Formations()
{

}

void Formations::formation442(QTableWidget *tableWidget, QStringList titles)
{
    for(int i = 0; i < titles.size(); ++i)
        tableWidget->item(0, i)->setBackground(QColor(255, 255, 0, 50));
    for(int j = 1; j <= 4; ++j)
        for(int i = 0; i < titles.size(); ++i)
        tableWidget->item(j, i)->setBackground(QColor(0, 255, 0, 50));
    for(int j = 5; j <= 8; ++j)
        for(int i = 0; i < titles.size(); ++i)
        tableWidget->item(j, i)->setBackground(QColor(0, 0, 255, 50));
    for(int j = 9; j <= 10; ++j)
        for(int i = 0; i < titles.size(); ++i)
            tableWidget->item(j, i)->setBackground(QColor(255, 0, 0, 50));
  /*  for(int j = 11; j <= 16; ++j)
        for(int i = 0; i < titles.size(); ++i)
           tableWidget->item(j, i)->setBackground(Qt::lightGray);*/
}

void Formations::formation433(QTableWidget *tableWidget, QStringList titles)
{
    for(int i = 0; i < titles.size(); ++i)
        tableWidget->item(0, i)->setBackground(QColor(255, 255, 0, 50));
    for(int j = 1; j <= 4; ++j)
        for(int i = 0; i < titles.size(); ++i)
            tableWidget->item(j, i)->setBackground(QColor(0, 255, 0, 50));
    for(int j = 5; j <= 7; ++j)
        for(int i = 0; i < titles.size(); ++i)
            tableWidget->item(j, i)->setBackground(QColor(0, 0, 255, 50));
    for(int j = 8; j <= 10; ++j)
        for(int i = 0; i < titles.size(); ++i)
            tableWidget->item(j, i)->setBackground(QColor(255, 0, 0, 50));
  /*  for(int j = 11; j <= 16; ++j)
        for(int i = 0; i < titles.size(); ++i)
            tableWidget->item(j, i)->setBackground(Qt::lightGray);*/
}

void Formations::formation352(QTableWidget *tableWidget, QStringList titles)
{
    for(int i = 0; i < titles.size(); ++i)
        tableWidget->item(0, i)->setBackground(QColor(255, 255, 0, 50));
    for(int j = 1; j <= 3; ++j)
        for(int i = 0; i < titles.size(); ++i)
        tableWidget->item(j, i)->setBackground(QColor(0, 255, 0, 50));
    for(int j = 4; j <= 8 ; ++j)
        for(int i = 0; i < titles.size(); ++i)
        tableWidget->item(j, i)->setBackground(QColor(0, 0, 255, 50));
    for(int j = 9; j <= 10; ++j)
        for(int i = 0; i < titles.size(); ++i)
         tableWidget->item(j, i)->setBackground(QColor(255, 0, 0, 50));
  /*  for(int j = 11; j <= 16; ++j)
        for(int i = 0; i < titles.size(); ++i)
            tableWidget->item(j, i)->setBackground(Qt::lightGray);*/
}
