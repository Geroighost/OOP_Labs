#pragma once
#include <string>
#include <iostream>

using namespace std;

class Pharmacy
{
private:
	string name;
	string manufacturer;
	float price;
	float discount;
public:
	Pharmacy();
	void Price_with_discount();
	~Pharmacy();
	void Set_Name(string row) { name = row; }
	void Set_Manufacturer(string row) { manufacturer = row; }
	void Set_Price(float number) { price = number; }
	void Set_Discount(float number) { discount = number; }
	string Get_Name() { return name; }
	string Get_Manufacturer() { return manufacturer; }
	float Get_Price() { return price; }
	float Get_Discount() { return discount; }
};