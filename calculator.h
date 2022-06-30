#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject
{
    Q_OBJECT
private:
    QString input;
    int open_brackets = 0;
public:
    explicit Calculator(QObject *parent = nullptr);
signals:
    void change_input(const QString& new_input);
public slots:
    void add_digit(QChar digit);
    void add_operand(QChar operand);
    void add_left_bracket();
    void add_right_bracket();
    void get_answer();
    void add_point();
    void clear();
    void remove();
};

#endif // CALCULATOR_H
