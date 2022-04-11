#pragma once
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
	friend Vector operator+(const Vector& N1, const Vector& N2);
	friend Vector operator*(const Vector&, int);
	int Get_num1() { return number1; }
	int Get_num2() { return number2; }
	int Get_num3() { return number3; }
	int Get_num4() { return number4; }
};

