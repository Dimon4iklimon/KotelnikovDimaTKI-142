#define _CRT_SECURE_NO_WARNINGS
#include<locale.h>
#include <stdio.h>

/** @brief Получает значение числа
 * @return Полученное число типа double
 */
double get_number();

/** @brief Получает выбор действия пользователя
 * @return Номер выбранного действия
 */
int get_action();

/*
 * @brief Перечисление действий с переменными
 * @details Amount - Сложение
 *          Difference - Вычитание
 *          Average - Среднее арифметическое 
*/
enum { Amount, Difference, Average };

/** @brief Точка входа в программу.
 * @return 0 в случае успеха
 * @return 1 в случае неудачи
 */
int main(void) {
    setlocale(LC_ALL, "Russian");
    const double A = get_number();
    const double B = get_number();
    const int Action = get_action();

    switch (Action) {
    case Amount:
        printf("Сумма чисел равна: %lf", A + B);
        break;
    case Difference:
        printf("Разность чисел равна: %lf", A - B);
        break;
    case Average:
        printf("Среднее арифметическое чисел равно: %lf", (A + B) / 2);
        break;
    default:
        printf("Ошибка: неверный выбор операции.");
        return 1;
    }
    return 0;
}

double get_number() {
    static int counter = 1;
    printf("Введите %s число: ", counter == 1 ? "первое" : "второе");
    double number = 0;
    scanf("%lf", &number);
    counter++;
    return number;
}

int get_action() {
    printf("%d — Сложение\n%d — Вычитание\n%d — Среднее арифметическое\n", Amount, Difference, Average);
    printf("Выберите операцию с переменными: ");
    int action;
    scanf("%d", &action);
    return action;
}
