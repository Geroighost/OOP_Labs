#include <iostream>

using namespace std;

double find_x(double, double, int);
double find_h(double, double, int);
double find_s(double, double, int, int);
double find_I1(double, double, int, int);
double find_I2(double, double, int, int);
double f(double, int);
double integral1(double);
double integral2(double);
double integral3(double);


int main()
{
    setlocale(LC_ALL, "Russian");
    double e = pow(10, -4), answer = 0;
    double (*operation) (double a);
    operation = integral1;
    answer = answer + integral1(e);
    operation = integral2;
    answer = answer + integral2(e);
    operation = integral3;
    answer = answer + integral3(e);
    cout << "Ответ на задачу: " << answer << endl;
    system("pause");
    return 0;
}

double find_x(double a, double b, int c) // a - a, b - h, c - i
{
    return a + (b * c) + (b / 2);
}

double find_h(double a, double b, int c) // a - a, b - b, c - n
{
    return (b - a) / c;
}

double find_s(double a, double h, int c, int number_of_integral) // a - h, c - i
{
    double s;
    double (*operation) (double, double, int);
    operation = find_x;
    double (*operation2) (double, int);
    operation2 = f;
    s = h * f(find_x(a, h, c), number_of_integral);
    return s;
}

double find_I1(double a, double b, int n, int number_of_integral) // a = a, b = b, n = n
{
    double s = 0, h;
    for (int i = 0; i < n; i++)
    {
        double (*operation) (double, double, int);
        double (*operation2) (double, double, int, int);
        operation = find_h;
        h = find_h(a, b, n);
        operation2 = find_s;
        s = s + find_s(a, h, i, number_of_integral);
    }
    return s;
}

double find_I2(double a, double b, int n, int number_of_integral)  // a = s, b = n/i
{
    double s = 0, h;
    for (int i = 0; i < n; i++)
    {
        double (*operation) (double, double, int);
        double (*operation2) (double, double, int, int);
        operation = find_h;
        h = find_h(a, b, n);
        operation2 = find_s;
        s = s + find_s(a, h, i, number_of_integral);
    }
    return s;
}

double f(double a, int b) // a - x, b - number
{
    double c = 0;
    if (b == 1)
    {
        c = sqrt(exp(a) - 1);
    }
    else if (b == 2)
    {
        c = exp(a) * sin(a);
    }
    else if (b == 3)
    {
        c = (pow(a, 2) - 1) * pow(10, 2 * a);
    }
    return c;
}

double integral1(double e)
{
    double I1 = 0, I2 = 0, answer, o_bool = 0, a = 0.2, b = 2.1;
    int n = 4, number_of_integral = 1;
    double (*operation) (double, double, int, int);
    do
    {
        if (o_bool == 0) o_bool++;
        else if (fabs(I2 - I1) > e)
        {
            I1 = I2;
            n = n * 2;
        }
        operation = find_I1;
        I1 = find_I1(a, b, n, number_of_integral);
        n = n * 2;
        operation = find_I2;
        I2 = find_I2(a, b, n, number_of_integral);
    } while (fabs(I2 - I1) > e);
    answer = I2;
    return answer;
}

double integral2(double e)
{
    double I1 = 0, I2 = 0, answer, o_bool = 0, a = 0, b = (3.14 / 2);
    int n = 4, number_of_integral = 2;
    double (*operation) (double, double, int, int);
    do
    {
        if (o_bool == 0) o_bool++;
        else if (fabs(I2 - I1) > e)
        {
            I1 = I2;
            n = n * 2;
        }
        operation = find_I1;
        I1 = find_I1(a, b, n, number_of_integral);
        n = n * 2;
        operation = find_I2;
        I2 = find_I2(a, b, n, number_of_integral);
    } while (fabs(I2 - I1) > e);
    answer = I2;
    return answer;
}

double integral3(double e)
{
    double I1 = 0, I2 = 0, answer, o_bool = 0, a = 0, b = 0.5;
    int n = 4, number_of_integral = 3;
    double (*operation) (double, double, int, int);
    do
    {
        if (o_bool == 0) o_bool++;
        else if (fabs(I2 - I1) > e)
        {
            I1 = I2;
            n = n * 2;
        }
        operation = find_I1;
        I1 = find_I1(a, b, n, number_of_integral);
        n = n * 2;
        operation = find_I2;
        I2 = find_I2(a, b, n, number_of_integral);
    } while (fabs(I2 - I1) > e);
    answer = I2;
    return answer;
}