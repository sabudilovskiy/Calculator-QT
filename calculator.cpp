#include "calculator.h"
#include "support.h"
Calculator::Calculator(QObject *parent)
    : QObject{parent}
{

}


void Calculator::add_digit(QChar digit)
{
    if (is_digit(digit)){
        input.append(digit);
        emit change_input(input);
    }
}

void Calculator::add_operand(QChar operand)
{
    if (input.length() > 0){
        QChar last_symbol = input[input.length() - 1];
        if ((is_operand(operand)) && (last_symbol == ')' || is_digit(last_symbol))){
            input.append(operand);
            emit change_input(input);
        }
    }
}

void Calculator::add_left_bracket()
{
    if (input.isEmpty() || is_operand(input[input.length() - 1] ))
    {
        input.append('(');
        open_brackets++;
        emit change_input(input);
    }
}

void Calculator::add_right_bracket()
{
    QChar last_symbol = input[input.length() - 1];
    if (open_brackets>0 && (last_symbol == ')' || is_digit(last_symbol)))
    {
         input.append(')');
         open_brackets--;
         emit change_input(input);
    }
}

void Calculator::get_answer()
{
    input = answer(input);
    emit change_input(input);
}

void Calculator::add_point()
{
    QChar last_symbol = input[input.length() - 1];
    if (is_digit(last_symbol)){
        int i = input.length() - 1;
        while (i >= 0 && is_digit(input[i])){
            --i;
        }
        if (i < 0 || input[i] != '.'){
            input.append('.');
            emit change_input(input);
        }
    }

}

void Calculator::clear()
{
    input.clear();
    emit change_input(input);
}

void Calculator::remove()
{
    if (input.length() > 0){
        QChar last_symbol = input[input.length() - 1];
        if (last_symbol == ')'){
            open_brackets++;
        }
        else if (last_symbol == '('){
            open_brackets--;
        }
        input.erase(input.begin() + input.length() - 1, input.end());
        emit change_input(input);
    }
}
