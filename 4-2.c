#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>

/**
* @brief Считывает значение, введённое с клавиатуры, с проверкой ввода
* @return Считанное значение
*/
int getValid();

/**
* @brief Проверяет что переменная не меньше единицы
* @param input - значение проверяемой переменной
*/
void checkValueForN(const int input);

/**
* @brief Проверяет лежит ли переменная в интервале [min;max]
* @param input - значение проверяемой переменной
* @param min - минимально возможный элемент
* @param max - максимально возможный элемент
*/
void checkValue(const int input, const int min, const int max);

/**
* @brief Заменяет первый элемент массива, кратный 5, на ноль
* @param arr - массив
* @param size - размер массива
*/
void defForTask1(int* arr, const size_t size);

/**
* @brief Вставляет элемент K после всех нечётных элементов, начинающихся на цифру K
* @param arr - массив
* @param size - размер массива
* @param K - значение для вставки и проверки начальной цифры
*/
void defForTask2(const int* arr, const size_t size, const int K);

/**
* @brief Создаёт новый массив согласно условию 3 из массива P
* @param arr - исходный массив P
* @param size - размер массива
* @return Указатель на новый массив M
*/
int* defForTask3(const int* arr, const size_t size);

/**
* @brief Проверяет, начинается ли число (по модулю) на цифру K
* @param num - проверяемое число
* @param K - цифра (0-9)
* @return 1, если начинается, иначе 0
*/
bool startsWithDigit(int num, int K);

/**
* @brief Проверяет, удалось ли выделить память для массива
* @param arr - массив
*/
void check_pointer(const int* arr);

/**
* @brief Проверяет корректность диапазона [min; max]
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void defCheckMinMax(const int min, const int max);

/**
* @brief Заполняет массив элементами, введёнными с клавиатуры, с учётом диапазона
* @param arr - массив
* @param size - размер массива
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void getManual(int* arr, const size_t size, const int min, const int max);

/**
* @brief Заполняет массив случайными элементами в заданном диапазоне
* @param arr - массив
* @param size - размер массива
* @param min - минимально возможный элемент массива
* @param max - максимально возможный элемент массива
*/
void getRandom(int* arr, const size_t size, const int min, const int max);

/**
* @brief Выводит все элементы массива на экран
* @param arr - массив
* @param size - размер массива
*/
void defPrintArr(const int* arr, const size_t size);

/**
* @brief Копирует все элементы массива в новый
* @param arr - исходный массив
* @param size - размер массива
* @return Новый массив, идентичный старому
*/
int* defcopyArr(const int* arr, const size_t size);

/**
@brief CHOISE_ONE - первый выбор (Ручное заполнение массива)
@brief CHOISE_TWO - второй выбор (Автоматическое заполнение массива)
@brief TASK_ONE - выполнение первого задания
@brief TASK_TWO - второе задание
@brief TASK_THREE - третье задание
*/
enum { CHOISE_ONE = 1, CHOISE_TWO, TASK_ONE = 1, TASK_TWO, TASK_THREE };

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа была выполнена корректно, иначе 1
*/
int main(void)
{
	system("chcp 1251");

	printf("Введите размер массива: ");
	size_t size = (size_t)getValid();
	checkValueForN(size);

	int* A = calloc(size, sizeof(int));
	check_pointer(A);

	printf("Введите диапазон, в котором будут задаваться числа массива: \n");
	const int min = getValid();
	const int max = getValid();
	defCheckMinMax(min, max);
	printf("Числа массива будут в диапазоне [%d,%d]", min, max);

	printf("\nКак будет заполнен массив?\n %d - Ручной ввод\n %d - Автоматический ввод\n", CHOISE_ONE, CHOISE_TWO);
	int choise = getValid();

	switch (choise)
	{
	case CHOISE_ONE:
		getManual(A, size, min, max);
		break;

	case CHOISE_TWO:
		getRandom(A, size, min, max);
		break;

	default:
		fprintf(stderr,"Error");
		free(A);
		exit(1);
	}

	defPrintArr(A, size);
	int* copyA = defcopyArr(A, size);
	check_pointer(copyA);

	int* AforTask3 = defForTask3(A, size);
	check_pointer(AforTask3);

	printf("\nКакие будут преобразования?\n"
		"%d - Заменить первый элемент массива, кратный 5, нулем\n"
		"%d - Вставить элемент со значением K после всех нечетных элементов, начинающихся на цифру K\n"
		"%d - Из элементов массива P сформировать массив M той же размерности: M[0]=M[size-1]=0, остальные Mi=-Pi*(i+1)\n",
		TASK_ONE, TASK_TWO, TASK_THREE);
	int second_choise = getValid();

	switch (second_choise)
	{
	case TASK_ONE:
		defForTask1(copyA, size);
		break;

	case TASK_TWO:
	{
		printf("Введите K (целое число от 0 до 9): ");
		int K = getValid();
		if (K < 0 || K > 9)
		{
			fprintf(stderr, "Error\nK должно быть цифрой от 0 до 9");
			free(A);
			free(copyA);
			free(AforTask3);
			exit(1);
		}
		defForTask2(copyA, size, K);
		break;
	}

	case TASK_THREE:
		defPrintArr(AforTask3, size);
		break;

	default:
		fprintf(stderr,"Error");
		free(A);
		free(copyA);
		free(AforTask3);
		exit(1);
	}

	free(A);
	free(copyA);
	free(AforTask3);

	return 0;
}

