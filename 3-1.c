#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<float.h>

/**
* @brief Рассчитывает значение ординаты функции в указанной точке
* @param x - абцисса точки
* @return Рассчитанное значение ординаты
*/
const double defFunct(const double x);

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
double getValid();

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
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
  system("chcp 1251");

  printf("Введите начальное значение: ");
  double start = getValid();
  printf("Введите конечное значение: ");
  double end = getValid();
  checkEndStart(start, end);

  printf("Введите шаг: ");
  double step = getValid();
  checkStep(step);

  printf("%-10s %s\n", "x", "f(x)");
  for (double x = start; x < end + step + DBL_EPSILON; x += step)
  {
    printf_s("%-10.2lf%.4lf\n", x, defFunct(x));
  }

  return 0;
}

const double defFunct(const double x)
{
  return cos(x) - exp(-1.0 * pow(x, 2) / 2) + x - 1;
}

double getValid()
{
  double valid = 0;
  if (!scanf_s("%lf", &valid))
  {
    printf("Error\n");
    exit(1);
  }
  return valid;
}

void checkEndStart(const double start, const double end)
{
  if (!(start < end))
  {
    printf("Error\n");
    exit(1);
  }
}

void checkStep(const double step)
{
  if (step <= DBL_EPSILON)
  {
    printf("Error\n");
    exit(1);
  }
}
