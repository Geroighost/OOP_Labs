#pragma once
using namespace std;

struct car_info
{
    int YEAR = 0;
    int MILEAGE = 0;
    int VOLUME = 0;
    int BODYWORK;
    int PRICE = 0;
};

struct car
{
    string MANUFACTURER;
    string CODE;
    car_info CAR_INFO;
};

void number_of_structs(fstream& a, int& b, int& c)
{
    char mainrow[200];
    a.open("Log.txt");
    if (a.is_open())
    {
        while (!a.eof())
        {
            a.getline(mainrow, 200);
            b++;
        }
        a.close();
    }
    else
    {
        cout << "Log-файл не найден в корневой папке. Верните или создайте файл.\n";
        c++;
    }
}

void createstructs(fstream& a, int b, car*& c)
{
    fstream my_file;
    my_file.open("Log.txt");
    if (my_file.is_open())
    {
        for (int i = 0; i < b; i++)
        {
            my_file >> c[i].MANUFACTURER;
            my_file >> c[i].CODE;
            my_file >> c[i].CAR_INFO.YEAR;
            my_file >> c[i].CAR_INFO.MILEAGE;
            my_file >> c[i].CAR_INFO.VOLUME;
            my_file >> c[i].CAR_INFO.BODYWORK;
            my_file >> c[i].CAR_INFO.PRICE;
        }
    }
    my_file.close();
}

void create_new_struct(int b, car*& a)
{
    car* car_s = new car[b];
    for (int i = 0; i < b - 1; i++)
    {
        car_s[i].MANUFACTURER = a[i].MANUFACTURER;
        car_s[i].CODE = a[i].CODE;
        car_s[i].CAR_INFO.YEAR = a[i].CAR_INFO.YEAR;
        car_s[i].CAR_INFO.MILEAGE = a[i].CAR_INFO.MILEAGE;
        car_s[i].CAR_INFO.VOLUME = a[i].CAR_INFO.VOLUME;
        car_s[i].CAR_INFO.BODYWORK = a[i].CAR_INFO.BODYWORK;
        car_s[i].CAR_INFO.PRICE = a[i].CAR_INFO.PRICE;
    }
    delete[] a;
    a = car_s;
}

void display(car* a, int b)
{
    for (int i = 0; i < b; i++)
    {
        cout << "Марка: " << a[i].MANUFACTURER << endl;
        cout << "Производственный код: " << a[i].CODE << endl;
        cout << "Год выпуска: " << a[i].CAR_INFO.YEAR << " г." << endl;
        cout << "Пробег: " << a[i].CAR_INFO.MILEAGE << " км." << endl;
        cout << "Объём двигателя: " << a[i].CAR_INFO.VOLUME << " см. куб." << endl;
        if (a[i].CAR_INFO.BODYWORK == 1) cout << "Тип кузова: Внедорожник" << endl;
        else if (a[i].CAR_INFO.BODYWORK == 2) cout << "Тип кузова: Лифтбек" << endl;
        else if (a[i].CAR_INFO.BODYWORK == 3) cout << "Тип кузова: Седан" << endl;
        else if (a[i].CAR_INFO.BODYWORK == 4) cout << "Тип кузова: Хэтчбек" << endl;
        cout << "Цена: " << a[i].CAR_INFO.PRICE << " руб." << endl;
        cout << endl;
    }
}

void add(car*& a, int& b)
{
    int number;
    b++;
    create_new_struct(b, a);
    for (int i = 0; i < b; i++)
    {
        if (i == b - 1)
        {
            cout << "Введите марку машины:\n";
            cin >> a[i].MANUFACTURER;
            cout << "Введите код марки машины:\n";
            cin >> a[i].CODE;
            cout << "Введите год производства:\n";
            cin >> a[i].CAR_INFO.YEAR;
            cout << "Введите пробег (в км):\n";
            cin >> a[i].CAR_INFO.MILEAGE;
            cout << "Введите объём двигателя (в см. куб):\n";
            cin >> a[i].CAR_INFO.VOLUME;
            cout << "Введите тип кузова (1 - Внедорожник, 2 - Лифтбек, 3 - Седан, 4 - Хэтчбек):\n";
            cin >> number;
            a[i].CAR_INFO.BODYWORK = number;
            cout << "Введите цену (в руб):\n";
            cin >> a[i].CAR_INFO.PRICE;
        }
    }
}

