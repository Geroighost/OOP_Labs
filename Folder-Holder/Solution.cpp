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
	cout << "1cl destroyed." << endl;
}

void Solution::Just_a_method()
{
	cout << "Method from clss for smrt." << endl;
}

void Solution::Just_another_method_with_override()
{
	cout << "Values was set in first class." << endl;
}

float Cubic_Solution::cubic_Solution_Method(float *x)
{
	float M_PI = 3.14, M_2PI = (2 * M_PI);
	float q, r, r2, q3;
	q = ((number_a * number_a) - 3. * number_b) / 9.; r = (number_a * (2. * number_a * number_a - 9. * number_b) + 27. * number_c) / 54.;
	r2 = r * r; q3 = q * q * q;
	if (r2 < q3) {
		double t = acos(r / sqrt(q3));
		number_a /= 3.; q = -2. * sqrt(q);
		x[0] = q * cos(t / 3.) - number_a;
		x[1] = q * cos((t + M_2PI) / 3.) - number_a;
		x[2] = q * cos((t - M_2PI) / 3.) - number_a;
		return(3);
	}
	else {
		double aa, bb;
		if (r <= 0.) r = -r;
		aa = -pow(r + sqrt(r2 - q3), 1. / 3.);
		if (aa != 0.) bb = q / aa;
		else bb = 0.;
		number_a /= 3.; q = aa + bb; r = aa - bb;
		x[0] = q - number_a;
		x[1] = (-0.5) * q - number_a;
		x[2] = (sqrt(3.) * 0.5) * fabs(r);
		if (x[2] == 0.) return(2);
		return(1);
	}
}

Cubic_Solution::Cubic_Solution()
{
	number_a = 0;
	number_b = 0;
	number_c = 0;
}

Cubic_Solution::Cubic_Solution(float a, float b, float c)
{
	number_a = a;
	number_b = b;
	number_c = c;
}

void Cubic_Solution::Just_another_method_with_override()
{
	cout << "Values was set in second class." << endl;
}

void Third_Class::Just_another_method_with_override()
{
	cout << "Just hello from third class." << endl;
}
