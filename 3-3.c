#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<float.h>

/**
* @brief Рассчитывает значение функции в точке
* @param x - точка
* @return Рассчитанное значение
*/
const double function(const double x);

/**
* @brief Рассчитывает значение рекурентной формулы с заданной точностью e
* @param e - точность рассчёта 
* @param x - значение параметра x, участвующее в расcчёте
* @return Рассчитанное значение
*/
double defSummE(const double e, const double x);

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double defValid();

/**
 * @brief Рассчитывает коэффициент рекуррентного выражения
 * @param i - текущий индекс
 * @param x - значение параметра x, участвующее в раcсчёте
 * @return Рассчитанное значение коэффициента
 */
double getRecurent(const int i, const double x);

/**
* @brief Проверяет переменную на условие
* @param input - значение проверяемой переменной
*/
void CheckValue(const double input);

/**
* @brief Проверяет значения на условие
* @param end - значение конца промежутка
* @param start - значение начала промежутка
*/
void checkEndStart(const double start, const double end);

/**
* @brief Проверяет значение на условие
* @param step - значение шага
*/
void checkStep(const double step);

/**
* @brief Проверяет заначение на условие
* @param x - значение параметра x
* @return Возвращает 0 или 1 в зависимости от истинности выражения
*/
_Bool checkX(const double x);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	printf("Введите число e: ");
	double e = defValid();
	CheckValue(e); // ε > 0

	printf("Введите начальное значение: ");
	double start = defValid();
	printf("Введите конечное значение: ");
	double end = defValid();
	checkEndStart(start, end);

	printf("Введите шаг: ");
	double step = defValid();
	checkStep(step);

	printf("%-10s%-25s%-10s\n", "x", "f(x)", "Summ(x)");
	for (double x = start; x <= end + DBL_EPSILON; x += step)
	{
		if (checkX(x))
		{
			printf_s("%-10.2lf%-25.4lf%-10.4lf\n", x, function(x), defSummE(e, x));
		}
		else
		{
			printf_s("%-10.2lf%-25s%-10s\n", x, "Функция не определена", "Сумма ряда не определена");
		}
	}

	return 0;
}

const double function(const double x)
{
	return (x * (3.0 - x)) / pow(1.0 - x, 3.0);
}

double defValid()
{
	double valid = 0;
	if (!scanf_s("%lf", &valid))
	{
		printf("Error\n");
		exit(1);
	}
	return valid;
}

void CheckValue(const double input)
{
	if (!(input > 0))
	{
		printf("Error\n");
		exit(1);
	}
}

double defSummE(const double e, const double x)
{
	double current = 3.0 * x; // a1 = 1*(1+2)*x = 3x
	double result = 0.0;
	int i = 1;

	while (fabs(current) > e)
	{
		result += current;
		i++;
		current *= getRecurent(i, x);
	}
	return result;
}

void checkEndStart(const double start, const double end)
{
	if (!(start < end))
	{
		printf("Error\n Значения не должны совпадать\n Значение начала не может быть больше значения конца\n");
		exit(1);
	}
}

void checkStep(const double step)
{
	if (step <= DBL_EPSILON)
	{
		printf("Error\n Шаг должен быть больше 0\n");
		exit(1);
	}
}

double getRecurent(const int i, const double x)
{
	// a_i = i*(i+2)*x^i
	// a_{i} / a_{i-1} = [i*(i+2) * x] / [(i-1)*(i+1)]
	if (i <= 1)
	{
		return 1.0;
	}
	double numerator = i * (i + 2.0) * x;
	double denominator = (i - 1.0) * (i + 1.0);
	return numerator / denominator;
}

_Bool checkX(const double x)
{
	return (x > 0.0) && (x < 1.0 - DBL_EPSILON);
}
