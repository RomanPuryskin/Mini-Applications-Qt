#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFrame>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QValidator>
#include <math.h>
class Widget : public QWidget  // наследуемся от базового класса
{
    Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов
protected:
    QFrame *frame; // рамка, в которой будут находиться editLine's
    QLineEdit *inputEdit; // поле ввода
    QLabel *outputLabel; // лейбл с текстом вывода
    QLineEdit *outputEdit; // поле вывода
    QPushButton *nextButton; // кнопка Следующее
    QPushButton *exitButton; // кнопка Выход
public:
    Widget(QWidget *parent = nullptr); // Наш класс widget не имеет родителей, он сам является родителем для будущих виджетов
public slots:
    void begin();
    void calc();
};

class StrValidator:public QValidator // наследуемся от класса валидатора, для проверки корректности данных
{
public:
    StrValidator(QObject *parent):QValidator(parent){}  //Qвалидатор принимает объект класса Qobject (в нашем случае lineEdit)
    virtual State validate(QString &str,int &pos)const // при завершении ввода метод вызывается автоматически
    {
        return Acceptable;
    }
};
#endif // WIDGET_H
