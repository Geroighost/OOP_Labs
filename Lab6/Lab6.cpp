#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include "tinyexpr.h"

using namespace std;

void dihotomy(string functions, float e, float& an, float& bn);
float function_appr(string functions, float x);
int Fibonacchi_with_number(int n);
string ReplaceString(std::string subject, const std::string& search, const std::string& replace);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUSSIAN");
    //float A = 0, B = 0, C = 0;
    float e = 0.01;
    string functions;
    int a0 = 0, b0 = 0;
    //cout << "Введите значение А функции у (учитывая знак):\n> ";
    //cin >> A;
    //cout << "Введите значение B функции у (учитывая знак):\n> ";
    //cin >> B;
    //cout << "Введите значение C функции у (учитывая знак):\n> ";
    //cin >> C;
    cout << "Введите функцию для решения (в языке С++ и без пробелов):\n> ";
    cin >> functions;
    cout << "Введите начальное граничное значение:\n> ";
    cin >> a0;
    cout << "Введите конечное граничное значение:\n> ";
    cin >> b0;
    //Дихотомия
    float an = a0, bn = b0;
    float dihotomy_answer = 0;
    while ((bn - an) > (2 * e)) dihotomy(functions, e, an, bn);
    float x_dihotomy = (an + bn) / 2;
    dihotomy_answer = function_appr(functions, x_dihotomy);
    cout << "Ответ методом дихотомии:\n x: " << x_dihotomy << " y: " << dihotomy_answer << endl;
    int N = 30;
    //Фибоначчи
    float x1_fib = 0, x2_fib = 0, a_fib = a0, b_fib = b0;
    int Fbn_2 = Fibonacchi_with_number(N - 2);
    int Fbn_N = Fibonacchi_with_number(N);
    int Fbn_1 = Fibonacchi_with_number(N - 1);
    x1_fib = a_fib + (b_fib - a_fib) * ((float)Fbn_2 / Fbn_N);
    x2_fib = a_fib + (b_fib - a_fib) * ((float)Fbn_1 / Fbn_N);
    float y1_fib = 0, y2_fib = 0;
    y1_fib = function_appr(functions, x1_fib);
    y2_fib = function_appr(functions, x2_fib);
    int num_for_fib = N - 3;
    for (int i = 0; i < num_for_fib; i++)
    {
        if (y1_fib <= y2_fib)
        {
            b_fib = x2_fib;
            x2_fib = x1_fib;
            y2_fib = y1_fib;
            x1_fib = a_fib + b_fib - x2_fib;
            y1_fib = function_appr(functions, x1_fib);
        }
        else {
            a_fib = x1_fib;
            x1_fib = x2_fib;
            y1_fib = y2_fib;
            x2_fib = a_fib + b_fib - x1_fib;
            y2_fib = function_appr(functions, x2_fib);
        }
    }
    if (y1_fib < y2_fib) b_fib = x2_fib;
    else a_fib = x1_fib;
    x2_fib = x1_fib;
    y2_fib = y1_fib;
    x1_fib = x2_fib - e;
    y1_fib = function_appr(functions, x1_fib);
    if (y1_fib < y2_fib) b_fib = x2_fib;
    else a_fib = x1_fib;
    float x_min_fib, y_min_fib;
    x_min_fib = (a_fib + b_fib) / 2;
    y_min_fib = function_appr(functions, x_min_fib);
    cout << "Ответ методом Фибоначчи: \nx: " << x_min_fib << " y: " << y_min_fib << endl;
    cout << "The End.";
    return 0;
}

void dihotomy(string functions, float e, float& an, float& bn)
{
    float x0 = (an + bn) / 2;
    float x1, x2;
    x1 = x0 - (e / 2);
    x2 = x0 + (e / 2);
    float y1, y2;
    y1 = function_appr(functions, x1);
    y2 = function_appr(functions, x2);
    if (y1 > y2)
    {
        an = x2;
        bn = bn;
    }
    else if (y1 < y2) {
        an = an;
        bn = x1;
    }
}

float function_appr(string functions, float x)
{
    string x_str(to_string(x));
    string toReplace = "x";
    string resultString = ReplaceString(functions, toReplace, x_str);
    const char* c = resultString.c_str();
    //wstring widefunction;
    //for (int i = 0; i < resultString.length(); ++i) widefunction += wchar_t(resultString[i]);
    //const wchar_t* your_result = widefunction.c_str();
    float f_result = (float)te_interp(c, 0);
    return f_result;
}

int Fibonacchi_with_number(int n)
{
    int Fibon = 1, FibonPast1 = 0, FibonPast2 = 1;
    for (int i = 1; i <= n; i++)
    {
        Fibon = FibonPast1 + FibonPast2;
        FibonPast1 = FibonPast2;
        FibonPast2 = Fibon;
    }
    return Fibon;
}

string ReplaceString(std::string subject, const std::string& search,
    const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}