#ifndef WIDGET_H
#define WIDGET_H
#include <QtGui>
#include <iostream>
#include "area.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Widget : public QWidget
{
protected:
    QPushButton *exitButton;
    area *myarea;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};

#endif // WIDGET_H
