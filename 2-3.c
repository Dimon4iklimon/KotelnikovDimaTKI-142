#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <locale.h>

/**
 * @brief считывает значение,
 * введенное с клавиатуры с проверкой ввода
 * @return считанное значение
 */
double getValue();

/**
 * @brief Точка входа в программу
 * @return возвращает 0, если программма выполнена корректно
 */
int main(void)
{
    setlocale(LC_ALL, "Russian");

    double a = 0;
    double b = 0;
    double c = 0;

    // Ввод первого числа
    printf("Введите значение a: ");
    a = getValue();

    // Ввод второго числа
    printf("Введите значение b: ");
    b = getValue();

    // Ввод третьего числа
    printf("Введите значение c: ");
    c = getValue();

    // Вывод введенных значений
    printf("\nВведенные значения:\n");
    printf("a = %.2lf\n", a);
    printf("b = %.2lf\n", b);
    printf("c = %.2lf\n", c);

    // Разветвлённый процесс
    if (a < b && b < c) {
        printf("\nУсловие a < b < c выполнено. Удваиваем значения:\n");
        a *= 2;
        b *= 2;
        c *= 2;
    }
    else {
        printf("\nУсловие a < b < c НЕ выполнено. Берем абсолютные значения:\n");
        a = fabs(a);
        b = fabs(b);
        c = fabs(c);
    }

    // Вывод результата
    printf("\nРезультат обработки:\n");
    printf("a = %.2lf\n", a);
    printf("b = %.2lf\n", b);
    printf("c = %.2lf\n", c);

    return 0;
}

double getValue()
{
    double value = 0;
    if (!scanf("%lf", &value))
    {
        printf("Ошибка: необходимо ввести действительное число!\n");
        abort();
    }
    return value;
}
