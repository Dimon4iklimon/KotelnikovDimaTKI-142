#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

/**
* @brief Вычисляет энергию затраченную на плавление льда
* @param m - масса
* @param с - удельная теплоемкость льда
* @param u - удельная теплота плавления льда
* @param T - температура льда
* @param T_plavlenia - температура плавления
* @return Рассчитанне значение
*/
double getEnergy(const double m, const double c, const double u, const double T, const double T_plavlenia);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	const double T = -10;
	const double c = 2100;
	const double u = 340000;
	const double T_plavlenia = 0;
	double m;

	printf("Введите массу льда : ");
	scanf("%lf", &m);

	printf("Энергия затраченная на плавление льда = %.2lf Дж\n", getEnergy(m, c, u, T, T_plavlenia));

	return 0;
}

double getEnergy(const double m, const double c, const double u, const double T, const double T_plavlenia)
{
	return (c * m * (T_plavlenia - T)) + (u * m);
}
