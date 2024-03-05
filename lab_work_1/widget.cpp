#include "widget.h"

Widget::Widget(QWidget *parent):QWidget(parent)
{
    setWindowTitle("Squaring");
    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);
    inputLabel = new QLabel("Enter a number:");
    inputEdit = new QLineEdit("",this);
    StrValidator *v=new StrValidator(inputEdit);
    inputEdit->setValidator(v);
    outputLabel = new QLabel("Result:");
    outputEdit = new QLineEdit("",this);
    nextButton = new QPushButton("Next");
    exitButton = new QPushButton("Exit");

    // компоновка приложения
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();
    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);

    begin();

    connect(exitButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(nextButton,SIGNAL(clicked(bool)),this,SLOT(begin()));
    connect(inputEdit,SIGNAL(returnPressed()),this,SLOT(calc()));
}

void Widget::begin()
{
    inputEdit->clear();
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}

void Widget::calc()
{
    bool Ok = true;
    float r,a;
    QString str = inputEdit->text();
    a=str.toDouble(&Ok);
    if (Ok)
    {
        r=a*a;
        str.setNum(r);
        outputEdit->setText(str);
        inputEdit->setEnabled(false);
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else
        if (!str.isEmpty())
        {
            QMessageBox msgBox(QMessageBox::Information,
                               ("Возведение в квадрат."),
                               ("Введено неверное значение."),
                               QMessageBox::Ok);
        msgBox.exec();
    }
}