void del(car* a, int& b)
{
    string mark, code;
    int number = 0, number1 = 0;
    cout << "Введите марку машины, который нужно удалить:\n";
    cin >> mark;
    for (int i = 0; i < b; i++) if (mark == a[i].MANUFACTURER) number1++;
    if (number1 == 0) cout << "Машин с такой маркой не обнаружено." << endl;
    if (number1 == 1)
    {
        cout << "Найдена 1 машина с такой маркой. Удаляем..." << endl;
        for (int i = 0; i < b; i++)
        {
            if (number == 1)
            {
                a[i - 1].MANUFACTURER = a[i].MANUFACTURER;
                a[i - 1].CODE = a[i].CODE;
                a[i - 1].CAR_INFO.YEAR = a[i].CAR_INFO.YEAR;
                a[i - 1].CAR_INFO.MILEAGE = a[i].CAR_INFO.MILEAGE;
                a[i - 1].CAR_INFO.VOLUME = a[i].CAR_INFO.VOLUME;
                a[i - 1].CAR_INFO.BODYWORK = a[i].CAR_INFO.BODYWORK;
                a[i - 1].CAR_INFO.PRICE = a[i].CAR_INFO.PRICE;
            }
            if (mark == a[i].MANUFACTURER) number = 1;
        }
    }
    if (number1 > 1)
    {
        cout << "Найдено несколько (" << number1 << ") машин с такой маркой. Выберите, пожалуйста, марку машины из приведённых:\n";
        for (int i = 0; i < b; i++) if (a[i].MANUFACTURER == mark) cout << a[i].CODE << endl;
        cin >> code;
        for (int i = 0; i < b; i++)
        {
            if (number == 1)
            {
                a[i - 1].MANUFACTURER = a[i].MANUFACTURER;
                a[i - 1].CODE = a[i].CODE;
                a[i - 1].CAR_INFO.YEAR = a[i].CAR_INFO.YEAR;
                a[i - 1].CAR_INFO.MILEAGE = a[i].CAR_INFO.MILEAGE;
                a[i - 1].CAR_INFO.VOLUME = a[i].CAR_INFO.VOLUME;
                a[i - 1].CAR_INFO.BODYWORK = a[i].CAR_INFO.BODYWORK;
                a[i - 1].CAR_INFO.PRICE = a[i].CAR_INFO.PRICE;
            }
            if (code == a[i].CODE) number = 1;
        }
        if (number == 0) cout << "Машин с такой маркой и кодом не обнаружено." << endl;
    }
    if (number == 1) b--;
}

void search(car* a, int b)
{
    int number, o_bool = 0;
    cout << "Что вы хотите найти?\n1. Самая новая машина.\n2. Самая старая машина.\n3. Выйти.\n";
    do
    {
        cin >> number;
        switch (number)
        {
        case 1:
        {
            int year = 0, year_max = 0;
            for (int i = 0; i < b; i++)
            {
                year = a[i].CAR_INFO.YEAR;
                if (year > year_max) year_max = year;
            }
            cout << "Самая(-ые) новая(-ые) машина(-ы):" << endl;
            for (int i = 0; i < b; i++)
            {
                if (a[i].CAR_INFO.YEAR == year_max) cout << "- " << a[i].MANUFACTURER << " " << a[i].CODE << endl;
            }
        }
        break;
        case 2:
        {
            int year = 0, year_min = 3000;
            for (int i = 0; i < b; i++)
            {
                year = a[i].CAR_INFO.YEAR;
                if (year < year_min) year_min = year;
            }
            cout << "Самая(-ые) старая(-ые) машина(-ы):" << endl;
            for (int i = 0; i < b; i++)
            {
                if (a[i].CAR_INFO.YEAR == year_min) cout << "- " << a[i].MANUFACTURER << " " << a[i].CODE << endl;
            }
        } break;
        case 3:
        {
            o_bool = 1;
        } break;
        default: cout << "Введёное вами число не из данного меню.\n";
        }
    } while (o_bool == 0);
}

