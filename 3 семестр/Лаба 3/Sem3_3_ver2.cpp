#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Vector Vector_1(1, 3, 5, 7);
    Vector Vector_2(5, 8, 16, 56);
    Vector Vector_Sum = Vector_1 + Vector_2;
    cout << "Сумма векторов: (" << Vector_Sum.Get_num1() << ", " << Vector_Sum.Get_num2() << ", " << Vector_Sum.Get_num3() << ", " << Vector_Sum.Get_num4() << ")" << endl;
    int number, number1;
    cout << "Введите число, на которое нужно умножить вектор:\n> ";
    cin >> number;
    cout << "Выберите какой вектор, 1 или 2?\n> ";
    cin >> number1;
    Vector Vector_Tim;
    if (number1 == 1)
    {
        Vector_Tim = Vector_1 * number;
    }
    if (number1 == 2)
    {
        Vector_Tim = Vector_2 * number;
    }
    cout << "Произведение: (" << Vector_Tim.Get_num1() << ", " << Vector_Tim.Get_num2() << ", " << Vector_Tim.Get_num3() << ", " << Vector_Tim.Get_num4() << ")" << endl;
    system("pause");
    return 0;
}