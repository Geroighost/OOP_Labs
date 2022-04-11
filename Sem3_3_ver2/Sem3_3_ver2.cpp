#include <iostream>
#include "Vector.h"

using namespace std;

template <typename T_sum>
T_sum sum(T_sum& fun1, T_sum& fun2)
{
    T_sum result;
    result = fun1 + fun2;
    return result;
}

template <typename T_multi>
T_multi multi(T_multi& fun1, int n)
{
    T_multi result;
    result = fun1 * n;
    return result;
}

int main()
{
    setlocale(LC_ALL, "ru");
    Vector Vector_1(1, 3, 5, 7);
    cout << "Первый вектор (константа): (" << Vector_1 << ")" << endl;
    Vector Vector_2;
    cout << "Второй вектор вводится с клавиатуры. Введите первое число вектора:\n> ";
    int num;
    cin >> num;
    Vector_2.Set_num1(num);
    cout << "Введите второе число вектора:\n> ";
    cin >> num;
    Vector_2.Set_num2(num);
    cout << "Введите третье число вектора:\n> ";
    cin >> num;
    Vector_2.Set_num3(num);
    cout << "Введите четвёртое число вектора:\n> ";
    cin >> num;
    Vector_2.Set_num4(num);
    cout << "\nПервый вектор: (" << Vector_1 << ")" << endl;
    cout << "Второй вектор: (" << Vector_2 << ")" << endl;
    cout << "Сумма векторов: (" << sum(Vector_1, Vector_2) << ")" << endl;
    int number, number1;
    cout << "Введите число, на которое нужно умножить вектор:\n> ";
    cin >> number;
    cout << "Выберите какой вектор, 1 или 2?\n> ";
    cin >> number1;
    if (number1 == 1) cout << "Произведение: (" << multi(Vector_1, number) << ")" << endl;
    if (number1 == 2) cout << "Произведение: (" << multi(Vector_2, number) << ")" << endl;
    Vector Vector_3 = Vector_1;
    cout << multi(Vector_3, 3) << endl;
    system("pause");
    return 0;
}