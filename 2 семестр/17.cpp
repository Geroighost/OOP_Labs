#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char mainrow[200];
	fstream myfile;
	char b[200];
	string mainrows;
	cout << "Введите путь текстового файла (на английском):\n> ";
	gets_s(b);
	myfile.open(b);
	if (myfile.is_open())
	{
		int number = 0;
		while (!myfile.eof())
		{
			myfile.getline(mainrow, 200);
			mainrows = mainrow;
			if (mainrow[0] == mainrows[mainrows.size() - 1]) number++;
		}
		cout << "Количество строк: " << number << endl;
	}
	else
	{
		cout << "Файл не найден.";
	}
	system("pause");
	return 0;
}