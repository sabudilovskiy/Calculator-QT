#ifndef SUPPORT_H
#define SUPPORT_H
#include <QString>
#include <stack>
#include <queue>
#include <stdexcept>
bool is_operand(QChar ch){
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
bool is_operand(const QString& str){
    return str == "+" || str == '-' || str == '*' || str == '/';
}
bool is_digit(QChar ch){
    return '0' <= ch && ch <= '9';
}

enum PRIORITIES_OPS{
    PLUS_MINUS, DIV_MULT
};

int get_priority(QChar operand){
    if (operand == '+' || operand == '-') return PLUS_MINUS;
    else if (operand == '*' || operand == '/') return DIV_MULT;
    else throw std::invalid_argument("");
}
int get_priority(const QString& operand){
    if (operand == "+" || operand == "-") return PLUS_MINUS;
    else if (operand == "*" || operand == "/") return DIV_MULT;
    else throw std::invalid_argument("");
}
QString postfix_answer(std::queue<QString> postfix){
    std::stack<double> stack;
    while (!postfix.empty()){
        QString cur = postfix.front();
        postfix.pop();
        if (is_operand(cur)){
            double right_value = stack.top();
            stack.pop();
            double left_value = stack.top();
            stack.pop();
            if (cur == "+"){
                stack.push(left_value+right_value);
            }
            else if (cur == "-"){
                stack.push(left_value-right_value);
            }
            else if (cur == "*"){
                stack.push(left_value*right_value);
            }
            else if (cur == "/"){
                stack.push(left_value/right_value);
            }
            else throw std::invalid_argument("");
        }
        else{
            stack.push(cur.toDouble());
        }
    }
    return QString::number(stack.top());
}
QString answer(QString task){
    int i = 0;
    int n = task.length();
    std::queue<QString> lexemes;
    while (i < n){
        if (is_digit(task[i])){
            QString temp;
            temp.append(task[i]);
            ++i;
            while (i < n && (is_digit(task[i]) || task[i] == '.')){
                temp.append(task[i]);
                ++i;
            }
            lexemes.push(std::move(temp));
        }
        else if (is_operand(task[i]) || task[i] == '(' || task[i] == ')'){
            lexemes.emplace(task[i]);
            ++i;
        }
        else throw std::invalid_argument("");
    }
    //transform to postfix
    std::queue<QString> postfix;
    std::stack<QString> ops;
    while (!lexemes.empty())
    {
        QString temp = lexemes.front();
        lexemes.pop();
        if (is_operand(temp)){
            int prior = get_priority(temp);
            while (!ops.empty() && (ops.top() != "(" && get_priority(ops.top()) >= prior)){
                postfix.push(ops.top());
                ops.pop();
            }
            ops.push(std::move(temp));
        }
        else if (temp == "("){
            ops.push(std::move(temp));
        }
        else if (temp == ')'){
            while (ops.top() != "("){
                postfix.push(ops.top());
                ops.pop();
            }
            ops.pop();
        }
        else{
            postfix.push(std::move(temp));
        }
    }
    while (!ops.empty()){
        postfix.push(ops.top());
        ops.pop();
    }
    return postfix_answer(std::move(postfix));
}



#endif // SUPPORT_H
