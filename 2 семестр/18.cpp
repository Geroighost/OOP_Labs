#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <windows.h>

using namespace std;

struct books_struct
{
	string AUTHOR;
	string NAME;
	string PUBLISHER;
	string YEAR;
};

void create_new_file();
void vvod(fstream&);
void add_underscores(string&);
void delete_underscores(string&);
void while_check(int&);
void number_of_structs(fstream&, int&);
void create_new_structs(fstream&, struct books_struct*&, int&);
void search_FIO(struct books_struct*, int);
void search_first_symbol(struct books_struct*, int);
void search_1985(struct books_struct*, int);
void search_author_1984(struct books_struct*, int);
void menu(struct books_struct*&, int);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUSSIAN");
	int number = 0;
	fstream my_file;
	create_new_file();
	vvod(my_file);
	number_of_structs(my_file, number);
	books_struct* book_s = new books_struct[number];
	create_new_structs(my_file, book_s, number);
	menu(book_s, number);
	return 0;
}

void create_new_file()
{
	ofstream ofs("log.txt");
	ofs.open("log.txt");
	ofs.close();
}

void vvod(fstream& a)
{
	int o_bool = 0, o_check = 0;
	string word;
	books_struct books;
	a.open("log.txt");
	do
	{
		int f;
		if (o_check != 0) a << "\n";
		cout << "Введите автора (не более 25-ти символов):\n> ";
		getline(cin, word);
		f = word.length();
		if (f <= 25)
		{
			add_underscores(word);
			books.AUTHOR = word;
		}
		else do
		{
			cout << "Строка превышает допустимое значение (в строке содержится " << word.length() << " символов). Повторите ввод.\n> ";
			getline(cin, word);
			f = word.length();
			if (f <= 25)
			{
				add_underscores(word);
				books.AUTHOR = word;
			}
		} while (f > 25);
		cout << "Введите название книги (не более 40-ка символов):\n> ";
		getline(cin, word);
		f = word.length();
		if (f <= 40)
		{
			add_underscores(word);
			books.NAME = word;
		}
		else do
		{
			cout << "Строка превышает допустимое значение (в строке содержится " << word.length() << " символов). Повторите ввод.\n> ";
			getline(cin, word);
			f = word.length();
			if (f <= 40)
			{
				add_underscores(word);
				books.NAME = word;
			}
		} while (f > 40);
		cout << "Введите издателя (не более 20-ти символов):\n> ";
		getline(cin, word);
		f = word.length();
		if (f <= 20)
		{
			add_underscores(word);
			books.PUBLISHER = word;
		}
		else do
		{
			cout << "Строка превышает допустимое значение (в строке содержится " << word.length() << " символов). Повторите ввод.\n> ";
			getline(cin, word);
			f = word.length();
			if (f <= 20)
			{
				add_underscores(word);
				books.PUBLISHER = word;
			}
		} while (f > 20);
		cout << "Введите год издания (не более 4-х символов):\n> ";
		getline(cin, word);
		f = word.length();
		if (f <= 4) books.YEAR = word;
		else do
		{
			cout << "Строка превышает допустимое значение (в строке содержится " << word.length() << " символов). Повторите ввод.\n> ";
			getline(cin, word);
			f = word.length();
			if (f <= 4) books.YEAR = word;
		} while (f > 4);
		a << books.AUTHOR << " " << books.NAME << " " << books.PUBLISHER << " " << books.YEAR;
		o_check++;
		while_check(o_bool);
		cin.ignore(255, '\n');
	} while (o_bool == 0);
	a.close();
}

void add_underscores(string& str)
{
	int n = str.length(), i = 0;
	while (i < n)
	{
		if (str[i] == ' ')
		{
			str.replace(i, 1, "_");
		}
		i++;
	}
}

void delete_underscores(string& str)
{
	int n = str.length(), i = 0;
	while (i < n)
	{
		if (str[i] == '_')
		{
			str.replace(i, 1, " ");
		}
		i++;
	}
}

void while_check(int& a)
{
	int symbol, o1_bool = 0;
	cout << "Хотите добавить ещё одну строку?\n1. Да\n2. Нет\n";
	do
	{
		cout << "> ";
		cin >> symbol;
		switch (symbol)
		{
		case 1:
		{
			o1_bool++;
		}break;
		case 2:
		{
			a++;
			o1_bool++;
		} break;
		default: "Данное число не из меню.";
		}
	} while (o1_bool == 0);
}

void number_of_structs(fstream& a, int& b)
{
	char mainrow[200];
	a.open("log.txt");
	while (!a.eof())
	{
		a.getline(mainrow, 200);
		b++;
	}
	a.close();
}

void create_new_structs(fstream& a, books_struct*& b, int& c)
{
	string my_string;
	a.open("log.txt");
	for (int i = 0; i < c; i++)
	{
		a >> my_string;
		delete_underscores(my_string);
		b[i].AUTHOR = my_string;
		a >> my_string;
		delete_underscores(my_string);
		b[i].NAME = my_string;
		a >> my_string;
		delete_underscores(my_string);
		b[i].PUBLISHER = my_string;
		a >> my_string;
		delete_underscores(my_string);
		b[i].YEAR = my_string;
	}
	a.close();
}

