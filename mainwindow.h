/*!
 * \file
 * \brief Заголовочный файл с описанием класса главного окна
 * Данный файл содержит в себе определение класса главного окна
*/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "storywindow.h"
#include <QKeyEvent>
#include <deque>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *e) override;

private:
    Ui::MainWindow *ui;
    StoryWindow *story;

private slots:
    void digits_numbers();
    void on_pushButton_dot_clicked();
    void on_pushButton_sign_clicked();
    void operations();
    void on_pushButton_equal_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_story_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_mc_clicked();

    void on_pushButton_ms_clicked();

    void on_pushButton_mr_clicked();

    void on_pushButton_mplus_clicked();

    void on_pushButton_mmin_clicked();

    void on_pushButton_clear_all_clicked();

signals:
    void signal(std::deque<double>, std::deque<char>, std::deque<double>, std::deque<double>);
};
#endif // MAINWINDOW_H
