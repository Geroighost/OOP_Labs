#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include "Pharmacy.h"

using namespace std;

void menu(Pharmacy*&, int&);
void add(Pharmacy*&, int&);
void record_in_file(Pharmacy*&, int);
void edit(Pharmacy*&, int);
void deleting(Pharmacy*&, int&);
void search(Pharmacy*, int);
void read_number_from_file(int&);
void read_elements_from_file(Pharmacy*&, int);
void output_data_on_monitor(Pharmacy*, int);
void calculation_discount(Pharmacy*, int);

void menu(Pharmacy*& Medicines, int& number)
{
    int number_in_menu, o_bool = 0;
    do
    {
        cout << endl;
        printf_s("1. Вывести все данные на экран.\n2. Добавить препарат.\n3. Удалить препарат.\n4. Внести изменения.\n5. Перезаписать в файл.\n6. Поиск.\n7. Вычисление цены со скидкой для определённого препарата.\n8. Закончить работу.\n");
        cout << "> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            output_data_on_monitor(Medicines, number);
        }
        break;
        case 2:
        {
            add(Medicines, number);
        } break;
        case 3:
        {
            deleting(Medicines, number);
        } break;
        case 4:
        {
            edit(Medicines, number);
        } break;
        case 5:
        {
            record_in_file(Medicines, number);
        } break;
        case 6:
        {
            search(Medicines, number);
        } break;
        case 7:
        {
            calculation_discount(Medicines, number);
        } break;
        case 8:
        {
            o_bool++;
        } break;
        default: cout << "\nВведёное вами число не из меню.";
        }
    } while (o_bool == 0);
}

void add(Pharmacy*& Medicines, int& number)
{
    int number_in_menu, o_bool = 0;
    cout << "Выберите пункт меню:" << endl;
    do
    {
        cout << "1. Добавление препарата в программу\n2. Выход\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            string a;
            float b;
            if (number != 0)
            {
                Pharmacy* New_Medicines = new Pharmacy[number + 1];
                for (int i = 0; i < number; i++)
                {
                    a = Medicines[i].Get_Name();
                    New_Medicines[i].Set_Name(a);
                    a = Medicines[i].Get_Manufacturer();
                    New_Medicines[i].Set_Manufacturer(a);
                    b = Medicines[i].Get_Price();
                    New_Medicines[i].Set_Price(b);
                    b = Medicines[i].Get_Discount();
                    New_Medicines[i].Set_Discount(b);
                }
                Medicines = New_Medicines;
            }
            number = number + 1;
            if (number == 1)
            {
                Pharmacy* New_Medicines = new Pharmacy[number + 1];
                Medicines = New_Medicines;
            }
            cout << "Введите название препарата:\n> ";
            cin.ignore(255, '\n');
            getline(cin, a);
            for (int i = number-1; i < number; i++)
                Medicines[i].Set_Name(a);
            cout << "Введите производителя:\n> ";
            getline(cin, a);
            for (int i = number-1; i < number; i++) 
                Medicines[i].Set_Manufacturer(a);
            cout << "Введите цену препарата:\n> ";
            cin >> b;
            for (int i = number-1; i < number; i++) 
                Medicines[i].Set_Price(b);
            cout << "Введите скидку (если её нет, вписывается 0:\n> ";
            cin >> b;
            for (int i = number-1; i < number; i++) 
                Medicines[i].Set_Discount(b);
            cout << "Добавление прошло успешно." << endl;
        }
        break;
        case 2:
        {
            o_bool++;
        }
        break;
        default: cout << "Число не из меню." << endl;
        }
    } while (o_bool == 0);
}

void record_in_file(Pharmacy*& Medicines, int number)
{
    ofstream file;
    file.open("log.txt");
    for (int i = 0; i < number; i++)
    {
        file << Medicines[i].Get_Name() << " ";
        file << Medicines[i].Get_Manufacturer() << " ";
        file << Medicines[i].Get_Price() << " ";
        file << Medicines[i].Get_Discount() << " ";
        if (i + 1 != number) file << "\n";
    }
    cout << "Перезаписано!" << endl;
}

