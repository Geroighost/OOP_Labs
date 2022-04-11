#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include "Mine.h"

using namespace std;

void number_of_structs(fstream&, int&, int&);
void createstructs(fstream&, int, struct home_library*&);
void create_new_struct(int, struct home_library*&);
void display(struct home_library*, int);
void add(struct home_library*&, int&);
void del(struct home_library*, int&);
void search(struct home_library*, int);
void calculation(struct home_library*, int);
void edit(struct home_library*&, int);
void rewrite(struct home_library*, int);
void menu(struct home_library*&, int&);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUSSIAN");
    int number_of_books = 0, bool_number = 0;
    cout << "Please, change font of the console to Consolas or Lucida!" << endl;
    fstream my_file;
    number_of_structs(my_file, number_of_books, bool_number);
    if (bool_number == 0)
    {
        home_library* books = new home_library[number_of_books];
        createstructs(my_file, number_of_books, books);
        menu(books, number_of_books);
    }
    cout << "Сеанс закончен.\n";
    system("pause");
    return 0;
}