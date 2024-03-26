#include "area.h"
area::area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200));
    myline = new MyLine(80,100,50);
    myrect = new MyRect(220,100,50);
    alpha = 0;
}

void area::showEvent(QShowEvent *)
{
    myTimer = startTimer(50);
}

void area::paintEvent(QPaintEvent *)
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
        update();
    }

    else
        QWidget::timerEvent(event);
}

void area::hideEvent(QHideEvent *)
{
    killTimer(myTimer);
}

area::~area()
{
    delete myline;
    delete myrect;
}
