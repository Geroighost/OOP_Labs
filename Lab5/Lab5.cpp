#include <iostream>

using namespace std;

void menu(int, float, float);
void splitting(int, float, float, float &);
void chorda(int, float, float, float&);
void Newton(int, float, float&);

double f(double x)
{
    return ((2 * pow(sin(2 * x), 2)) / 3) - ((3 * pow(cos(2 * x), 2)) / 4);
}
double df(double x)
{
    return 17 * (sin(2 * x) * (cos(2 * x)/3));
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int a = 0;
    float b, eps = pow(10, -5);
    cout << "Введите b для отрезка:\n";
    cin >> b;
    menu(a, b, eps);
    system("pause");
    return 0;
}

void menu(int a, float b, float e)
{
    int number_menu;
    bool my_bool = true;
    do
    {
        float my_c;
        printf_s("1. Метод деления на отрезки.\n2. Метод хорд.\n3. Метод Ньютона.\n4. Закончить работу.\n");
        cout << "> ";
        cin >> number_menu;
        switch (number_menu)
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
            my_bool = false;
        } break;
        default: cout << "\nВведёное вами число не из меню.";
        }
    } while (my_bool == true);
}

void splitting(int a, float b, float e, float& c)
{
    float FA, FB, FC, A = a, B = b;
    FA = f(a);
    FB = f(b);
    do
    {
        c = (A + B) / 2;
        FC = f(c);
        if (FC != 0)
        {
            if ((FC > 0 && FA > 0) || (FC < 0 && FA < 0)) A = c;
            if ((FC > 0 && FB > 0) || (FC < 0 && FB < 0)) B = c;
        }
    } while (fabs(B - A) > e);
}

void chorda(int a, float b, float e, float &c)
{
    while (fabs(f(b)) > e)
    {
        a = b - ((b - a) * f(b)) / (f(b) - f(a));
        b = a - ((a - b) * f(a)) / (f(a) - f(b));
    }
    c = b;
}

void Newton(int a, float e, float &c)
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
