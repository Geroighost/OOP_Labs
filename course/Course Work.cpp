#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include "CourseworkLib.h"
#include "Pharmacy.h"

using namespace std;

void menu(Pharmacy*&, int&);
void add(Pharmacy*&, int&);
void record_in_file(Pharmacy*&, int);
void edit(Pharmacy*&, int);
void deleting(Pharmacy*&, int&);
void search(Pharmacy*, int);
void read_number_from_file(int&);
void read_elements_from_file(Pharmacy*&, int);
void output_data_on_monitor(Pharmacy*, int);
void calculation_discount(Pharmacy*, int);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUSSIAN");
    int number_of_medicines = 0;
    cout << "Please, change font of the console to Consolas or Lucida!" << endl;
    read_number_from_file(number_of_medicines);
    Pharmacy* Medicines = new Pharmacy[number_of_medicines];
    read_elements_from_file(Medicines, number_of_medicines);
    menu(Medicines, number_of_medicines);
    cout << "End of the program.\n";
    system("pause");
    return 0;
}