int getValid()
{
	int valid = 0;
	if (!scanf_s("%d", &valid))
	{
		fprintf(stderr,"Error");
		exit(1);
	}
	return valid;
}

void checkValueForN(const int input)
{
	if (input < 1)
	{
		fprintf(stderr,"Error\nЧисло должно быть не меньше 1");
		exit(1);
	}
}

void defCheckMinMax(const int min, const int max)
{
	if (min >= max)
	{
		fprintf(stderr,"Error\n Неправильно указан диапазон");
		exit(1);
	}
}

void checkValue(const int input, const int min, const int max)
{
	if (input > max || input < min)
	{
		fprintf(stderr,"Error\nЧисло должно лежать в промежутке [%d;%d]", min, max);
		exit(1);
	}
}

void getManual(int* arr, const size_t size, const int min, const int max)
{
	check_pointer(arr);

	printf("\nВведи %zu элемент-а(ов) массива:\n", size);
	for (size_t i = 0; i < size; i++)
	{
		int num = getValid();
		checkValue(num, min, max);
		printf("A[%zu] = %d\n", i, num);
		arr[i] = num;
	}
}

void getRandom(int* arr, const size_t size, const int min, const int max)
{
	check_pointer(arr);
	srand(time(NULL));

	for (size_t i = 0; i < size; i++)
	{
		int numm = (rand() % (max - min + 1)) + min;
		arr[i] = numm;
	}
}

void defPrintArr(const int* arr, const size_t size)
{
	check_pointer(arr);

	printf("\nМассив: \n");
	for (size_t i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}

int* defcopyArr(const int* arr, const size_t size)
{
	check_pointer(arr);

	int* copyArr = calloc(size,sizeof(int));
	check_pointer(copyArr);

	for (size_t i = 0; i < size; i++)
	{
		copyArr[i] = arr[i];
	}
	return copyArr;
}

void defForTask1(int* arr, const size_t size)
{
	check_pointer(arr);

	bool found = false;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] % 5 == 0)
		{
			arr[i] = 0;
			found = true;
			break;
		}
	}

	if (!found)
	{
		printf("\nЭлемент, кратный 5, не найден\n");
	}
	else
	{
		printf("\nНовый массив: \n");
		for (size_t i = 0; i < size; i++)
		{
			printf("%d\n", arr[i]);
		}
	}
}

void defForTask2(const int* arr, const size_t size, const int K)
{
	check_pointer(arr);

	// Подсчёт количества вставок
	int countInsert = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] % 2 != 0 && startsWithDigit(arr[i], K))
		{
			countInsert++;
		}
	}

	size_t newsize = size + countInsert;
	int* newarr = calloc(newsize, sizeof(int));
	check_pointer(newarr);

	size_t j = 0;
	for (size_t i = 0; i < size; i++)
	{
		newarr[j] = arr[i];
		j++;

		if (arr[i] % 2 != 0 && startsWithDigit(arr[i], K))
		{
			newarr[j] = K;
			j++;
		}
	}

	defPrintArr(newarr, newsize);
	free(newarr);
}

int* defForTask3(const int* arr, const size_t size)
{
	check_pointer(arr);

	int* newarr = calloc(size, sizeof(int));
	check_pointer(newarr);

	if (size == 1)
	{
		newarr[0] = 0;
	}
	else
	{
		newarr[0] = 0;
		newarr[size - 1] = 0;

		for (size_t i = 1; i < size - 1; i++)
		{
			newarr[i] = -arr[i] * (int)(i + 1);
		}
	}

	return newarr;
}

bool startsWithDigit(int num, int K)
{
	num = abs(num);
	if (num == 0)
	{
		return (K == 0) ? true : false;
	}
	while (num >= 10)
	{
		num = num / 10;
	}
	return (num == K) ? true : false;
}

void check_pointer(const int* arr)
{
	if (arr == NULL)
	{
		fprintf(stderr, "Error");
		exit(1);
	}
}
