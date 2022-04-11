#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <Windows.h>
#include "Top_Gear.h"

using namespace std;

void number_of_structs(fstream &, int &, int &);
void createstructs(fstream &, int, struct car*&);
void create_new_struct(int, struct car*&);
void display(struct car*, int);
void add(struct car*&, int &);
void del(struct car*, int &);
void search(struct car*, int);
void calculation(struct car*, int);
void edit(struct car*&, int);
void rewrite(struct car*, int);
void menu(struct car*&, int &);

int main()
{
    setlocale(LC_ALL, "Russian");
    int number_of_cars = 0, bool_number = 0;
    fstream my_file;
    number_of_structs(my_file, number_of_cars, bool_number);
	if (bool_number == 0)
	{
    car* cars = new car[number_of_cars];
    createstructs(my_file, number_of_cars, cars);
    menu(cars, number_of_cars);
	}
    system("pause");
    return 0;
}