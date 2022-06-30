#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_div_clicked();
    void on_pushButton_mult_clicked();
    void on_pushButton_left_br_clicked();
    void on_pushButton_right_br_clicked();
    void on_pushButton_point_clicked();
    void on_pushButton_remove_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_eq_clicked();
    void on_label_windowTitleChanged(const QString &title);

private:
    Ui::MainWindow *ui;
public: signals:
    void add_digit(QChar digit);
    void add_operand(QChar operand);
    void add_left_bracket();
    void add_right_bracket();
    void get_answer();
    void add_point();
    void remove();
    void clear();
};
#endif // MAINWINDOW_H
