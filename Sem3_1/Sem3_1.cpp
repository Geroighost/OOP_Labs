#include <iostream>
#include "Solution.h"
#include <fstream>
#include <memory>

using namespace std;

void menu(int, Solution*);

int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 0;
    float num1, num2, num3;
    cout << "Введите какое количество уравнений вы хотите ввести:\n> ";
    cin >> n;
    Solution* Equations = new Solution[n];
    //Third_Class Hide;
    //Third_Class* Hides = new Third_Class[n];
    //unique_ptr<Fifth_Class> Equations_unique(new Fifth_Class);
    //(*Equations_unique).Just_a_method();
    //auto ptr1 = make_shared<Third_Class>();
    //auto ptr2 = ptr1;
    //cout << "Shared_ptr = " << ptr2.use_count() << endl;
    //auto nomber1 = make_shared<Fourty_Class>(56);
    //auto nomber2 = make_shared<Fourty_Class>(65);
    //Up(nomber1, nomber2);
    for (int y = 0; y < n; y++)
    {
        cout << "Введите A, B и C в вашем " << y+1 << "-м уравнении (целое или вещественное):";
        for (int i = 3; i > 0; i--)
        {
            cout << "\n> ";
            if (i == 3) { cin >> num1; }
            else if (i == 2) { cin >> num2; }
            else if (i == 1) { cin >> num3; }
        }
        if (num1 != NULL)
        {
            Equations[y].set_A(num1);
        }
        if (num2 != NULL)
        {
            Equations[y].set_B(num2);
        }
        if (num3 != NULL)
        {
            Equations[y].set_C(num3);
        }
        Equations[y].Just_another_method_with_override();
    }
    menu(n, Equations);
    return 0;
}

void menu(int n, Solution* Eq)
{
    int o = 0, number_in_menu;
    do
    {
        cout << "Какую операцию вы хотите провести?" << endl;
        if (n == 1)
        {
            cout << "1. Вывести условие.\n2. Вывести x1 и x2 для квадратных уравнений.\n3. Выход.\n> ";
            cin >> number_in_menu;
            switch (number_in_menu)
            {
            case 1:
            {
                for (int y = 0; y < n; y++) cout << Eq[y] << endl;
            } break;
            case 2:
            {
                for (int y = 0; y < n; y++)
                {
                    float x1 = 0, x2 = 0;
                    float* x = new float[3];
                    Eq[y].method_coef_prop(x1, x2);
                    cout << y + 1 << ") x1 = " << x1 << ", x2 = " << x2 << "(квадратное уравнение)" << endl;
                }
            } break;
            case 3:
            {
                o = 1;
            } break;
            default: cout << "Не то число." << endl;
            };
        };
        if (n > 1)
        {
            cout << "1. Вывести все условия.\n2. Вывести x1 и x2 во всех кв. уравнениях.\n3. Выход.\n> ";
            cin >> number_in_menu;
            switch (number_in_menu)
            {
            case 1:
            {
                for (int y = 0; y < n; y++) cout << y+1 << ") " << Eq[y] << endl;
            } break;
            case 2:
            {
                for (int y = 0; y < n; y++)
                {
                    float x1 = 0, x2 = 0;
                    float* x = new float[3];
                    Eq[y].method_coef_prop(x1, x2);
                    cout << y + 1 << ") x1 = " << x1 << ", x2 = " << x2 << " (квадратное уравнение)" << endl;
                }
            } break;
            case 3:
            {
                o = 1;
            } break;
            default: cout << "Не то число." << endl;
            };
        };
    } while (o == 0);
    cout << "Сеанс завершен." << endl;
}