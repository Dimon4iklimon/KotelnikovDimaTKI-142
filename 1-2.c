#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<locale.h>
#include<math.h>

/*
* @brief Рассчитывает функцию PerimetrTreug по заданной формуле
* @param a - значение катета a
* @param b - значение катета b
* @return рассчитанное значение
*/
double getPerimetrTreug(const double a, const double b);

/*
* @brief Рассчитывает функцию SquareTreug по заданной формуле
* @param a - значение катета a
* @param b - значение катета b
* @return рассчитанное значение
*/
double getSquareTreug(const double a, const double b);

/*
* @brief Точка входа в программу
* @return Возвращает 0, если функция выполнена корректно
*/
int main() {
	setlocale(LC_ALL, "Russian");
	printf("Введите значение для катетов треугольника:");
	const double a = 0;
	scanf("%lf", &a);
	const double b = 0;
	scanf("%lf", &b);
	printf("PerimetrTreug = %.2lf\n", getPerimetrTreug(a, b));
	printf("SquareTreug = %.2lf\n", getSquareTreug(a, b));
	return 0;
}

double getPerimetrTreug(const double a, const double b)
{
	return pow(pow(a, 2) + pow(b, 2), 0.5) + a + b;
}

double getSquareTreug(const double a, const double b)
{
	return a * b / 2;
}
