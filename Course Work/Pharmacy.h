#pragma once
#include <string>
#include <iostream>

using namespace std;

class Pharmacy
{
protected:
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

class Pills : public Pharmacy
{
private:
	string form;
	string distribution_method;
public:
	Pills();
	~Pills();
	friend ostream& operator<< (ostream& out, const Pills& Pills);
	void Set_Form(string row) { form = row; }
	void Set_Distribution_method(string row) { distribution_method = row; }
	string Get_Form() { return form; }
	string Get_Distribution_method() { return distribution_method; }
	string output_in_file();
	void writeToBinStream(ostream& stream)
	{
		stream.write((char*)&name, sizeof(name));
		stream.write((char*)&form, sizeof(form));
		stream.write((char*)&distribution_method, sizeof(distribution_method));
		stream.write((char*)&manufacturer, sizeof(manufacturer));
		stream.write((char*)&price, sizeof(price));
		stream.write((char*)&discount, sizeof(discount));
	}
};

class Devices : public Pharmacy
{
private:
	int level_of_security;
	int operation_period;
public:
	Devices();
	~Devices();
	friend ostream& operator<< (ostream& out, const Devices& Devices);
	void Set_Level_of_security(int number) { level_of_security = number; }
	void Set_Operation_period(int number) { operation_period = number; }
	int Get_Level_of_security() { return level_of_security; }
	int Get_Operation_period() { return operation_period; }
	string output_in_file();
	void writeToBinStream(ostream& stream)
	{
		stream.write((char*)&name, sizeof(name));
		stream.write((char*)&level_of_security, sizeof(level_of_security));
		stream.write((char*)&manufacturer, sizeof(manufacturer));
		stream.write((char*)&operation_period, sizeof(operation_period));
		stream.write((char*)&price, sizeof(price));
		stream.write((char*)&discount, sizeof(discount));
	}
};