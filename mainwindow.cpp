/*!
 * \file
 * \brief Файл с описаниями функций главного окна
 * Данный файл содержит в себе описания функций главного окна
*/



#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <deque>
#include "count.h"



double num_first; ///< Глобальная переменная, хранящая первый номер при вызове бинарной операции
int show_size = 15; ///< Глобальная переменная, определяющая количество цифр, до перехода в экспоненциальную нотацию
std::deque<double> story_first_num(6); ///< Глобальный дек, содержащий первые номера в операциях
std::deque<char> story_operation(6); ///< Глобальный дек, содержащий информацию об операции
std::deque<double> story_second_num(6); ///< Глобальный дек, содержащий вторые номера в операциях
std::deque<double> story_equal_num(6); ///< Глобальный дек, содержащий результаты операций
double memory = 0; ///< Глобальная переменная, хранящая число, сохраненное в память калькулятора



/*!
 * \brief Конструктор экземпляра класса MainWindow
 * \param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    story = new StoryWindow(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_root, SIGNAL(clicked()), this, SLOT(operations()));

    connect(this, &MainWindow::signal, story, &StoryWindow::slot);

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_mul->setCheckable(true);
    ui->pushButton_div->setCheckable(true);
    ui->pushButton_pow->setCheckable(true);
    ui->pushButton_root->setCheckable(true);
}



/*!
 * \brief Деструктор экземпляра класса MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}



/*!
 * \brief Функция, связывающая физическую клавиатуру с кнопками графического интерфейса
 * \param e Событие нажатия на клавишу клавиатуры
 */
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_0)
        ui->pushButton_0->click();
    else if (e->key() == Qt::Key_1)
        ui->pushButton_1->click();
    else if (e->key() == Qt::Key_2)
        ui->pushButton_2->click();
    else if (e->key() == Qt::Key_3)
        ui->pushButton_3->click();
    else if (e->key() == Qt::Key_4)
        ui->pushButton_4->click();
    else if (e->key() == Qt::Key_5)
        ui->pushButton_5->click();
    else if (e->key() == Qt::Key_6)
        ui->pushButton_6->click();
    else if (e->key() == Qt::Key_7)
        ui->pushButton_7->click();
    else if (e->key() == Qt::Key_8)
        ui->pushButton_8->click();
    else if (e->key() == Qt::Key_9)
        ui->pushButton_9->click();
    else if (e->key() == Qt::Key_0)
        ui->pushButton_0->click();
    else if (e->key() == Qt::Key_Plus)
        ui->pushButton_plus->click();
    else if (e->key() == Qt::Key_Minus)
        ui->pushButton_minus->click();
    else if (e->key() == Qt::Key_Asterisk)
        ui->pushButton_mul->click();
    else if (e->key() == Qt::Key_Slash)
        ui->pushButton_div->click();
    else if (e->key() == Qt::Key_AsciiCircum)
        ui->pushButton_pow->click();
    else if (e->key() == Qt::Key_NumberSign)
        ui->pushButton_root->click();
    else if (e->key() == Qt::Key_Exclam)
        ui->pushButton_sign->click();
    else if (e->key() == Qt::Key_Period)
        ui->pushButton_dot->click();
    else if (e->key() == Qt::Key_Enter)
        ui->pushButton_equal->click();
    else if (e->key() == Qt::Key_Backspace)
        ui->pushButton_del->click();
    else if (e->key() == Qt::Key_Delete)
        ui->pushButton_clear->click();
    else if (e->key() == Qt::Key_Escape)
        ui->pushButton_clear_all->click();
    else if (e->key() == Qt::Key_Alt)
        ui->pushButton_story->click();
    else if (e->key() == Qt::Key_F1)
        ui->pushButton_mc->click();
    else if (e->key() == Qt::Key_F2)
        ui->pushButton_ms->click();
    else if (e->key() == Qt::Key_F3)
        ui->pushButton_mr->click();
    else if (e->key() == Qt::Key_F4)
        ui->pushButton_mplus->click();
    else if (e->key() == Qt::Key_F5)
        ui->pushButton_mmin->click();
}



/*!
 * \brief Слот, обрабатывающий сигнал нажатия кнопок цифр от 0 до 9
 */
void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers; ///< Переменная, в которую записываются числа с экрана + введенное число
    QString new_label; ///< Переменная, в которую записывается переменная [all_numpers] для вывода на экран

    if (ui->result_show->text().contains(".") && button->text() == "0")
    {
        new_label = ui->result_show->text() + button->text();
    }
    else
    {
        all_numbers = (ui->result_show->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', show_size);
    }
    ui->result_show->setText(new_label);
}



/*!
 * \brief Слот, обрабатывающий сигнал нажатия кнопки "точка"
 */
void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->result_show->text().contains(".")))
        ui->result_show->setText(ui->result_show->text() + ".");
}



/*!
 * \brief Слот, обрабатывающий сигнал нажатия кнопки "смена знака"
 */