void edit(Pharmacy*& Medicines, int number)
{
    int number_in_menu, o_bool = 0;
    cout << "Выберите пункт меню:" << endl;
    do
    {
        cout << "1. Внести изменения\n2. Выход\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            string a;
            float b;
            int memory = 0, number_in_menu2;
            cout << "Выберите препарат для редактирования: " << endl;
            for (int i = 0; i < number; i++) cout << i + 1 << ". " << Medicines[i].Get_Name() << endl;
            cin.ignore(255, '\n');
            getline(cin, a);
            for (int i = 0; i < number; i++)
                if (a == Medicines[i].Get_Name())
                {
                    int oo_bool = 0;
                    do
                    {
                        memory++;
                        cout << "Что вы хотите изменить?\n1. Название\n2. Производителя\n3. Цену\n4. Скидку\n5. Выход в меню\n> ";
                        cin >> number_in_menu2;
                        switch (number_in_menu2)
                        {
                        case 1:
                        {
                            cout << "Прошлое значение: " << Medicines[i].Get_Name() << endl;
                            cout << "Введите изменение:\n> ";
                            cin.ignore(255, '\n');
                            getline(cin, a);
                            Medicines[i].Set_Name(a);
                            oo_bool++;
                        }
                        break;
                        case 2:
                        {
                            cout << "Прошлое значение: " << Medicines[i].Get_Manufacturer() << endl;
                            cout << "Введите изменение:\n> ";
                            cin.ignore(255, '\n');
                            getline(cin, a);
                            Medicines[i].Set_Manufacturer(a);
                            oo_bool++;
                        }
                        break;
                        case 3:
                        {
                            cout << "Прошлое значение: " << Medicines[i].Get_Price() << endl;
                            cout << "Введите изменение:\n> ";
                            cin >> b;
                            Medicines[i].Set_Price(b);
                            oo_bool++;
                        }
                        break;
                        case 4:
                        {
                            cout << "Прошлое значение: " << Medicines[i].Get_Discount() << endl;
                            cout << "Введите изменение:\n> ";
                            cin >> b;
                            Medicines[i].Set_Discount(b);
                            oo_bool++;
                        }
                        break;
                        case 5:
                        {
                            oo_bool++;
                        }
                        break;
                        default: cout << "Число не из меню.";
                        }
                    } while (oo_bool == 0);
                }
            if (memory == 0) cout << "Такой препарат не найден." << endl;
        }
        break;
        case 2:
        {
            o_bool++;
        }
        break;
        default: cout << "Число не из меню." << endl;
        }
    } while (o_bool == 0);
}

void deleting(Pharmacy*& Medicines, int& number)
{
    int number_in_menu, o_bool = 0;
    cout << "Выберите пункт меню:" << endl;
    do
    {
        cout << "1. Удалить препарат из программы\n2. Выход\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            cout << "Выберите, какой препарат вы хотите убрать из списка:" << endl;
            for (int i = 0; i < number; i++)
            {
                cout << i + 1 << ". " << Medicines[i].Get_Name() << endl;
            }
            string name, original_name;
            int i_memorized = 0, oo_bool = 0;
            cout << "> ";
            cin.ignore(255, '\n');
            getline(cin, name);
            for (int i = 0; i < number; i++)
            {
                original_name = Medicines[i].Get_Name();
                if (name == original_name)
                {
                    i_memorized = i;
                    oo_bool++;
                }
            }
            if (i_memorized == 0 && oo_bool != 0)
            {
                for (int i = i_memorized; i < number - 1; i++)
                {
                    string a;
                    float b;
                    a = Medicines[i + 1].Get_Name();
                    Medicines[i].Set_Name(a);
                    a = Medicines[i + 1].Get_Manufacturer();
                    Medicines[i].Set_Manufacturer(a);
                    b = Medicines[i + 1].Get_Price();
                    Medicines[i].Set_Price(b);
                    b = Medicines[i + 1].Get_Discount();
                    Medicines[i].Set_Discount(b);
                }
                number = number - 1;
                Pharmacy* New_Medicines = new Pharmacy[number];
                string a;
                float b;
                for (int i = 0; i < number; i++)
                {
                    a = Medicines[i].Get_Name();
                    New_Medicines[i].Set_Name(a);
                    a = Medicines[i].Get_Manufacturer();
                    New_Medicines[i].Set_Manufacturer(a);
                    b = Medicines[i].Get_Price();
                    New_Medicines[i].Set_Price(b);
                    b = Medicines[i].Get_Discount();
                    New_Medicines[i].Set_Discount(b);
                }
                Medicines = New_Medicines;
                cout << "Успешно удалено." << endl;
            }
            else if (i_memorized == 0 && oo_bool == 0) cout << "Название введено неверно." << endl;
        }
        break;
        case 2:
        {
            o_bool++;
        }
        break;
        default: cout << "Число не из меню" << endl;
        }
    } while (o_bool == 0);
}

