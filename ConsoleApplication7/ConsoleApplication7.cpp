#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char mainrow[200], *row_for_strchr;
	fstream myfile;
	char b[200];
	cout << "Введите путь текстового файла:\n> ";
	gets_s(b);
	myfile.open(b);
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile.getline(mainrow, 200);
			row_for_strchr = strchr(mainrow, ' ');
			if (row_for_strchr != NULL)
			{
				cout << mainrow << endl;
			}
		}
	}
	else
	{
		cout << "Файл не найден.";
	}
	system("pause");
	return 0;
}