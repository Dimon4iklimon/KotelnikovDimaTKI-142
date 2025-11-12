#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include<locale.h>

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main() {
    setlocale(LC_ALL, "Russian");
    double a = 0;
    double b = 0;
    double c = 0;
    int check = 0;

    printf("Введите три действительных числа (a, b, c):\n");

    // Проверка корректности ввода
    check = scanf("%lf %lf %lf", &a, &b, &c);
    if (check != 3) {
        printf("Ошибка: необходимо ввести три действительных числа!\n");
        return 1; // завершение программы с кодом ошибки
    }

    // Разветвлённый процесс
    if (a < b && b < c) {
        a *= 2;
        b *= 2;
        c *= 2;
        printf("Условие a < b < c выполнено. Удвоенные значения:\n");
    }
    else {
        a = fabs(a);
        b = fabs(b);
        c = fabs(c);
        printf("Условие a < b < c НЕ выполнено. Абсолютные значения:\n");
    }

    // Вывод результата
    printf("a = %.2lf, b = %.2lf, c = %.2lf\n", a, b, c);

    return 0;
}
