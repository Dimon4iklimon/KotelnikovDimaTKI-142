#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>
#include<float.h>

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief рассчитывает значение функции y
 * @param a значение параметра а
 * @param x значение параметра x
 * @return считает значение функции y
 */
double getFunctionY(const double x, const double a);

/**
 * @brief Точка входа в программу
 * @param x - вводится значение x
 * @return возвращает 0, если программа выполнена корректно
 */
int main() {
    setlocale(LC_ALL, "Russian");
    const double a = 2.0;
    printf("Введите значение параметра x = ");
    double x = getValue();
    printf("Значение функции = %.6lf", getFunctionY(x, a));
    return 0;
}

double getValue() {
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Error\n");
        abort();
    }
    return value;
}

double getFunctionY(const double x, const double a) {
    if (x > a) {
        // y = tg(x) + π/3 для x > a
        return tan(x) + M_PI / 3;
    }
    else {
        // y = sin(x) * a для x <= a
        return sin(x) * a;
    }
}