void search(Pharmacy* Medicines, int number)
{
    int number_in_menu, o_bool = 0;
    cout << "Выберите пункт меню:" << endl;
    do
    {
        cout << "1. Выполнить поиск\n2. Выход в главное меню\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            int oo_bool = 0;
            cout << "Введите по какому элементу вы хотите провести поиск:" << endl;
            do
            {
                cout << "1. Название препарата\n2. Производитель\n3. Цена\n4. Скидка\n5. Выход в предыдущее меню" << endl;
                cout << "> ";
                cin >> number_in_menu;
                switch (number_in_menu)
                {
                case 1:
                {
                    string a;
                    int memory = 0;
                    cout << "Введите препарат:\n> ";
                    cin.ignore(255, '\n');
                    getline(cin, a);
                    for (int i = 0; i < number; i++)
                    {
                        if (a == Medicines[i].Get_Name())
                        {
                            cout << "Препарат: " << Medicines[i].Get_Name() << "\nПроизводитель: " << Medicines[i].Get_Manufacturer() << "\nЦена: " << Medicines[i].Get_Price() << "руб.\nСкидка (если имеется): " << Medicines[i].Get_Discount() << "%" << endl;
                            Medicines[i].Price_with_discount();
                            memory++;
                        }
                    }
                    if (memory == 0)
                    {
                        cout << "Препарат с таким названием не найден.";
                    }
                }
                break;
                case 2:
                {
                    string a;
                    int memory = 0;
                    cout << "Введите производителя:\n> ";
                    cin.ignore(255, '\n');
                    getline(cin, a);
                    for (int i = 0; i < number; i++)
                    {
                        if (a == Medicines[i].Get_Manufacturer())
                        {
                            if (memory == 0) cout << "Препараты от данного производителя: " << endl;
                            cout << "Препарат: " << Medicines[i].Get_Name() << "\nЦена: " << Medicines[i].Get_Price() << "руб.\nСкидка (если имеется): " << Medicines[i].Get_Discount() << "%" << endl;
                            Medicines[i].Price_with_discount();
                            memory++;
                        }
                    }
                    if (memory == 0)
                    {
                        cout << "Препараты от данного производителя не найдены.";
                    }
                }
                break;
                case 3:
                {
                    float a;
                    int memory = 0;
                    cout << "Введите цену:\n> ";
                    cin.ignore(255, '\n');
                    cin >> a;
                    for (int i = 0; i < number; i++)
                    {
                        if (a == Medicines[i].Get_Price())
                        {
                            if (memory == 0) cout << "Препараты с такой ценой: " << endl;
                            cout << "Препарат: " << Medicines[i].Get_Name() << "\nПроизводитель: " << Medicines[i].Get_Manufacturer() << "Скидка (если имеется): " << Medicines[i].Get_Discount() << "%" << endl;
                            Medicines[i].Price_with_discount();
                            memory++;
                        }
                    }
                    if (memory == 0)
                    {
                        cout << "Препараты с такой ценой не найдены.";
                    }
                }
                break;
                case 4:
                {
                    float a;
                    int memory = 0;
                    cout << "Введите скидку:\n> ";
                    cin.ignore(255, '\n');
                    cin >> a;
                    for (int i = 0; i < number; i++)
                    {
                        if (a == Medicines[i].Get_Discount())
                        {
                            if (memory == 0) cout << "Препараты с такой скидкой: " << endl;
                            cout << "Препарат: " << Medicines[i].Get_Name() << "\nПроизводитель: " << Medicines[i].Get_Manufacturer() << "\nЦена: " << Medicines[i].Get_Price() << "руб." << endl;
                            Medicines[i].Price_with_discount();
                            memory++;
                        }
                    }
                    if (memory == 0)
                    {
                        cout << "Препараты с такой скидкой не найдены.";
                    }
                }
                break;
                case 5:
                {
                    oo_bool++;
                }
                break;
                default: cout << "Повторите ввод.";
                }
            } while (oo_bool == 0);
        }
        break;
        case 2:
        {
            o_bool++;
        }
        break;
        default: cout << "Число не из меню." << endl;
        }
    } while (o_bool == 0);
}