void calculation(car* a, int b)
{
    int number, o_bool = 0;
    cout << "Что вы хотите вычислить?\n1. Самая дорогая машина.\n2. Машина с самым большим пробегом.\n3. Количество машин определённого типа.\n4. Выйти.\n";
    do
    {
        cin >> number;
        switch (number)
        {
        case 1:
        {
            int price_max = 0, price = 0;
            for (int i = 0; i < b; i++)
            {
                price = a[i].CAR_INFO.PRICE;
                if (price > price_max) price_max = price;
            }
            cout << "Самая(-ые) дорогая(-ые) машина(-ы):" << endl;
            for (int i = 0; i < b; i++)
            {
                if (a[i].CAR_INFO.PRICE == price_max) cout << "- " << a[i].MANUFACTURER << " " << a[i].CODE << endl;
            }
        }
        break;
        case 2:
        {
            int mileage_max = 0, mileage = 0;
            for (int i = 0; i < b; i++)
            {
                mileage = a[i].CAR_INFO.MILEAGE;
                if (mileage > mileage_max) mileage_max = mileage;
            }
            cout << "Машина(-ы) с самым большим пробегом:" << endl;
            for (int i = 0; i < b; i++)
            {
                if (a[i].CAR_INFO.MILEAGE == mileage_max) cout << "- " << a[i].MANUFACTURER << " " << a[i].CODE << endl;
            }
        }
        break;
        case 3:
        {
            int one = 0, two = 0, three = 0, four = 0, number = 0;
            for (int i = 0; i < b; i++)
            {
                number = a[i].CAR_INFO.BODYWORK;
                if (number == 1) one++;
                else if (number == 2) two++;
                else if (number == 3) three++;
                else if (number == 4) four++;
            }
            cout << "Количество машин по типам:\nВнедорожников: " << one << "\nЛифтбеков: " << two << "\nСеданов: " << three << "\nХэтчбеков: " << four << endl;
        } break;
        case 4:
        {
            o_bool = 1;
        } break;
        default: cout << "Введёное вами число не из данного меню.\n";
        }
    } while (o_bool == 0);
    cout << "Возвращение к меню." << endl;
}

