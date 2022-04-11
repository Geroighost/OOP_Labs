#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	//Определение переменных.
	setlocale(LC_ALL, "Russian");
	FILE* myfile;
	int number, number_in_file = 1, o_bool = 0, o_bool1 = 0, n, * mass_number = 0;
	//Открытие файла.
	fopen_s(&myfile, "log.dat", "wb+");
	//Ввод чисел и их запись в файл.
	cout << "Введите количество чисел для ввода в файл:\n> ";
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		number_in_file = number_in_file * 3;
		fwrite(&number_in_file, sizeof(int), 1, myfile); //Запись в файл.
	}
	mass_number = new int[number];
	fseek(myfile, 0L, SEEK_SET); //Возвращение к началу файла.
	fread(mass_number, sizeof(int), number, myfile); //Запись number-элементов в массив mass_number.
	fseek(myfile, 0L, SEEK_SET); //Возвращение к началу файла. 
	//Сравнительная проверка.
	for (int i = 0; i < number; i++)
	{
		fseek(myfile, 1L, SEEK_CUR); //Перемещение на один байт.
		n = ftell(myfile); //Получение позиции-байта и передача значения в n.
		//Само сравнение.
		if (n % 2 == 0)
		{
			cout << mass_number[i] << " ";
		}
	}
	cout << endl;
	fclose(myfile); //Закрытие файла.
	system("pause");
	return 0;
}