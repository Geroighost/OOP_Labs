#include <iostream>
#include <time.h>

using namespace std;

void setvalue(int*, int);
void setvalue(float*, int);
void print(int*, int);
void print(float*, int);
void printquestion(int*, float*, int, int);
void min_mod_choice(int*, float*, int, int);
void sum_of_elements_choice(int*, float*, int, int);
void min_mod(int*, int);
void min_mod(float*, int);
void sum_of_elements(int*, int);
void sum_of_elements(float*, int);

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int celye, veshestv, answer, o3;
	o3 = 0;
	printf_s("Введите количество элементов массива целых чисел: ");
	scanf_s("%i", &celye);
	int* p = new int[celye];
	printf_s("Введите количество элементов массива веществ. чисел: ");
	scanf_s("%i", &veshestv);
	float* t = new float[veshestv];
	printf_s("Создаём массивы...");
	setvalue(p, celye);
	setvalue(t, veshestv);
	printquestion(p, t, celye, veshestv);
	do
	{
		printf_s("\nВыберите пункт из меню:\n1. Номер минимального по модулю элемента массива.\n2. Сумму модулей элементов массива, расположенных после первого отрицательного элемента.\n3. Выход");
		printf_s("\nОтвет: ");
		scanf_s("%i", &answer);
		switch (answer)
		{
		case 1:
		{
			min_mod_choice(p, t, celye, veshestv);
		}
		break;
		case 2:
		{
			sum_of_elements_choice(p, t, celye, veshestv);
		}
		break;
		case 3:
		{
			o3++;
		}
		break;
		default: printf_s("Введёное вами число не из меню.");
		}
	} while (o3 == 0);
	printf_s("Конец программы.");
	return 0;
}

void setvalue(int* x, int m)
{
	srand(time(NULL));
	for (int j = 0; j < m; j++) x[j] = rand() % 101;
}

void setvalue(float* x, int m)
{
	srand(time(NULL));
	for (int j = 0; j < m; j++) x[j] = (float)(rand() % 20) * 0.001;
}

void print(int* x, int m)
{
	printf_s("\n");
	for (int j = 0; j < m; j++) printf_s("%i ", x[j]);
}

void print(float* x, int m)
{
	printf_s("\n");
	for (int j = 0; j < m; j++) printf_s("%0.3f ", x[j]);
}

void printquestion(int* p, float* t, int x, int y)
{
	int answer3, answer4, check;
	check = 0;
	printf_s("\nЖелаете вывести массивы на экран?\n1. Да\n2. Нет");
	printf_s("\nОтвет: ");
	scanf_s("%i", &answer3);
	switch (answer3)
	{
	case 1:
	{
		printf_s("\nВаш массив из целых чисел:");
		print(p, x);
		printf_s("\nВаш массив из веществ. чисел:");
		print(t, y);
		do
		{
			printf_s("\nЖелаете повторить?\n1. Да\n2. Нет");
			printf_s("\nОтвет: ");
			scanf_s("%i", &answer4);
			switch (answer4)
			{
			case 1:
			{
				printf_s("\nВаш массив из целых чисел:");
				print(p, x);
				printf_s("\nВаш массив из веществ. чисел:");
				print(t, y);
			}
			break;
			case 2:
			{
				check++;
			}
			break;
			default: printf_s("Непонятное число.");
			}
		} while (check == 0);
		check = 0;
	}
	break;
	case 2: break;
	}
}

void min_mod(int* x, int m)
{
	int min_mod, number = 0;
	min_mod = 100;
	for (int j = 0; j < m; j++) if (abs(x[j]) < min_mod) min_mod = x[j];
	for (int j = 0; j < m; j++) if (min_mod == abs(x[j])) number = j;
	printf_s("\nНомер минимального по модулю эелмента у целых чисел: %i", number+1);
}

void min_mod(float* x, int m)
{
	int number = 0;
	float min_mod = 100;
	for (int j = 0; j < m; j++) if (abs(x[j]) < min_mod) min_mod = x[j];
	for (int j = 0; j < m; j++) if (min_mod == abs(x[j])) number = j;
	printf_s("\nНомер минимального по модулю эелмента у веществ. чисел: %i", number+1);
}

void sum_of_elements(int* x, int m)
{
	int sum = 0, o_bool = 0;
	for (int j = 0; j < m; j++)
	{
		if (x[j] < 0 && o_bool == 0)
		{
			o_bool++;
		}
		if (o_bool == 1)
		{
			sum = sum + x[j];
		}
	}
	if (o_bool == 1) printf_s("\nСумма чисел: %i", sum);
	if (o_bool == 0) printf_s("\nСреди элементов массива нет отрицательных чисел.");
}

void sum_of_elements(float* x, int m)
{
	int o_bool = 0;
	float sum = 0;
	for (int j = 0; j < m; j++)
	{
		if (x[j] < 0 && o_bool == 0)
		{
			o_bool++;
		}
		if (o_bool == 1)
		{
			sum = sum + x[j];
		}
	}
	if (o_bool == 1) printf_s("\nСумма чисел до минимального элемента: %0.3f", sum);
	if (o_bool == 0) printf_s("\nСреди элементов массива нет отрицательных чисел.");
}

void min_mod_choice(int* p, float* t, int x, int y)
{
	int answer5, answer6, check, justcheck;
	check = 0;
	justcheck = 0;
	do
	{
		printf_s("\nДля какого массива вы хотите вывести модуль?\n1. Из целых\n2. Из вещественных\n3. Выход");
		printf_s("\nОтвет: ");
		scanf_s("%i", &answer5);
		switch (answer5)
		{
		case 1:
		{
			min_mod(p, x);

		}
		break;
		case 2:
		{
			min_mod(t, y);
		}
		break;
		case 3:
		{
			check++;
		}
		break;
		default: printf_s("Непонятное число.");
		}
		if (answer5 != 3)
		{
			printf_s("\nЖелаете повторить?\n1. Да\n2. Нет");
			do
			{
				printf_s("\nОтвет: ");
				scanf_s("%i", &answer6);
				switch (answer6)
				{
				case 1:
				{
					justcheck++;
				}
				break;
				case 2:
				{
					check++;
					justcheck++;
				}
				break;
				default: printf_s("Непонятное число.");
				}
			} while (justcheck == 0);
			justcheck = 0;
		}
	} while (check == 0);
}

void sum_of_elements_choice(int* p, float* t, int x, int y)
{
	int answer7, answer8, check, justcheck;
	check = 0;
	justcheck = 0;
	do
	{
		printf_s("\nДля какого массива вы хотите вывести сумму?\n1. Из целых\n2. Из вещественных\n3. Выход");
		printf_s("\nОтвет: ");
		scanf_s("%i", &answer7);
		switch (answer7)
		{
		case 1:
		{
			sum_of_elements(p, x);

		}
		break;
		case 2:
		{
			sum_of_elements(t, y);
		}
		break;
		case 3:
		{
			check++;
		}
		break;
		default: printf_s("Непонятное число.");
		}
		if (answer7 != 3)
		{
			printf_s("\nЖелаете повторить?\n1. Да\n2. Нет");
			do
			{
				printf_s("\nОтвет: ");
				scanf_s("%i", &answer8);
				switch (answer8)
				{
				case 1:
				{
					justcheck++;
				}
				break;
				case 2:
				{
					check++;
					justcheck++;
				}
				break;
				default: printf_s("Непонятное число.");
				}
			} while (justcheck == 0);
			justcheck = 0;
		}
	} while (check == 0);
}