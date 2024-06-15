/*!
 * \file
 * \brief Файл с описаниями вычислительных функий
 */



#include <cmath>
#include <deque>
#include "qstring.h"



/*!
 * \brief Функция, проводящая вычисление и записывающая операцию вычисления и результат вычисления в соответствующие деки
 * \param num1 Первое число вычисления
 * \param opera Операция вычисления
 * \param num2 Второе число вычисления
 * \param story_operation Дек с операциями вычислений
 * \param story_equal_num Дек с результатами вычислений
 * \param show_size Глобальная переменная, определяющая количество цифр, до перехода в экспоненциальную нотацию
 * \return Возвращает строку QString с результатом вычисления
 */
QString counter(double num1, char opera, double num2, std::deque<char> * story_operation, std::deque<double> * story_equal_num, int show_size)
{
    double label_number = 0; ///< Переменная, в которую записывается результат вычисления
    switch (opera) {
    case '+':
        label_number = num1 + num2;
        break;
    case '-':
        label_number = num1 - num2;
        break;
    case '*':
        label_number = num1 * num2;
        break;
    case '/':
        label_number = num1 / num2;
        break;
    case '^':
        label_number = pow(num1, num2);
        break;
    case '#':
        label_number = pow(num1, 1/num2);
        break;
    default:
        label_number = 0;
        break;
    }
    story_operation->push_front(opera);
    story_operation->pop_back();
    story_equal_num->push_front(label_number);
    story_equal_num->pop_back();
    return QString::number(label_number, 'g', show_size);
}



/*!
 * \brief Функция, проверяющая операцию вычисления на валидность
 * \param operation Операция вычисления
 * \return Возвращает true или false
 */
bool valid_operation(char operation)
{
    switch (operation) {
    case '+':
        return true;
        break;
    case '-':
        return true;
        break;
    case '*':
        return true;
        break;
    case '/':
        return true;
        break;
    case '^':
        return true;
        break;
    case '#':
        return true;
        break;
    default:
        return false;
        break;
    }
}



/*!
 * \brief Функиция, связывающая данные из деков истории вычислений в строку QString
 * \param i Индекс номера вычисления
 * \param story_first_num Дек с первыми числами в вычислениях
 * \param story_operation Дек с операциями вычислений
 * \param story_second_num Дек со вторыми числами в вычислениях
 * \param story_equal_num Дек с результатами вычислений
 * \return Возвращает строку QString вычисление в случае валидной операции или строку "..." в случае невалидной операции
 */
QString calcul(int i, std::deque<double> story_first_num, std::deque<char> story_operation, std::deque<double> story_second_num, std::deque<double> story_equal_num)
{
    if (valid_operation(story_operation[i]))
        return QString::number(story_first_num[i], 'g', 3) + " " + story_operation[i] + " " + QString::number(story_second_num[i], 'g', 3) + " = " + QString::number(story_equal_num[i], 'g', 3);
    else
        return "...";
}
