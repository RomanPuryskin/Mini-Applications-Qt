#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent)
{
    setWindowTitle("Events");
    exitButton = new QPushButton("Завершить",this);
    myarea = new area(this);
    QVBoxLayout *layout1 = new QVBoxLayout(this);
    QHBoxLayout *layout2 = new QHBoxLayout();
    if(!layout1 || !layout2)
    {
        std::cerr<<"memory allocate error";
    }
    else
    {
        layout2->addWidget(myarea);
        layout1->addLayout(layout2);
        layout1->addWidget(exitButton);
    }

    connect(exitButton,&QPushButton::clicked,this,&Widget::close);
}

Widget::~Widget(){}

