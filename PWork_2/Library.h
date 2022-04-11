#pragma once

#include <string>
#include <iostream>

using namespace std;

class Library
{
private:
	string name;
	string author;
	int year;
	int quantity;
public:
	Library();
	~Library();
	void Set_Name(string row) { name = row; }
	void Set_Author(string row) { author = row; }
	void Set_Year(int number) { year = number; }
	void Set_Quantity(int number) { quantity = number; }
	string Get_Name() { return name; }
	string Get_Author() { return author; }
	int Get_Year() { return year; }
	int Get_Quantity() { return quantity; }
};

