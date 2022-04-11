#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	FILE* myfile;
	int number, o = 0, n;
	double number_in_file, number_for_check, *mass_number = 0, answer;
	fopen_s(&myfile, "log.dat", "wb+");
	cout << "Введите количество чисел для ввода в файл:\n";
	cin >> number;
	cout << "Вводите числа.\n";
	for (int i = 0; i < number; i++)
	{
		cout << "> ";
		cin >> number_in_file;
		fwrite(&number_in_file, sizeof(double), 1, myfile);
	}
	cout << "Запись завершена.\nВведите число для проверки:\n";
	cin >> number_for_check;
	mass_number = new double[number];
	fseek(myfile, 0L, SEEK_SET);
	fread(mass_number, sizeof(double), number, myfile);
	fseek(myfile, 0L, SEEK_SET);
	for (int i = 0; i < number; i++)
	{
		fseek(myfile, 1L, SEEK_CUR);
		n = ftell(myfile);
		if (n % 2 == 0) if (mass_number[i] < number_for_check)
		{
			o++;
			answer = mass_number[i];
			if (o == 1)
			{
				cout << "Ответ: " << mass_number[i];
			}
			if (o >= 2)
			{
				cout << "  " << mass_number[i];
			}
		}
	}
	cout << endl;
	fclose(myfile);
	system("pause");
	return 0;
}