#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class Widget : public QWidget
{
    Q_OBJECT
protected:
    QLabel *label1,*label2;
    QPushButton *calcButton,*exitButton;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};

class Counter : public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & text , QWidget *parent = nullptr):QLineEdit(Text,parent){}
signals:
    void tick_signal();
public slots:
    void add_one()
    {
        QString str = text();
        int r = str.toInt();
        if (r!=0 && r%5 == 0)
            emit tick_signal();
        r++;
        str.setNum(r);
        setText(str);
    }
};

#endif // WIDGET_H
