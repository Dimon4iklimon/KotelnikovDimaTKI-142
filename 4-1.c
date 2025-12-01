#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/**
 * @brief Считывает целое число с клавиатуры
 *
 * @return int Введенное пользователем число
 *
 * @note При ошибке ввода выводит сообщение и завершает программу
 * @warning Очищает буфер ввода при ошибке
 */
int Value();

/**
 * @brief Запрашивает и возвращает размер массива
 *
 * @param message Сообщение для пользователя
 * @return size_t Размер массива (положительное число)
 *
 * @note Проверяет, что размер > 0
 * @warning При некорректном размере завершает программу
 */
size_t getSize(char* message);

/**
 * @brief Заполняет массив значениями с клавиатуры
 *
 * @param arr Указатель на массив
 * @param size Размер массива
 *
 * @note Запрашивает каждое значение у пользователя
 * @note Проверяет, что числа в диапазоне [-1000, 1000]
 * @warning Изменяет переданный массив
 */
void fillArray(int* arr, const size_t size);

/**
 * @brief Заполняет массив случайными числами
 *
 * @param arr Указатель на массив
 * @param size Размер массива
 *
 * @note Генерирует числа в диапазоне [-1000, 1000]
 * @warning Для работы требует предварительной инициализации rand()
 */
void fillRandom(int* arr, const size_t size);

/**
 * @brief Выводит массив на экран
 *
 * @param arr Указатель на массив
 * @param size Размер массива
 *
 * @note Выводит все элементы через пробел
 * @note Добавляет перевод строки в конце
 */
void printArray(int* arr, const size_t size);

/**
 * @brief Находит сумму положительных двузначных элементов
 *
 * @param arr Указатель на массив
 * @param size Размер массива
 * @return int Сумма положительных двузначных элементов
 *
 * @note Двузначные числа: от 10 до 99 включительно
 * @note Отрицательные числа игнорируются
 * @example Для массива [5, 15, -25, 99, 100] вернет 114 (15 + 99)
 */
int sumTwoDigitPositive(int* arr, const size_t size);

/**
 * @brief Умножает четные положительные элементы на последний элемент
 *
 * @param arr Указатель на массив
 * @param size Размер массива
 *
 * @note Изменяет исходный массив
 * @note Умножаются только элементы, удовлетворяющие условиям:
 *       1. arr[i] > 0 (положительные)
 *       2. arr[i] % 2 == 0 (четные)
 * @note Последний элемент массива: arr[size-1]
 * @warning Если size = 0, функция ничего не делает
 * @example Для массива [2, 3, 4, 5] (последний = 5) получим [10, 3, 20, 5]
 */
void multiplyEvenPositiveByLast(int* arr, const size_t size);

/**
 * @brief Находит первую пару соседних элементов с разными знаками
 *
 * @param arr Указатель на массив
 * @param size Размер массива
 * @param givenNumber Число для сравнения суммы
 * @return int Индекс первого элемента пары или -1 если не найдено
 *
 * @note Ищет ПЕРВУЮ (самую левую) подходящую пару
 * @note Условия для пары:
 *       1. Элементы имеют разные знаки (один +, другой -)
 *       2. Сумма элементов < givenNumber
 * @note Возвращает индекс ПЕРВОГО элемента пары
 * @warning Если size < 2, возвращает -1
 * @example Для массива [10, -5, 3, -8] и givenNumber = 0:
 *          Пара [0] и [1]: 10 и -5, сумма = 5, 5 < 0? НЕТ
 *          Пара [1] и [2]: -5 и 3, сумма = -2, -2 < 0? ДА → вернет 1
 */
int findFirstPairWithDifferentSigns(int* arr, const size_t size, int givenNumber);

/**
 * @brief Перечисление способов заполнения массива
 */
enum { RANDOM = 1, MANUAL };

/**
 * @brief Главная функция программы
 *
 * @return int Код завершения программы (0 - успех)
 *
 * @note Выполняет все три задания по порядку
 * @note Выделяет и освобождает динамическую память
 * @note Предлагает выбор способа заполнения массива
 */
int main()
{
    // Устанавливаем русскую локаль для вывода и ввода
    setlocale(LC_ALL, "Russian");
    srand((unsigned int)time(NULL));

    size_t size = getSize("Введите размер массива:  ");
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }

    printf("Выберите способ заполнения массива:\n"
        "%d - случайными числами, %d - вручную: ", RANDOM, MANUAL);
    int choice = Value();
    switch (choice)
    {
    case RANDOM:
        fillRandom(arr, size);
        break;
    case MANUAL:
        fillArray(arr, size);
        break;
    default:
        printf("Некорректный выбор\n");
        free(arr);
        return 1;
    }

    printf("Исходный массив:\n");
    printArray(arr, size);

    // Задание 1
    int sum = sumTwoDigitPositive(arr, size);
    printf("\n1. Сумма положительных двузначных элементов: %d\n", sum);

    // Задание 2
    int* copyArr = malloc(size * sizeof(int));
    if (copyArr == NULL)
    {
        printf("Ошибка выделения памяти\n");
        free(arr);
        exit(1);
    }
    for (size_t i = 0; i < size; i++) {
        copyArr[i] = arr[i];
    }
    multiplyEvenPositiveByLast(copyArr, size);
    printf("2. Массив после умножения четных положительных на последний элемент:\n");
    printArray(copyArr, size);

    // Задание 3
    printf("\n3. Введите число для сравнения: ");
    int givenNumber = Value();
    int pairIndex = findFirstPairWithDifferentSigns(arr, size, givenNumber);
    if (pairIndex != -1) {
        printf("Первая пара соседних элементов с разными знаками, сумма которых меньше %d: \n", givenNumber);
        printf("Элементы [%d] = %d и [%d] = %d (индекс первого элемента: %d)\n",
            pairIndex, arr[pairIndex], pairIndex + 1, arr[pairIndex + 1], pairIndex);
    }
    else {
        printf("Такая пара не найдена\n");
    }

    free(copyArr);
    free(arr);
    return 0;
}

int Value()
{
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        printf("Ошибка ввода\n");
        while (getchar() != '\n');
        abort();
    }
    return value;
}

size_t getSize(char* message)
{
    printf("%s", message);
    int value = Value();
    if (value <= 0)
    {
        printf("Размер должен быть положительным\n");
        abort();
    }
    return (size_t)value;
}

void fillArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("Введите элемент arr[%zu] = ", i);
        arr[i] = Value();
        while (arr[i] < -1000 || arr[i] > 1000) {
            printf("Число должно быть в интервале [-1000, 1000]. Введите снова: ");
            arr[i] = Value();
        }
    }
}

void fillRandom(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = (rand() % 2001) - 1000;
    }
}

void printArray(int* arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sumTwoDigitPositive(int* arr, const size_t size)
{
    int result = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0) {
            if (arr[i] >= 10 && arr[i] <= 99) {
                result += arr[i];
            }
        }
    }
    return result;
}

void multiplyEvenPositiveByLast(int* arr, const size_t size)
{
    if (size == 0) return;

    int lastElement = arr[size - 1];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0 && arr[i] % 2 == 0) {
            arr[i] *= lastElement;
        }
    }
}

int findFirstPairWithDifferentSigns(int* arr, const size_t size, int givenNumber)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        if ((arr[i] > 0 && arr[i + 1] < 0) || (arr[i] < 0 && arr[i + 1] > 0))
        {
            if (arr[i] + arr[i + 1] < givenNumber) {
                return (int)i;
            }
        }
    }
    return -1;
}
