#include "mainwindow.h"
#include <QtWidgets>
#include "calculator.h"
int main(int argc, char *argv[])
{
    Calculator calculator;
    QApplication app(argc, argv);
    MainWindow main_window;
    main_window.show();
    QObject::connect(&main_window, SIGNAL(add_digit(QChar)),
                     &calculator, SLOT(add_digit(QChar)));
    QObject::connect(&main_window, SIGNAL(add_operand(QChar)),
                     &calculator, SLOT(add_operand(QChar)));
    QObject::connect(&main_window, SIGNAL(add_left_bracket()),
                     &calculator, SLOT(add_left_bracket()));
    QObject::connect(&main_window, SIGNAL(add_right_bracket()),
                     &calculator, SLOT(add_right_bracket()));
    QObject::connect(&main_window, SIGNAL(add_point()),
                     &calculator, SLOT(add_point()));
    QObject::connect(&main_window, SIGNAL(remove()),
                     &calculator, SLOT(remove()));
    QObject::connect(&main_window, SIGNAL(clear()),
                     &calculator, SLOT(clear()));
    QObject::connect(&main_window, SIGNAL(get_answer()),
                     &calculator,SLOT(get_answer()));
    QObject::connect(&calculator, SIGNAL(change_input(const QString&)),
                     &main_window, SLOT(on_label_windowTitleChanged(const QString&)));
    return app.exec();
}
