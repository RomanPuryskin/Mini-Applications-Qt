#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent)
{
    setWindowTitle("Counter");
    label1 = new QLabel("Counter by 1",this);
    label2 = new QLabel("Counter by 2",this);
    edit1 = new Counter("0",this);
    edit2 = new Counter("0",this);
    calcButton = new QPushButton("+1" , this);
    exitButton = new QPushButton("Exit",this);

    QHBoxLayout *layout1 = new QHBoxLayout();
    layout1->addWidget(label1);
    layout2->addWidget(label2);

    QHBoxLayout *layout2 = new QHBoxLayout();
    layout2->addWidget(edit1);
    layout2->addWidget(edit1);

    QHBoxLayout *layout3 = new QHBoxLayout();
    layout3->addWidget(calcButton);
    layout3->addWidget(exitButton);

    QVBoxLayout *layout4 = new QVBoxLayout(this);
    layout4->addLayout(layout1);
    layout4->addLayout(layout2);
    layout4->addLayout(layout3);
}

Widget::~Widget()
{
}

