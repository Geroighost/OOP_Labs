#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include "PWorkLib.h"
#include "Calls.h"

using namespace std;

void menu(Calls*&, int&);
void add(Calls*&, int&);
void record_in_file(Calls*&, int);
void edit(Calls*&, int);
void sorting(Calls*, int);
void read_number_from_file(int&);
void read_elements_from_file(Calls*&, int);
void output_data_on_monitor(Calls*, int);
void for_sorting(Calls*, int, int, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, float&);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUSSIAN");
    int number_of_numbers = 0;
    cout << "Please, change font of the console to Consolas or Lucida!" << endl;
    read_number_from_file(number_of_numbers);
    Calls* My_Calls = new Calls[number_of_numbers];
    read_elements_from_file(My_Calls, number_of_numbers);
    menu(My_Calls, number_of_numbers);
    cout << "End of the program.\n";
    system("pause");
    return 0;
}