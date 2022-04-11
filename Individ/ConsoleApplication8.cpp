#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "Mysterylib.h"

using namespace std;

void number_of_structs(fstream &, int &, int &);
void createstructs(fstream &, int, struct tv*&);
void create_new_struct(int, struct tv*&);
void display(struct tv*, int);
void add(struct tv*&, int &);
void del(struct tv*, int &);
void search(struct tv*, int);
void calculation(struct tv*, int);
void edit(struct tv*&, int);
void rewrite(struct tv*, int);
void menu(struct tv*&, int &);

int main()
{
    setlocale(LC_ALL, "Russian");
    int number_of_tv = 0, bool_number = 0;
    fstream my_file;
    number_of_structs(my_file, number_of_tv, bool_number);
	if (bool_number == 0)
	{
    tv* tv_s = new tv[number_of_tv];
    createstructs(my_file, number_of_tv, tv_s);
    menu(tv_s, number_of_tv);
	}
    cout << "Сеанс закончен.\n";
    system("pause");
    return 0;
}