#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/**
 * @brief считывает целое значение с клавиатуры в проверкой ввода
 * @return возвращает считанное значение
 */
int getValue();

/**
 * @brief считывает вещественное значение с клавиатуры в проверкой ввода
 * @return возвращает считанное значение
 */
double getDouble();

/**
 * @brief рассчитывает сумму n членов последовательности
 * @param n - заданное число членов
 * @return рассчитанное значение
 */
double getSumN(const int n);

/**
 * @brief рассчитывает сумму членов последовательности,
 * с точностью e
 * @param e - заданная точность
 * @return рассчитанное значение
 */
double getSumE(const double e);

/**
 * @brief вычисляет факториал числа
 * @param n - число для вычисления факториала
 * @return факториал числа n
 */
long long factorial(int n);

/**
 * @brief проверяет, что число положительное
 * @param value - проверяемое значение
 */
void checkPositive(const double value);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Введите n:");
    int n = getValue();
    checkPositive(n);
    printf("Сумма %d чисел последовательности равна %.6lf\n",
        n, getSumN(n));

    printf("Введите e:");
    double e = getDouble();
    checkPositive(e);
    printf("Сумма последовательности с точностью "
        "%lf равна %.6lf\n",
        e, getSumE(e));

    return 0;
}

int getValue()
{
    int value = 0;
    if (!scanf("%d", &value))
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

double getDouble()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

long long factorial(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

double getSumN(const int n)
{
    double result = 0;
    for (int k = 1; k <= n; k++)
    {
        double term = pow(-1, k) * (1.0 + k) / factorial(k + 2);
        result += term;
    }
    return result;
}

void checkPositive(const double value)
{
    if (value <= 0)
    {
        printf("Error: значение должно быть положительным\n");
        exit(1);
    }
}

double getSumE(const double e)
{
    double result = 0;
    double term;
    int k = 1;

    do {
        term = pow(-1, k) * (1.0 + k) / factorial(k + 2);
        result += term;
        k++;
    } while (fabs(term) > e);

    return result;
}
