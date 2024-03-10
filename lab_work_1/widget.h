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

class StrValidator:public QValidator // наследуемся от класса валидатора, для проверки корректности данных(функция validate может быть использована
//только у наследуемого класса)
{
public:
    StrValidator(QObject *parent):QValidator(parent){}  //указываем родителя, который будет потом удалять этот объект
    virtual State validate(QString &str,int &pos)const // виртуальная функция у класса QValidate (state- тип возвращаемого значения),
        //чтобы воспользоваться validate - ее нужно определить у наследуемого класса
    {
        return Acceptable;
    }
};
#endif // WIDGET_H
