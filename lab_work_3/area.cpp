#include "area.h"
area::area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200));
    myline = new MyLine(80,100,50);
    myrect = new MyRect(220,100,50);
    alpha = 0;
}

void area::showEvent(QShowEvent *event)
{
    myTimer = startTimer(50); // метод QObject запускает таймер и возварщает его идентификатор
}

void area::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    myline->move(alpha,&painter);
    myrect->move(alpha*(-0.5),&painter);
}

void area::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == myTimer)
    {
        alpha += 0.2;
        update(); // не перерисовывает заново, а планирует событие рисования
    }
}

void area::hideEvent(QHideEvent *event)
{
    killTimer(myTimer);
}

area::~area()
{
    delete myline;
    delete myrect;
}
