#include "mainwindow.h"
#include <QMessageBox>
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_0_clicked()
{
    emit add_digit('0');
}
void MainWindow::on_pushButton_1_clicked()
{
    emit add_digit('1');
}
void MainWindow::on_pushButton_2_clicked()
{
    emit add_digit('2');
}
void MainWindow::on_pushButton_3_clicked()
{
    emit add_digit('3');
}
void MainWindow::on_pushButton_4_clicked()
{
    emit add_digit('4');
}
void MainWindow::on_pushButton_5_clicked()
{
    emit add_digit('5');
}

void MainWindow::on_pushButton_6_clicked()
{
    emit add_digit('6');
}

void MainWindow::on_pushButton_7_clicked()
{
    emit add_digit('7');
}

void MainWindow::on_pushButton_8_clicked()
{
    emit add_digit('8');
}

void MainWindow::on_pushButton_9_clicked()
{
    emit add_digit('9');
}

void MainWindow::on_pushButton_plus_clicked()
{
    emit add_operand('+');
}

void MainWindow::on_pushButton_minus_clicked()
{
    emit add_operand('-');
}

void MainWindow::on_pushButton_div_clicked()
{
    emit add_operand('/');
}

void MainWindow::on_pushButton_mult_clicked()
{
    emit add_operand('*');
}

void MainWindow::on_pushButton_left_br_clicked()
{
    emit add_left_bracket();
}

void MainWindow::on_pushButton_right_br_clicked()
{
    emit add_right_bracket();
}

void MainWindow::on_pushButton_point_clicked()
{
    emit add_point();
}

void MainWindow::on_pushButton_remove_clicked()
{
    emit remove();
}

void MainWindow::on_pushButton_clear_clicked()
{
    emit clear();
}

void MainWindow::on_pushButton_eq_clicked()
{
    emit get_answer();
}

void MainWindow::on_label_windowTitleChanged(const QString &title)
{
    this->ui->label->setText(title);
}