void search_FIO(books_struct* a, int b)
{
	int o_bool = 0, number;
	string word;
	do
	{
		int o2_bool = 0;
		cout << "Введите фамилию и инициалы автора: " << endl;
		cin.ignore(255, '\n');
		cout << "> ";
		getline(cin, word);
		for (int i = 0; i < b; i++)
		{
			if (a[i].AUTHOR == word)
			{
				cout << a[i].AUTHOR << " " << a[i].NAME << " " << a[i].PUBLISHER << " " << a[i].YEAR << endl;
				o2_bool++;
			}
		}
		if (o2_bool == 0) cout << "Таких записей не обнаружено." << endl;
		cout << "Желаете повторить?\n1. Да.\n2. Нет.\n";
		int oo_bool = 0;
		do
		{
			cout << "> ";
			cin >> number;
			switch (number)
			{
			case 1: 
			{
				oo_bool++;
			} break;
			case 2:
			{
				o_bool++;
				oo_bool++;
			} break;
			default: cout << "Данное число не из меню.";
			}
		} while (oo_bool == 0);
	} while (o_bool == 0);
}

void search_first_symbol(books_struct* a, int b)
{
	int o_bool = 0, number;
	char symbol;
	do
	{
		int o2_bool = 0;
		cout << "Введите первую букву фамилии автора: " << endl;
		cout << "> ";
		cin >> symbol;
		for (int i = 0; i < b; i++)
		{
			if (a[i].AUTHOR[0] == symbol)
			{
				cout << a[i].AUTHOR << " " << a[i].NAME << " " << a[i].PUBLISHER << " " << a[i].YEAR << endl;
				o2_bool++;
			}
		}
		if (o2_bool == 0) cout << "Таких записей не обнаружено." << endl;
		cout << "Желаете повторить?\n1. Да.\n2. Нет.\n";
		int oo_bool = 0;
		do
		{
			cout << "> ";
			cin >> number;
			switch (number)
			{
			case 1:
			{
				oo_bool++;
			} break;
			case 2:
			{
				o_bool++;
				oo_bool++;
			} break;
			default: cout << "Данное число не из меню.";
			}
		} while (oo_bool == 0);
	} while (o_bool == 0);
}

void search_1985(books_struct* a, int b)
{
	int o_bool = 0;
	for (int i = 0; i < b; i++)
	{
		if (a[i].YEAR < "1985")
		{
			cout << a[i].AUTHOR << " " << a[i].NAME << " " << a[i].PUBLISHER << " " << a[i].YEAR << endl;
			o_bool++;
		}
	}
	if (o_bool == 0) cout << "Таких записей не обнаружено." << endl;
}

void search_author_1984(books_struct* a, int b)
{
	int o_bool = 0, number, number2;
	string word, word2, word3;
	do
	{
		cin.ignore(255, '\n');
		int o2_bool = 0, o3_bool = 0;
		cout << "Введите фамилию автора: " << endl;
		cout << "> ";
		getline(cin, word);
		for (int i = 0; i < b; i++)
		{
			word3 = a[i].AUTHOR;
			number2 = word3.find(' ', 0);
			word2.append(word3, 0, number2);
			if (word2 == word) if(a[i].YEAR < "1984")
			{
				cout << a[i].AUTHOR << " " << a[i].NAME << " " << a[i].PUBLISHER << " " << a[i].YEAR << endl;
				o2_bool++;
			}
		}
		if (o2_bool == 0) cout << "Таких записей не обнаружено." << endl;
		cout << "Желаете повторить?\n1. Да.\n2. Нет.\n";
		int oo_bool = 0;
		do
		{
			cout << "> ";
			cin >> number;
			switch (number)
			{
			case 1:
			{
				oo_bool++;
			} break;
			case 2:
			{
				o_bool++;
				oo_bool++;
			} break;
			default: cout << "Данное число не из меню.";
			}
		} while (oo_bool == 0);
	} while (o_bool == 0);
}

void menu(books_struct*& a, int b)
{
	int number_in_menu, o_bool = 0;
	do
	{
		printf_s("1. Вывод записей с заданной фамилией и инициалами.\n2. Вывод записей с заданной первой буквой фамилии.\n3. Вывод записей о книгах, изданных до 1985.\n4. Вывод записей о книгах, изданных конкретным автором до 1984 года.\n5. Закончить работу.\n");
		cout << "> ";
		cin >> number_in_menu;
		switch (number_in_menu)
		{
		case 1:
		{
			search_FIO(a, b);
		}
		break;
		case 2:
		{
			search_first_symbol(a, b);
		} break;
		case 3:
		{
			search_1985(a, b);
		} break;
		case 4:
		{
			search_author_1984(a, b);
		} break;
		case 5:
		{
			o_bool = 1;
		} break;
		default: cout << "\nВведёное вами число не из меню.";
		}
	} while (o_bool == 0);
}