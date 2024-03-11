#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent)
{
    setWindowTitle("Events");
    exitButton = new QPushButton("Завершить",this);
    QVBoxLayout *layout1 = new QVBoxLayout(this);
    layout1->addWidget(exitButton);
    connect(exitButton,&QPushButton::clicked,this,&Widget::close);
}

Widget::~Widget()
{
}

