#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/**
 * @brief рассчитывает сумму 
 * @param a первое число
 * @param b второе число
 * @return возвращает рассчитанную сумму 
 */
double getAmount(const double a, const double b);

/**
 * @brief рассчитывает разность
 * @param a первое число
 * @param b второе число
 * @return возвращает рассчитанную разность
 */
double getDifference(const double a, const double b);

/**
 * @brief рассчитывает среднее арифметическое 
 * @param a первое число
 * @param b второе число
 * @return возвращает рассчитанное среднее арифметическое 
 */
double getAverage(const double a, const double b);

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief проверяет,что переменная положительная
 * @param value значение проверяемой переменной
 */
void checkValue(const double value);

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    setlocale(LC_ALL, "Russian");
    printf("Введите числа a и b : ");
    double a = getValue();
    checkValue(a);
    double b = getValue();
    checkValue(b);
    printf("Сумма = %.2lf\n", getAmount(a, b));
    printf("Разность = %.2lf\n", getDifference(a, b));
    printf("Среднее арифметическое = %.2lf\n", getAverage(a, b));
    return 0;
}

double getAmount(const double a, const double b)
{
    return a + b;
}

double getDifference(const double a, const double b)
{
    return a - b;
}

double getAverage(const double a, const double b)
{
    return (a + b) / 2;
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

void checkValue(const double value)
{
    if (value <= 0)
    {
        printf("Value have to be positive\n");
        abort();
    }
}