void read_number_from_file(int& number_of_elements)
{
    fstream file;
    char mainrow[200];
    file.open("log.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            file.getline(mainrow, 200);
            number_of_elements++;
        }
        file.close();
    }
    else
    {
        cout << "Log-файла данной программы не существует, либо это первый запуск программы." << endl;
    }
}

void read_elements_from_file(Pharmacy*& Medicines, int number)
{
    fstream file;
    file.open("log.txt");
    if (file.is_open())
    {
        string a;
        float b;
        for (int i = 0; i < number; i++)
        {
            file >> a;
            Medicines[i].Set_Name(a);
            file >> a;
            Medicines[i].Set_Manufacturer(a);
            file >> b;
            Medicines[i].Set_Price(b);
            file >> b;
            Medicines[i].Set_Discount(b);
        }
    }
}

void output_data_on_monitor(Pharmacy* Medicines, int number)
{
    cout << endl;
    for (int i = 0; i < number; i++)
    {
        string a1, a2;
        float b1, b2;
        a1 = Medicines[i].Get_Name();
        a2 = Medicines[i].Get_Manufacturer();
        b1 = Medicines[i].Get_Price();
        b2 = Medicines[i].Get_Discount();
        cout.precision(3);
        cout << i + 1 << ". Название: " << a1 << "\n   Производитель: " << a2 << "\n   Цена: " << b1 << " руб.\n   Скидка (если нет, указывается 0): " << b2 << "%" << endl;
    }
}

void calculation_discount(Pharmacy* Medicines, int number)
{
    int o_bool = 0;
    cout << "Выберите пункт меню: " << endl;
    do
    {
        int number_in_menu;
        cout << "1. Вычислить цену со скидкой\n2. Выход в главное меню\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            cout << "Выберите препарат, для которого вы хотите вычислить цену со скидкой: " << endl;
            for (int i = 0; i < number; i++)
            {
                cout << i + 1 << ". " << Medicines[i].Get_Name() << endl;
            }
            string name, original_name;
            int i_memorized, memory = 0;
            cout << "> ";
            cin.ignore(255, '\n');
            getline(cin, name);
            for (int i = 0; i < number; i++)
            {
                original_name = Medicines[i].Get_Name();
                if (name == original_name)
                {
                    i_memorized = i;
                    memory++;
                }
            }
            if (memory != 0)
            {
                cout << "Препарат: " << Medicines[i_memorized].Get_Name() << "\nЦена: " << Medicines[i_memorized].Get_Price() << " руб.\nСкидка: " << Medicines[i_memorized].Get_Discount() << endl;
                Medicines[i_memorized].Price_with_discount();
            }
            else cout << "Такой препарат не найден либо введён некорректно." << endl;
        }
        break;
        case 2:
        {
            o_bool++;
        }
        break;
        default: cout << "Число не из меню." << endl;
        }
    } while (o_bool == 0);
}