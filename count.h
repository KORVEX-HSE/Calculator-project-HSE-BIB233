/*!
 * \file
 * \brief Заголовочный файл с объявлениями вычислительных функций
*/



#ifndef COUNT_H
#define COUNT_H

#include <deque>
#include "qstring.h"

QString counter(double num1, char opera, double num2, std::deque<char> * story_operation, std::deque<double> * story_equal_num, int show_size);
bool valid_operation(char operation);
QString calcul(int i, std::deque<double> story_first_num, std::deque<char> story_operation, std::deque<double> story_second_num, std::deque<double> story_equal_num);

#endif // COUNT_H
