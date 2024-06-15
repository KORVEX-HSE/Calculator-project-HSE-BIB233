/*!
 * \file
 * \brief Файл с описаниями функций окна истории вычислений
 * Данный файл содержит в себе описания функций окна истории вычислений
*/



#include "storywindow.h"
#include "ui_storywindow.h"
#include "count.h"



/*!
 * \brief Конструктор экземпляра класса MainWindow
 * \param parent
 */
StoryWindow::StoryWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StoryWindow)
{
    ui->setupUi(this);
}



/*!
 * \brief Деструктор экземпляра класса MainWindow
 */
StoryWindow::~StoryWindow()
{
    delete ui;
}



/*!
 * \brief Функция, связывающая физическую клавиатуру с кнопками графического интерфейса
 * \param es Событие нажатия на клавишу клавиатуры
 */
void StoryWindow::keyPressEvent(QKeyEvent *es)
{
    if (es->key() == Qt::Key_Alt)
        close();
}




/*!
 * \brief Слот, утранавливающий в лейблы окна истории вычислений результаты последних 6 вычислений
 * \param story_first_num Первое число в вычислении
 * \param story_operation Операция вычисления
 * \param story_second_num Второе число в вычислении
 * \param story_equal_num Результат вычисления
 */
void StoryWindow::slot(std::deque<double> story_first_num, std::deque<char> story_operation, std::deque<double> story_second_num, std::deque<double> story_equal_num)
{
    ui->label_1->setText(calcul(0, story_first_num, story_operation, story_second_num, story_equal_num));
    ui->label_2->setText(calcul(1, story_first_num, story_operation, story_second_num, story_equal_num));
    ui->label_3->setText(calcul(2, story_first_num, story_operation, story_second_num, story_equal_num));
    ui->label_4->setText(calcul(3, story_first_num, story_operation, story_second_num, story_equal_num));
    ui->label_5->setText(calcul(4, story_first_num, story_operation, story_second_num, story_equal_num));
    ui->label_6->setText(calcul(5, story_first_num, story_operation, story_second_num, story_equal_num));
}
