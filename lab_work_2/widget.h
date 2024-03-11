#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
class Counter : public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString &text , QWidget *parent = nullptr):QLineEdit(text,parent){}
signals:
    void tick_signal();
public slots:
    void add_one()
    {
        QString str = text();
        int r = str.toInt();
        r++;
        if (r!=0 && r%5 == 0)
            emit tick_signal();

        str.setNum(r);
        setText(str);
    }
};

class Widget : public QWidget
{
    Q_OBJECT
protected:
    QLabel *label1,*label2;
    QPushButton *calcButton,*exitButton;
    Counter *edit1,*edit2;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};



#endif // WIDGET_H
