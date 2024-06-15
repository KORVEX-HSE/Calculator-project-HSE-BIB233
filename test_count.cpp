#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "count.h"
#include <deque>



TEST_CASE("Valid_operation - Case 1")
{
    CHECK(valid_operation('+') == true);
}
TEST_CASE("Valid_operation - Case 2")
{
    CHECK(valid_operation('#') == true);
}
TEST_CASE("Valid_operation - Case 3")
{
    CHECK(valid_operation('a') == false);
}
TEST_CASE("Valid_operation - Case 4")
{
    CHECK(valid_operation('5') == false);
}
TEST_CASE("Valid_operation - Case 5")
{
    CHECK(valid_operation(' ') == false);
}
TEST_CASE("Valid_operation - Case 5")
{
    CHECK(valid_operation('^') == true);
}



std::deque<double> story_first_num = {1, 2, 3, 4, 5, 9};
std::deque<char> story_operation = {'+', '-', '*', '/', '^', '#'};
std::deque<double> story_second_num = {6, 5, 4, 2, 2, 2};
std::deque<double> story_equal_num = {7, -3, 12, 2, 25, 3};

TEST_CASE("Calcul - Case 1")
{
    CHECK(calcul(0, story_first_num, story_operation, story_second_num, story_equal_num) == QString("1 + 6 = 7"));
}
TEST_CASE("Calcul - Case 2")
{
    CHECK(calcul(1, story_first_num, story_operation, story_second_num, story_equal_num) == QString("2 - 5 = -3"));
}
TEST_CASE("Calcul - Case 3")
{
    CHECK(calcul(2, story_first_num, story_operation, story_second_num, story_equal_num) == QString("3 * 4 = 12"));
}
TEST_CASE("Calcul - Case 4")
{
    CHECK(calcul(3, story_first_num, story_operation, story_second_num, story_equal_num) == QString("4 / 2 = 2"));
}
TEST_CASE("Calcul - Case 5")
{
    CHECK(calcul(4, story_first_num, story_operation, story_second_num, story_equal_num) == QString("5 ^ 2 = 25"));
}
TEST_CASE("Calcul - Case 6")
{
    CHECK(calcul(5, story_first_num, story_operation, story_second_num, story_equal_num) == QString("9 # 2 = 3"));
}



std::deque<char> opera(6);
std::deque<double> res(6);

TEST_CASE("Counter - Case 1")
{
    CHECK(counter(1, '+', 8, &opera, &res, 15) == QString("9"));
    CHECK(res[0] == 9);
    CHECK(opera[0] == '+');
}
TEST_CASE("Counter - Case 2")
{
    CHECK(counter(38, '-', -4, &opera, &res, 15) == QString("42"));
    CHECK(res[0] == 42);
    CHECK(opera[0] == '-');
}
TEST_CASE("Counter - Case 3")
{
    CHECK(counter(1.4, '*', -4, &opera, &res, 15) == QString("-5.6"));
    CHECK(res[0] == -5.6);
    CHECK(opera[0] == '*');
}
TEST_CASE("Counter - Case 4")
{
    CHECK(counter(1, '/', 0, &opera, &res, 15) == QString("inf"));
    CHECK(res[0] == std::numeric_limits<double>::infinity());
    CHECK(opera[0] == '/');
}
TEST_CASE("Counter - Case 5")
{
    CHECK(counter(10, '^', 3, &opera, &res, 15) == QString("1000"));
    CHECK(res[0] == 1000);
    CHECK(opera[0] == '^');
}
TEST_CASE("Counter - Case 6")
{
    CHECK(counter(16, '#', 2, &opera, &res, 15) == QString("4"));
    CHECK(res[0] == 4);
    CHECK(opera[0] == '#');
}
