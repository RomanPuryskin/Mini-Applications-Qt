#ifndef AREA_H
#define AREA_H
#include "figure.h"
#include <QPaintEvent>
#include <QTimerEvent>
#include <QShowEvent>
#include <QHideEvent>

class area : public QWidget
{
public:
    area(QWidget *parent = nullptr);
    ~area();
    MyLine *myline;
    MyRect *myrect;
    int myTimer;
    float alpha; //угол поворота
protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent (QHideEvent *event);
};

#endif // AREA_H
