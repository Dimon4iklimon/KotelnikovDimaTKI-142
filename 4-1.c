#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* @brief Выводит ошибку в поток ошибок и завершает программу
* @param text - текст выводимой ошибки
*/
void ERROR(const char* text);

/**
* @brief Считывает значение введённое с клавиатуры, с проверкой ввода
* @return Размер массива
*/
const int getSize(void);

/**
* @brief Считывает значение введённое с клавиатуры, с проверкой ввода
* @return Целое число
*/
int Input(void);

/**
* @brief Заполняет массив значениями, которые вводит пользователь
* @param arr - массив
* @param size - размер массива
*/
void fillManual(int* arr, const size_t size);

/**
* @brief Заполняет массив случайнами значениями, лежашие в промежутке
* @param arr - массив
* @param size - размер массива
*/
void fillRandom(int* arr, const size_t size);

/**
* @brief Выводит указанный массивна экран
* @param arr - массив
* @param size - размер массива
*/
void printARR(const int* arr, const size_t size);

/**
* @brief Создаёт массив, аналогичный старому
* @param arr - массив
* @param size - размер массива
*/
int* cloneARR(const int* arr, const size_t size);

/**
* @brief Выводит сумму чисел массива, согласно условию №1
* @param arr - массив
* @param size - размер массива
*/
const int getTaskOne(const int* arr, const size_t size);

/**
* @brief Изменяет массив, согласно условию №2 и выводит его на экран
* @param arr - массив
* @param size - размер массива
*/
void getTaskTwo(int* arr, const size_t size);

/**
* @brief Выводит индекс пары, согласно условию №3
* @param arr - массив
* @param size - размер массива
*/
const int getTaskThree(const int* arr, const size_t size);

/**
* @brief Проверяет корректность выделения памяти под массив и правильную передачу в функции
* @param arr - проверяемый массив
*/
void checkPoint(const int* arr);

/**
* @brief Константы выбора для метода заполнения и выполняемого задания
*/
enum { MANUAL = 1, RANDOM, TASK1 = 1, TASK2, TASK3 };

/**
* @brief Точка входа в программу
* @param 0 если программа выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");
	srand(time(NULL));

	printf("Введите кол-во элементов массива:");
	const size_t size = getSize();

	int* arr = calloc(size, sizeof(int));
	checkPoint(arr);

	printf("\nКак будет заполнен массив?\n%d - Вручную\n%d - Автоматичски\n", MANUAL, RANDOM);
	int choise1 = Input();
	switch (choise1)
	{
	case MANUAL:
		fillManual(arr, size);
		break;
	case RANDOM:
		fillRandom(arr, size);
		break;
	default:
		free(arr);
		ERROR("Ошибка выбора");
	}

	printARR(arr, size);
	int* copyarr = cloneARR(arr, size);
	checkPoint(copyarr);

	printf("\nКакие будут преобразования?\n%d - Найти сумму положительных элементов, значения которых состоят из двух цифр\n%d - Умножить все четные положительные элементы на последний элемент массива\n%d - Найти номер первой пары соседних элементов с разными знаками, сумма которых меньше заданного числа\n", TASK1, TASK2, TASK3);
	int choise2 = Input();
	switch (choise2)
	{
	case TASK1:
		printf("Cумма положительных элементов, значения которых состоят из двух цифр: %d", getTaskOne(copyarr, size));
		break;
	case TASK2:
		getTaskTwo(copyarr, size);
		break;
	case TASK3:
		printf("Номер первой пары соседних элементов с разными знаками, сумма которых меньше заданного числа: %d", getTaskThree(copyarr, size));
		break;
	default:
		free(arr);
		free(copyarr);
		ERROR("Ошибка выбора");
	}

	free(arr);
	free(copyarr);

	return 0;
}

void ERROR(const char* text)
{
	fprintf(stderr, "%s", text);
	exit(1);
}


void checkPoint(const int* arr)
{
	if (arr = NULL)
	{
		ERROR("Ошибка выделения памяти");
	}
}

const int getSize(void)
{
	int size = 0;
	if (!scanf_s("%d", &size))
	{
		ERROR("Некорректный ввод");
	}

	if (size <= 0)
	{
		ERROR("Некорректный ввод, число должно быть больше 0");
	}

	return (size_t)size;
}

int Input(void)
{
	int value = 0;
	if (!scanf_s("%d", &value))
	{
		ERROR("Некорректный ввод");
	}
	return value;
}

void fillManual(int* arr, const size_t size)
{
	checkPoint(arr);
	printf("Введите %zu элементов массива", size);
	for (size_t i = 0; i < size; i++)
	{
		printf("Arr[%zu] = ", i);
		arr[i] = Input();
	}
}

void fillRandom(int* arr, const size_t size)
{
	checkPoint(arr);

	printf("Введите минимальный элемент массива:");
	int min = Input();
	printf("Введите максимальный элемент массива:");
	int max = Input();

	if (min >= max)
	{
		ERROR("Некорректный ввод промежутка");
	}

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

void printARR(const int* arr, const size_t size)
{
	checkPoint(arr);
	printf("\nМассив\n");
	for (size_t i = 0; i < size; i++)
	{
		printf("%5d", arr[i]);
	}
}

int* cloneARR(const int* arr, const size_t size)
{
	checkPoint(arr);
	int* newarr = calloc(size, sizeof(int));
	checkPoint(newarr);
	for (size_t i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}
	return newarr;
}

const int getTaskOne(const int* arr, const size_t size)
{
	checkPoint(arr);

	int summ = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > 0 && arr[i] > 9 && arr[i] < 100)
		{
			summ += arr[i];
		}
	}
	return summ;
}

void getTaskTwo(int* arr, const size_t size)
{
	checkPoint(arr);

	int temp = arr[size - 1];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > 0 && arr[i] % 2 == 0)
		{
			arr[i] = arr[i] * temp;
		}
	}

	printARR(arr, size);
}

const int getTaskThree(const int* arr, const size_t size)
{
	checkPoint(arr);

	printf("Введите число k:\n");
	int k = Input();

	int idx = 0;
	for (size_t i = 0; i < size; i++)
	{
		if ((arr[i] > 0 && arr[i + 1] < 0) || !(arr[i] < 0 && arr[i + 1] > 0))
		{
			if (arr[i] + arr[i + 1] < k);
			{
				idx = i + 1;
				break;
			}
		}
	}
	return idx;
}
