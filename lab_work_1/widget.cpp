#include "widget.h"
#include <typeinfo>
Widget::Widget(QWidget *parent):QWidget(parent)
{
    setWindowTitle("Squaring");
    frame = new QFrame(this);

    // Кастомизация пространства(рамки), где будут располагаться лэйауты
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);

    inputEdit = new QLineEdit;
    inputEdit->setPlaceholderText("Enter a number:");
    StrValidator *v=new StrValidator(inputEdit);
    inputEdit->setValidator(v); // привязываем наш валидатор к полю ввода числа
    outputLabel = new QLabel("Result:");
    outputEdit = new QLineEdit;
    nextButton = new QPushButton("Next");
    exitButton = new QPushButton("Exit");

    // компоновка лэйблов и полей ввода
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);// автоматическое выравнивание по вертикале лэйблов и полей ввода в рамке
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();//добавляем отступ
    //компановка кнопок
    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();
    // компановка компановок
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);

    begin();

    connect(exitButton,&QPushButton::clicked,this,&Widget::close); //связь нажатия кнопки закрытия и закрытия самого виджета
    connect(nextButton,&QPushButton::clicked,this,&Widget::begin); // связь нажатия кнопки next и запуск сигнала begin сначала
    connect(inputEdit,&QLineEdit::returnPressed,this,&Widget::calc);// связь завершения ввода числа и запуск сигнала calc
}

void Widget::begin()
{
    inputEdit->clear(); //поле ввода должно быть пустое в начале
    nextButton->setEnabled(false); // кнопка next не доступна, пока не завершили ввод и не получили результат
    nextButton->setDefault(false); // кнопка в данном моменте не является кнопкой по умолчанию
    inputEdit->setEnabled(true); // доступность поля ввода

    // лэйблы и поля результата скрыты
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);

    inputEdit->setFocus();// фокус клавиатуры в этом поле ввода
}

void Widget::calc()
{
    bool Ok = true;
    float r,a;
    bool overload = false;
    QString str = inputEdit->text();
    a=str.toDouble(&Ok); // если возникнет ошибка, то Ok установится в false для дальнейшей обработки ошибки

    if (abs(a) >= sqrt((3.4*pow(10,38))))  // проверка на переполнение
        overload = true;

    if (Ok && !overload)
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
    {
        if (!str.isEmpty() && !overload )
        {
            QMessageBox msgBox(QMessageBox::Information,
                               ("Возведение в квадрат."),
                               ("Введено неверное значение."),
                               QMessageBox::Ok);
            msgBox.exec();
        }

        else
        {
            QMessageBox msgBox(QMessageBox::Information,
                               ("Возведение в квадрат."),
                               ("Введено слишком большое значение."),
                               QMessageBox::Ok);
            msgBox.exec();
        }
    }
}
