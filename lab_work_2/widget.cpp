#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent)
{
    setWindowTitle("Counter");
    label1 = new QLabel("Counter by 1",this);
    label2 = new QLabel("Counter by 5",this);
    edit1 = new Counter("0",this);
    edit2 = new Counter("0",this);
    calcButton = new QPushButton("+1" , this);
    exitButton = new QPushButton("Exit",this);

    QHBoxLayout *layout1 = new QHBoxLayout();
    QHBoxLayout *layout2 = new QHBoxLayout();
    QHBoxLayout *layout3 = new QHBoxLayout();
    QVBoxLayout *layout4 = new QVBoxLayout(this);

    if(layout1 && layout2 && layout3 && layout4)
    {
        layout1->addWidget(label1);
        layout1->addWidget(label2);
        layout2->addWidget(edit1);
        layout2->addWidget(edit2);
        layout3->addWidget(calcButton);
        layout3->addWidget(exitButton);
        layout4->addLayout(layout1);
        layout4->addLayout(layout2);
        layout4->addLayout(layout3);

    }
    else
    {
        QMessageBox msgBox(QMessageBox::Information,
                           ("Счетчик."),
                           ("Ошибка выделения памяти под объекты."),
                           QMessageBox::Ok);
        msgBox.exec();
    }

    connect(exitButton,&QPushButton::clicked,this,&Counter::close);
    connect(calcButton,&QPushButton::clicked,edit1,&Counter::add_one);
    connect(edit1,&Counter::tick_signal,edit2,&Counter::add_one);
}

Widget::~Widget()
{
}