void MainWindow::on_pushButton_sign_clicked()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers; ///< Переменная, в которую записываются числа с экрана
    QString new_label; ///< Переменная, в которую записывается переменная [all_numpers] для вывода на экран

    if (button->text() == "+/-")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers *= -1;
        new_label = QString::number(all_numbers, 'g', show_size);
    }
    ui->result_show->setText(new_label);
}



/*!
 * \brief Слот, обрабатывающий сигнал нажатия кнопок операций
 * Операции:
 * -- "+" операция сложения
 * -- "-" операция вычитания
 * -- "*" операция умножения
 * -- "/" операция деления
 * -- "^" операция возведения в степень
 * -- "#" операция взятия корня n-ой степени
 */
void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender(); ///< Объект кнопки

    num_first = ui->result_show->text().toDouble();
    story_first_num.push_front(num_first);
    story_first_num.pop_back();
    ui->result_show->setText("");
    button->setChecked(true);
}



/*!
 * \brief Слот, обрабатывающий сигнал нажатия кнопки "равно"
 */
void MainWindow::on_pushButton_equal_clicked()
{
    double num_second = 0; ///< Переменная, хранящая второй номер при вызове бинарной операции
    char opera = '?'; ///< Переменная, в которую записывается тип операции
    QString new_label; ///< Переменная, в которую записывается переменная [all_numpers] для вывода на экран

    num_second = ui->result_show->text().toDouble();
    story_second_num.push_front(num_second);
    story_second_num.pop_back();

    if (ui->pushButton_plus->isChecked())
    {
        opera = '+';
        ui->pushButton_plus->setChecked(false);
    }
    else if (ui->pushButton_minus->isChecked())
    {
        opera = '-';
        ui->pushButton_minus->setChecked(false);
    }
    else if (ui->pushButton_mul->isChecked())
    {
        opera = '*';
        ui->pushButton_mul->setChecked(false);
    }
    else if (ui->pushButton_div->isChecked())
    {
        opera = '/';
        ui->pushButton_div->setChecked(false);
    }
    else if (ui->pushButton_pow->isChecked())
    {
        opera = '^';
        ui->pushButton_pow->setChecked(false);
    }
    else if (ui->pushButton_root->isChecked())
    {
        opera = '#';
        ui->pushButton_root->setChecked(false);
    }
    new_label = counter(num_first, opera, num_second, &story_operation, &story_equal_num, show_size);
    ui->result_show->setText(new_label);
    emit signal(story_first_num, story_operation, story_second_num, story_equal_num);
}



/*!
 * \brief Слот, обрабатывающий сигнал нажатия кнопки "очистить"
 */
void MainWindow::on_pushButton_clear_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_mul->setChecked(false);
    ui->pushButton_div->setChecked(false);
    ui->pushButton_pow->setChecked(false);
    ui->pushButton_root->setChecked(false);
    ui->result_show->setText("0");
}



/*!
 * \brief Слот, обрабатывающий сигнал нажатия кнопки "очистить все"
 */
void MainWindow::on_pushButton_clear_all_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_mul->setChecked(false);
    ui->pushButton_div->setChecked(false);
    ui->pushButton_pow->setChecked(false);
    ui->pushButton_root->setChecked(false);
    ui->result_show->setText("0");
    memory = 0;
}



/*!
 * \brief Слот, обрабатывающий сигнал нажатия кнопки "история"
 */
void MainWindow::on_pushButton_story_clicked()
{
    emit signal(story_first_num, story_operation, story_second_num, story_equal_num);
    if (story->isActiveWindow() == true)
        story->close();
    else
        story->open();
}



/*!
 * \brief Слот, обрабатывающий сигнал нажатия кнопки "удалить символ"
 */
void MainWindow::on_pushButton_del_clicked()
{
    ui->result_show->setText(ui->result_show->text().remove(-1, 1));
}



/*!
 * \brief Слот, обрабатывающий сигнал нажатия кнопки "очистка памяти"
 */
void MainWindow::on_pushButton_mc_clicked()
{
    memory = 0;
}



/*!
 * \brief Слот, обрабатывающий сигнал нажатия кнопки "сохранить в память"
 */
void MainWindow::on_pushButton_ms_clicked()
{
    memory = (ui->result_show->text()).toDouble();
}



/*!
 * \brief Слот, обрабатывающий сигнал нажатия кнопки "вывести на экран из памяти"
 */
void MainWindow::on_pushButton_mr_clicked()
{
    ui->result_show->setText(QString::number(memory, 'g', show_size));
}



/*!
 * \brief Слот, обрабатывающий сигнал нажатия кнопки "добавить к памяти число на экране"
 */
void MainWindow::on_pushButton_mplus_clicked()
{
    memory += (ui->result_show->text()).toDouble();
}



/*!
 * \brief Слот, обрабатывающий сигнал нажатия кнопки "отнять из памяти число на экране"
 */
void MainWindow::on_pushButton_mmin_clicked()
{
    memory -= (ui->result_show->text()).toDouble();
}
