#include <iostream>

using namespace std;

void menu(int, float, float);
void splitting(int, float, float, float&);
void chorda(int, float, float, float&);
void Newton(int, float, float&);
double f(double x)
{
    return exp(x) - 2 * x - 10;
}
double df(double x)
{
    return exp(x) - 2;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int a = 0;
    float b, eps = pow(10, -4);
    cout << "Введите b для отрезка:\n> ";
    cin >> b;
    menu(a, b, eps);
    cout << "Сеанс закончен.\n";
    system("pause");
    return 0;
}

void menu(int a, float b, float e)
{
    int number_in_menu, o_bool = 0;
    do
    {
        float my_c;
        printf_s("1. Метод деления на отрезки.\n2. Метод хорд.\n3. Метод Ньютона.\n4. Закончить работу.\n");
        cout << "> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            splitting(a, b, e, my_c);
            cout << "Ответ путём деления на отрезки: " << my_c << endl;
            my_c = 0;
        }
        break;
        case 2:
        {
            chorda(a, b, e, my_c);
            cout << "Ответ путём хорд: " << my_c << endl;
            my_c = 0;
        } break;
        case 3:
        {
            Newton(a, e, my_c);
            cout << "Ответ путём метода Ньютона: " << my_c << endl;
            my_c = 0;
        } break;
        case 4:
        {
            o_bool++;
        } break;
        default: cout << "\nВведёное вами число не из меню.";
        }
    } while (o_bool == 0);
}

void splitting(int a, float b, float e, float& c)
{
    float FfromA, FfromB, FfromC, A = a, B = b;
    FfromA = f(a);
    FfromB = f(b);
    do
    {
        c = (A + B) / 2;
        FfromC = f(c);
        if (FfromC != 0)
        {
            if ((FfromC > 0 && FfromA > 0) || (FfromC < 0 && FfromA < 0)) A = c;
            if ((FfromC > 0 && FfromB > 0) || (FfromC < 0 && FfromB < 0)) B = c;
        }
    } while (fabs(B - A) > e);
}

void chorda(int a, float b, float e, float& c)
{
    while (fabs(f(b)) > e)
    {
        a = b - ((b - a) * f(b)) / (f(b) - f(a));
        b = a - ((a - b) * f(a)) / (f(a) - f(b));
    }
    c = b;
}

void Newton(int a, float e, float& c)
{
    double tmp;
    int N = 0;
    tmp = a + 2 * e;
    while (fabs(a - tmp) > e)
    {
        tmp = a;
        a = a - f(a) / df(a);
    }
    c = a;
}
