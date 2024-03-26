#ifndef AREA_H
#define AREA_H
#include <QWidget>
#include "figure.h"

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
    // события QWidget(кроме timerEvent)
    void paintEvent(QPaintEvent *event); //обработчик события перерисовки, вызывается при создании виджета
    virtual void timerEvent(QTimerEvent *event); // метод QObject
    void showEvent(QShowEvent *event); // событие , непосредственно перед тем как виджет становится видимым
    void hideEvent (QHideEvent *event); //событие скрытия, отправляется виджетам сразу после скрытия
};

#endif // AREA_H
