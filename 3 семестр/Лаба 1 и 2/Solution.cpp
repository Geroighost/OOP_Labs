#include "Solution.h"
#include <iostream>
#include <fstream>
using namespace std;

void Solution::method_Discriminant(float& x1, float& x2)
{
	float D;
	D = pow(number_b, 2) + (4 * number_a * number_c);
	x1 = ((-number_b) + sqrt(D)) / (2 * number_a);
	x2 = ((-number_b) - sqrt(D)) / (2 * number_a);
}

void Solution::method_coef_prop(float& x1, float& x2)
{
	float number;
	number = number_a + number_b + number_c;
	if (number == 0)
	{
		x1 = 1;
		x2 = number_c / number_a;
	}
	else method_Discriminant(x1, x2);
}

Solution::Solution()
{
	number_a = 1;
	number_b = 1;
	number_c = 1;
}

Solution::Solution(float a, float b, float c)
{
	number_a = a;
	number_b = b;
	number_c = c;
}

Solution::~Solution()
{
	ofstream myfile;
	myfile.open("log.txt");
	if (myfile.is_open())
	{
		myfile << number_a << " ";
		myfile << number_b << " ";
		myfile << number_c << " ";
	}
}
