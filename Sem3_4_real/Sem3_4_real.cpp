#include "Zhir.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	Zhir Massives_Methods;
	int n;
	cout << "Введите N:\n> ";
	cin >> n;
	int * int_numbers = new int[n];
	float* float_numbers = new float[n];
	double* double_numbers = new double[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		int_numbers[i] = rand() % 101 - 100;
		float_numbers[i] = (0.01 * (rand() % 101)) - 10;
		double_numbers[i] = (0.001 * (rand() % 101)) - 10;
	}
	cout << "Ваши массивы:\nint: ";
	for (int i = 0; i < n; i++)
	{
		cout << int_numbers[i];
		if (i != n - 1) cout << " ";
	}
	cout << "\nfloat: ";
	for (int i = 0; i < n; i++)
	{
		cout << float_numbers[i];
		if (i != n - 1) cout << " ";
	}
	cout << "\ndouble: ";
	for (int i = 0; i < n; i++)
	{
		cout << double_numbers[i];
		if (i != n - 1) cout << " ";
	}
	cout << endl;
	Massives_Methods.Find_max_negative_element(int_numbers, n);
	Massives_Methods.Find_max_negative_element(float_numbers, n);
	Massives_Methods.Find_max_negative_element(double_numbers, n);
	system("pause");
	return 0;
}