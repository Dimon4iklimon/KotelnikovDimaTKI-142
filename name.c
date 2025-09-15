#include <stdio.h>

/*
* @brief Точка входа в программу 
* @return возвращает 0 если программа выполена корректно, иначе 1
*/

double getB(const double x, const double y, const double z);

double getA(const double x, const double y, const double z);

int main()
{
	const double x = 3.1;
	const double y = 2.3;
	const double z = -1.25;

	return 0;

}

double getB(const double x, const double y, const double z)
{
	double a = getA(x, y, z);
	return sin(a) + exp(x + y) + z;

}

double getA(const double x, const double y, const double z)
{

}
