#include "Vector.h"

Vector::Vector()
{
	number1 = 0;
	number2 = 0;
	number3 = 0;
	number4 = 0;
}

Vector:: Vector(int num1, int num2, int num3, int num4)
{
	number1 = num1;
	number2 = num2;
	number3 = num3;
	number4 = num4;
}

Vector operator+(const Vector& N1, const Vector& N2)
{
	Vector VectorSum;
	VectorSum.number1 = N1.number1 + N2.number1;
	VectorSum.number2 = N1.number2 + N2.number2;
	VectorSum.number3 = N1.number3 + N2.number3;
	VectorSum.number4 = N1.number4 + N2.number4;
	return VectorSum;
}

Vector operator*(const Vector& N1, int num)
{
	Vector VectorTimes;
	VectorTimes.number1 = N1.number1 * num;
	VectorTimes.number2 = N1.number2 * num;
	VectorTimes.number3 = N1.number3 * num;
	VectorTimes.number4 = N1.number4 * num;
	return VectorTimes;
}