#include <stdio.h>
#include <math.h>

/**
* @brief Рассчитывает функцию B по заданной формуле
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитывает значение
*/
double getB(const double x, const double y, const double z);

/**
* @brief Рассчитывает функцию A по заданной формуле
* @param x - значение параметра x
* @param y - значение параметра y
* @param z - значение параметра z
* @return рассчитывает значение
*/
double getA(const double x, const double y, const double z);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main()
{
	const double x = 1.7;
	const double y = 1.08;
	const double z = 0.5;
	printf("A = %lf\n", getA(x, y, z));
	printf("B = %lf", getB(x, y, z));
	return 0;

}

double getA(const double x, const double y, const double z)
{
	return (sin(x) / (pow(pow(y, 2) + pow(sin(x), 2), 0.5))) - pow(x,2) * y * z;
}

double getB(const double x, const double y, const double z)
{
	return exp(-z * x) * pow(x + 1, 0.5) + exp(-y * x);
}
