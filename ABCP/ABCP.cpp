#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double a, b, Sum;

    cout << "Введите число a: ";
    cin >> a; "\n";
    cout << "Введите число b: ";
    cin >> b; "\n";
    Sum = a + b;
    cout << "Сумма a и b: ";
    cout << Sum;
    cout << "\n";
    Sum = a - b;
    cout << "Разность a и b: ";
    cout << Sum;
    cout << "\n";
    Sum = a * b;
    cout << "Произведение a и b: ";
    cout << Sum;
    cout << "\n";
    Sum = a / b;
    cout << "Частное a и b: ";
    cout << Sum;
    cout << "\n";

    system("pause");
    return 0;

}

