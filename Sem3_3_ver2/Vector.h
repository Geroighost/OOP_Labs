#pragma once
#include <iostream>

using namespace std;

class Vector
{
private:
	int number1;
	int number2;
	int number3;
	int number4;
public:
	Vector(int num1, int num2, int num3, int num4);
	Vector();
	friend Vector operator+ (const Vector& N1, const Vector& N2);
	friend Vector operator* (const Vector&, int);
	friend ostream& operator<< (ostream& out, const Vector& N1);
	int Get_num1() { return number1; }
	int Get_num2() { return number2; }
	int Get_num3() { return number3; }
	int Get_num4() { return number4; }
	void Set_num1(int number) { number1 = number; }
	void Set_num2(int number) { number2 = number; }
	void Set_num3(int number) { number3 = number; }
	void Set_num4(int number) { number4 = number; }
};