void edit(car*& a, int b)
{
    int o_bool = 0, number_menu, edit_int, bool_number = 0, bool_number_2 = 0, oo_bool = 0, ooo_bool = 0, oooo_bool = 0;
    string mark, code, edit_string;
    do
    {
        cout << "Выберите марку машины:\n";
        for (int i = 0; i < b; i++)
        {
            if (ooo_bool >= 1)
                for (int n = 0; n < i; n++)
                    if (a[i].MANUFACTURER == a[n].MANUFACTURER)
                    {
                        oooo_bool++;
                    }
            if (oooo_bool == 0) cout << a[i].MANUFACTURER << "\n";
            ooo_bool++;
            oooo_bool = 0;
        }
        cout << endl;
        cin >> mark;
        if (bool_number < 2)
        {
            for (int i = 0; i < b; i++) if (mark == a[i].MANUFACTURER) o_bool++;
            if (o_bool == 0)
            {
                cout << "Повторите ввод.\n";
                bool_number++;
            }
        }
        else
        {
            cout << "Вы ввели марку неправильно 3 раза подряд. Желаете выйти в меню для выбора другой операции?\n1. Да, выйти в меню.\n2. Нет, попробовать ещё.\n> ";
            cin >> bool_number_2;
            switch (bool_number_2)
            {
            case 1:
            {
                o_bool++;
                oo_bool++;
            } break;
            case 2:
            {
                bool_number = 0;
            } break;
            default: cout << "\nВведёное вами число не из меню.";
            }
        }
    } while (o_bool == 0);
    o_bool = 0;
    bool_number = 0;
    bool_number_2 = 0;
    if (oo_bool == 0)
    {
        do
        {
            cout << "Выберите код машины:\n";
            for (int i = 0; i < b; i++) if (mark == a[i].MANUFACTURER) cout << a[i].CODE << "\n";
            cout << endl;
            cin >> code;
            if (bool_number < 2)
            {
                for (int i = 0; i < b; i++) if (code == a[i].CODE) o_bool++;
                if (o_bool == 0)
                {
                    cout << "Повторите ввод.\n";
                    bool_number++;
                }
            }
            else
            {
                cout << "Вы ввели код неправильно 3 раза подряд. Желаете выйти в меню для выбора другой операции?\n1. Да, выйти в меню.\n2. Нет, попробовать ещё.\n> ";
                cin >> bool_number_2;
                switch (bool_number_2)
                {
                case 1:
                {
                    o_bool++;
                    oo_bool++;
                }
                case 2:
                {
                    bool_number = 0;
                }
                default: cout << "\nВведёное вами число не из меню.";
                }
            }
        } while (o_bool == 0);
        if (oo_bool == 0)
            do
            {
                cout << "Выберите, что вы хотите изменить:\n1. Марка\n2. Код\n3. Год производства\n4. Пробег\n5. Объём двигателя\n6. Тип кузова\n7. Цена\n8. Выйти в меню\n";
                cin >> number_menu;
                switch (number_menu)
                {
                case 1:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "Введите изменение (прошлое значение - " << a[i].MANUFACTURER << "):\n";
                                cin >> edit_string;
                                a[i].MANUFACTURER = edit_string;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 2:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "Введите изменение (прошлое значение - " << a[i].CODE << "):\n";
                                cin >> edit_string;
                                a[i].CODE = edit_string;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 3:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "Введите изменение (прошлое значение - " << a[i].CAR_INFO.YEAR << " г.):\n";
                                cin >> edit_int;
                                a[i].CAR_INFO.YEAR = edit_int;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 4:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "Введите изменение (прошлое значение - " << a[i].CAR_INFO.MILEAGE << " км.):\n";
                                cin >> edit_int;
                                a[i].CAR_INFO.MILEAGE = edit_int;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 5:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "Введите изменение (прошлое значение - " << a[i].CAR_INFO.VOLUME << " см. куб.):\n";
                                cin >> edit_int;
                                a[i].CAR_INFO.VOLUME = edit_int;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 6:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "Введите изменение (1 - Внедорожник, 2 - Лифтбек, 3 - Седан, 4 - Хэтчбек) (прошлое значение - " << a[i].CAR_INFO.BODYWORK << "):\n";
                                cin >> edit_int;
                                a[i].CAR_INFO.BODYWORK = edit_int;
                                break;
                            }
                    o_bool++;
                }
                case 7:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "Введите изменение (прошлое значение - " << a[i].CAR_INFO.PRICE << " руб.):\n";
                                cin >> edit_int;
                                a[i].CAR_INFO.PRICE = edit_int;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 8:
                {
                    o_bool++;
                }
                break;
                default: cout << "\nВведёное вами число не из меню.";
                }
            } while (o_bool == 0);
    }
    cout << "Возвращение к меню.\n" << endl;
}

void rewrite(car* a, int b)
{
    ofstream my_outfile;
    my_outfile.open("Log.txt");
    if (my_outfile.is_open())
    {
        for (int i = 0; i < b; i++)
        {
            my_outfile << a[i].MANUFACTURER << " ";
            my_outfile << a[i].CODE << " ";
            my_outfile << a[i].CAR_INFO.YEAR << " ";
            my_outfile << a[i].CAR_INFO.MILEAGE << " ";
            my_outfile << a[i].CAR_INFO.VOLUME << " ";
            my_outfile << a[i].CAR_INFO.BODYWORK << " ";
            my_outfile << a[i].CAR_INFO.PRICE << " ";
            if (i + 1 != b) my_outfile << "\n";
        }
    }
}

void menu(car*& a, int& b)
{
    int number_in_menu, o_bool = 0;
    do
    {
        printf_s("1. Вывести все машины на экран.\n2. Добавить машину.\n3. Удалить машину.\n4. Внести изменения.\n5. Перезаписать в файл.\n6. Поиск.\n7. Вычисление.\n8. Закончить работу.\n");
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            display(a, b);
        }
        break;
        case 2:
        {
            add(a, b);
        } break;
        case 3:
        {
            del(a, b);
        } break;
        case 4:
        {
            edit(a, b);
        } break;
        case 5:
        {
            rewrite(a, b);
        } break;
        case 6:
        {
            search(a, b);
        } break;
        case 7:
        {
            calculation(a, b);
        } break;
        case 8:
        {
            o_bool = 1;
        } break;
        default: cout << "\nВведёное вами число не из меню.";
        }
    } while (o_bool == 0);
}