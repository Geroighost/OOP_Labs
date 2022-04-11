#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include "PWorkLib.h"
#include "Library.h"

using namespace std;

void menu(Library*&, int&);
void add(Library*&, int&);
void record_in_file(Library*&, int);
void edit(Library*&, int);
void deleting(Library*&, int&);
void search(Library*, int);
void read_number_from_file(int&);
void read_elements_from_file(Library*&, int);
void output_data_on_monitor(Library*, int);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUSSIAN");
    int number_of_books = 0;
    cout << "Please, change font of the console to Consolas or Lucida!" << endl;
    read_number_from_file(number_of_books);
    Library* My_Library = new Library[number_of_books];
    read_elements_from_file(My_Library, number_of_books);
    menu(My_Library, number_of_books);
    cout << "End of the program.\n";
    system("pause");
    return 0;
}