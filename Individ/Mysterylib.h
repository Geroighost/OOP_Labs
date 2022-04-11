#pragma once
using namespace std;

struct tv_info
{
    float DIAGONAL = 0;
    string RESOLUTION;
    string TECHNOLOGY;
    int UPDATE_RATE = 0;
    int HDMI_NUMBER = 0;
    bool HDR;
    bool SMART_TV;
};

struct tv
{
    string MANUFACTURER;
    string CODE;
    tv_info TV_INFO;
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

void createstructs(fstream& a, int b, tv*& c)
{
    char symbol;
    fstream my_file;
    my_file.open("Log.txt");
    if (my_file.is_open())
    {
        for (int i = 0; i < b; i++)
        {
            my_file >> c[i].MANUFACTURER;
            my_file >> c[i].CODE;
            my_file >> c[i].TV_INFO.DIAGONAL;
            my_file >> c[i].TV_INFO.RESOLUTION;
            my_file >> c[i].TV_INFO.TECHNOLOGY;
            my_file >> c[i].TV_INFO.UPDATE_RATE;
            my_file >> c[i].TV_INFO.HDMI_NUMBER;
            my_file >> symbol;
            switch (symbol)
            {
            case '+':
            {
                c[i].TV_INFO.HDR = true;
            }
            break;
            case '-':
            {
                c[i].TV_INFO.HDR = false;
            } break;
            }
            my_file >> symbol;
            if (symbol == '+') c[i].TV_INFO.SMART_TV = true;
            if (symbol == '-') c[i].TV_INFO.SMART_TV = false;
        }
    }
    my_file.close();
}

void create_new_struct(int b, tv*& a)
{
    tv* tv_es = new tv[b - 1];
    for (int i = 0; i < b - 1; i++)
    {
        tv_es[i].MANUFACTURER = a[i].MANUFACTURER;
        tv_es[i].CODE = a[i].CODE;
        tv_es[i].TV_INFO.DIAGONAL = a[i].TV_INFO.DIAGONAL;
        tv_es[i].TV_INFO.HDMI_NUMBER = a[i].TV_INFO.HDMI_NUMBER;
        tv_es[i].TV_INFO.HDR = a[i].TV_INFO.HDR;
        tv_es[i].TV_INFO.RESOLUTION = a[i].TV_INFO.RESOLUTION;
        tv_es[i].TV_INFO.SMART_TV = a[i].TV_INFO.SMART_TV;
        tv_es[i].TV_INFO.TECHNOLOGY = a[i].TV_INFO.TECHNOLOGY;
        tv_es[i].TV_INFO.UPDATE_RATE = a[i].TV_INFO.UPDATE_RATE;
    }
    delete[] a;
    tv* tv_s = new tv[b];
    for (int i = 0; i < b - 1; i++)
    {
        tv_s[i].MANUFACTURER = tv_es[i].MANUFACTURER;
        tv_s[i].CODE = tv_es[i].CODE;
        tv_s[i].TV_INFO.DIAGONAL = tv_es[i].TV_INFO.DIAGONAL;
        tv_s[i].TV_INFO.HDMI_NUMBER = tv_es[i].TV_INFO.HDMI_NUMBER;
        tv_s[i].TV_INFO.HDR = tv_es[i].TV_INFO.HDR;
        tv_s[i].TV_INFO.RESOLUTION = tv_es[i].TV_INFO.RESOLUTION;
        tv_s[i].TV_INFO.SMART_TV = tv_es[i].TV_INFO.SMART_TV;
        tv_s[i].TV_INFO.TECHNOLOGY = tv_es[i].TV_INFO.TECHNOLOGY;
        tv_s[i].TV_INFO.UPDATE_RATE = tv_es[i].TV_INFO.UPDATE_RATE;
    }
    a = tv_s;
}

void display(tv* a, int b)
{
    for (int i = 0; i < b; i++)
    {
        cout << "Марка: " << a[i].MANUFACTURER << endl;
        cout << "Производственный код: " << a[i].CODE << endl;
        cout << "Диагональ: " << a[i].TV_INFO.DIAGONAL << "''" << endl;
        cout << "Разрешение: " << a[i].TV_INFO.RESOLUTION << endl;
        cout << "Технология экрана: " << a[i].TV_INFO.TECHNOLOGY << endl;
        cout << "Частота обновления: " << a[i].TV_INFO.UPDATE_RATE << " Гц" << endl;
        cout << "Количество HDMI: " << a[i].TV_INFO.HDMI_NUMBER << endl;
        if (a[i].TV_INFO.HDR == true) cout << "HDR: Присутствует" << endl;
        if (a[i].TV_INFO.HDR == false) cout << "HDR: Отсутствует" << endl;
        if (a[i].TV_INFO.SMART_TV == true) cout << "Smart TV: Присутствует" << endl;
        if (a[i].TV_INFO.SMART_TV == false) cout << "Smart TV: Отсутствует" << endl;
        cout << endl;
    }
    cout << "Выберите пункт меню." << endl;
}

void add(tv*& a, int& b)
{
    char word;
    b++;
    create_new_struct(b, a);
    for (int i = 0; i < b; i++)
    {
        if (i == b - 1)
        {
            cout << "Введите марку телевизора:\n> ";
            cin >> a[i].MANUFACTURER;
            cout << "Введите код марки телевизора:\n> ";
            cin >> a[i].CODE;
            cout << "Введите диагональ телевизора:\n> ";
            cin >> a[i].TV_INFO.DIAGONAL;
            cout << "Введите разрешение телевизора:\n> ";
            cin >> a[i].TV_INFO.RESOLUTION;
            cout << "Введите технологию телевизора:\n> ";
            cin >> a[i].TV_INFO.TECHNOLOGY;
            cout << "Введите частоту обновления телевизора:\n> ";
            cin >> a[i].TV_INFO.UPDATE_RATE;
            cout << "Введите количество HDMI телевизора:\n> ";
            cin >> a[i].TV_INFO.HDMI_NUMBER;
            cout << "Введите [+], если HDR у телевизора есть, [-], если его нет:\n> ";
            cin >> word;
            if (word == '+') a[i].TV_INFO.HDR = true;
            if (word == '-') a[i].TV_INFO.HDR = false;
            cout << "Введите [+], если Smart TV у телевизора есть, [-], если его нет:\n> ";
            cin >> word;
            if (word == '+') a[i].TV_INFO.SMART_TV = true;
            if (word == '-') a[i].TV_INFO.SMART_TV = false;
        }
    }
    cout << "Добавление прошло успешно.\nВыберите пункт меню." << endl;
}

void del(tv* a, int& b)
{
    string mark, code;
    int number = 0, number1 = 0;
    cout << "Введите марку телевизора, который нужно удалить:\n> ";
    cin >> mark;
    for (int i = 0; i < b; i++) if (mark == a[i].MANUFACTURER) number1++;
    if (number1 == 0) cout << "Телевизоров с такой маркой не обнаружено." << endl;
    if (number1 == 1)
    {
        cout << "Найден 1 телевизор с такой маркой. Удаляем этот телевизор..." << endl;
        for (int i = 0; i < b; i++)
        {
            if (number == 1)
            {
                a[i - 1].MANUFACTURER = a[i].MANUFACTURER;
                a[i - 1].CODE = a[i].CODE;
                a[i - 1].TV_INFO.DIAGONAL = a[i].TV_INFO.DIAGONAL;
                a[i - 1].TV_INFO.RESOLUTION = a[i].TV_INFO.RESOLUTION;
                a[i - 1].TV_INFO.TECHNOLOGY = a[i].TV_INFO.TECHNOLOGY;
                a[i - 1].TV_INFO.UPDATE_RATE = a[i].TV_INFO.UPDATE_RATE;
                a[i - 1].TV_INFO.HDMI_NUMBER = a[i].TV_INFO.HDMI_NUMBER;
                a[i - 1].TV_INFO.HDR = a[i].TV_INFO.HDR;
                a[i - 1].TV_INFO.SMART_TV = a[i].TV_INFO.SMART_TV;
            }
            if (mark == a[i].MANUFACTURER) number = 1;
        }
    }
    if (number1 > 1)
    {
        cout << "Найдено несколько (" << number1 << ") телевизоров с такой маркой. Выберите, пожалуйста, марку телевизора из приведённых:\n";
        for (int i = 0; i < b; i++) cout << a[i].CODE << endl;
        cout << "> ";
        cin >> code;
        for (int i = 0; i < b; i++)
        {
            if (number == 1)
            {
                a[i - 1].MANUFACTURER = a[i].MANUFACTURER;
                a[i - 1].CODE = a[i].CODE;
                a[i - 1].TV_INFO.DIAGONAL = a[i].TV_INFO.DIAGONAL;
                a[i - 1].TV_INFO.RESOLUTION = a[i].TV_INFO.RESOLUTION;
                a[i - 1].TV_INFO.TECHNOLOGY = a[i].TV_INFO.TECHNOLOGY;
                a[i - 1].TV_INFO.UPDATE_RATE = a[i].TV_INFO.UPDATE_RATE;
                a[i - 1].TV_INFO.HDMI_NUMBER = a[i].TV_INFO.HDMI_NUMBER;
                a[i - 1].TV_INFO.HDR = a[i].TV_INFO.HDR;
                a[i - 1].TV_INFO.SMART_TV = a[i].TV_INFO.SMART_TV;
            }
            if (code == a[i].CODE) number = 1;
        }
        if (number == 0) cout << "Телевизоров с такой маркой и кодом не обнаружено." << endl;
    }
    if (number == 1) b--;
    cout << "Успешно удалено.\nВыберите пункт меню." << endl;
}

void search(tv* a, int b)
{
    int number, o_bool = 0;
    cout << "Что вы хотите найти?\n1. Телевизор с самым большим разрешением.\n2. Телевизор с самой большой диагональю.\n3. Выйти.\n";
    do
    {
        cout << "> ";
        cin >> number;
        switch (number)
        {
        case 1:
        {
            string resol, max = "0";
            for (int i = 0; i < b; i++)
            {
                resol = a[i].TV_INFO.RESOLUTION;
                if (resol > max) max = resol;
            }
            for (int i = 0; i < b; i++)
            {
                if (max == a[i].TV_INFO.RESOLUTION)
                    cout << "У телевизора " << a[i].MANUFACTURER << " под кодом " << a[i].CODE << " самое большое разрешение, равное " << a[i].TV_INFO.RESOLUTION << "." << endl;
            }
            max = "0";

        }
        break;
        case 2:
        {
            float diagon = 0, max = 0;
            for (int i = 0; i < b; i++)
            {
                diagon = a[i].TV_INFO.DIAGONAL;
                if (diagon > max) max = diagon;
            }
            for (int i = 0; i < b; i++)
            {
                if (max == a[i].TV_INFO.DIAGONAL)
                    cout << "У телевизора " << a[i].MANUFACTURER << " под кодом " << a[i].CODE << " самая большая диагональ, равная " << a[i].TV_INFO.DIAGONAL << "." << endl;
            }
            max = 0;
        } break;
        case 3:
        {
            o_bool = 1;
        } break;
        default: cout << "Введёное вами число не из данного меню.\n";
        }
    } while (o_bool == 0);
    cout << "Возвращение в меню." << endl;
}

void calculation(tv* a, int b)
{
    int number, o_bool = 0;
    cout << "Что вы хотите вычислить?\n1. Количество телевизоров со Smart TV.\n2. Количество телевизоров с более чем одним HDMI.\n3. Выйти.\n";
    do
    {
        cout << "> ";
        cin >> number;
        switch (number)
        {
        case 1:
        {
            int all_smart = 0;
            for (int i = 0; i < b; i++)
            {
                if (a[i].TV_INFO.SMART_TV == true) all_smart++;
            }
            switch (all_smart)
            {
            case 1: cout << "Всего есть " << all_smart << " телевизор со Smart TV в списке." << endl; break;
            case 2: case 3: case 4: cout << "Всего есть " << all_smart << " телевизора со Smart TV в списке." << endl; break;
            default: cout << "Всего есть " << all_smart << " телевизоров со Smart TV в списке." << endl; break;
            }
        }
        break;
        case 2:
        {
            int all_hdmi = 0;
            for (int i = 0; i < b; i++)
            {
                if (a[i].TV_INFO.HDMI_NUMBER > 1) all_hdmi++;
            }
            switch (all_hdmi)
            {
            case 1: cout << "Всего есть " << all_hdmi << " телевизор с более чем одним HDMI в списке." << endl; break;
            case 2: case 3: case 4: cout << "Всего есть " << all_hdmi << " телевизора с более чем одним HDMI в списке." << endl; break;
            default: cout << "Всего есть " << all_hdmi << " телевизоров с более чем одним HDMI в списке." << endl; break;
            }
        }
        break;
        case 3:
        {
            o_bool = 1;
        } break;
        default: cout << "Введёное вами число не из данного меню.\n";
        }
    } while (o_bool == 0);
    cout << "Возвращение к меню." << endl;
}

void edit(tv*& a, int b)
{
    int o_bool = 0, number_menu, edit_int, bool_number = 0, bool_number_2 = 0, oo_bool = 0;
    float edit_float;
    string mark, code, edit_string;
    char edit_char;
    do
    {
        cout << "Выберите марку телевизора:\n";
        for (int i = 0; i < b; i++) cout << a[i].MANUFACTURER << "\n";
        cout << endl;
        cout << "> ";
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
            cout << "Выберите код телевизора:\n";
            for (int i = 0; i < b; i++) if (mark == a[i].MANUFACTURER) cout << a[i].CODE << "\n";
            cout << endl;
            cout << "> ";
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
                cout << "Выберите, что вы хотите изменить:\n1. Марка\n2. Код\n3. Диагональ\n4. Разрешение\n5. Технология экрана\n6. Частота обновления\n7. Количество HDMI\n8. Наличие HDR\n9. Наличие Smart TV\n10. Выйти в окно\n> ";
                cin >> number_menu;
                switch (number_menu)
                {
                case 1:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "Введите изменение:\n> ";
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
                                cout << "Введите изменение:\n> ";
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
                                cout << "Введите изменение:\n> ";
                                cin >> edit_float;
                                a[i].TV_INFO.DIAGONAL = edit_float;
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
                                cout << "Введите изменение:\n> ";
                                cin >> edit_string;
                                a[i].TV_INFO.RESOLUTION = edit_string;
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
                                cout << "Введите изменение:\n> ";
                                cin >> edit_string;
                                a[i].TV_INFO.TECHNOLOGY = edit_string;
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
                                cout << "Введите изменение:\n> ";
                                cin >> edit_int;
                                a[i].TV_INFO.UPDATE_RATE = edit_int;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 7:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "Введите изменение:\n> ";
                                cin >> edit_int;
                                a[i].TV_INFO.HDMI_NUMBER = edit_int;
                                break;
                                cout << a[i].TV_INFO.HDMI_NUMBER;
                            }
                    o_bool++;
                }
                break;
                case 8:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "Введите изменение (есть [+] или нет [-]):\n> ";
                                cin >> edit_char;
                                if (edit_char == '+') a[i].TV_INFO.HDR = true;
                                if (edit_char == '-') a[i].TV_INFO.HDR = false;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 9:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "Введите изменение (есть [+] или нет [-]):\n> ";
                                cin >> edit_char;
                                if (edit_char == '+') a[i].TV_INFO.SMART_TV = true;
                                if (edit_char == '-') a[i].TV_INFO.SMART_TV = false;
                            }
                    o_bool++;
                }
                break;
                case 10:
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

void rewrite(tv* a, int b)
{
    ofstream my_outfile;
    my_outfile.open("Log.txt");
    if (my_outfile.is_open())
    {
        for (int i = 0; i < b; i++)
        {
            my_outfile << a[i].MANUFACTURER << " ";
            my_outfile << a[i].CODE << " ";
            my_outfile << a[i].TV_INFO.DIAGONAL << " ";
            my_outfile << a[i].TV_INFO.RESOLUTION << " ";
            my_outfile << a[i].TV_INFO.TECHNOLOGY << " ";
            my_outfile << a[i].TV_INFO.UPDATE_RATE << " ";
            my_outfile << a[i].TV_INFO.HDMI_NUMBER << " ";
            if (a[i].TV_INFO.HDR == true) my_outfile << "+ ";
            if (a[i].TV_INFO.HDR == false) my_outfile << "- ";
            if (a[i].TV_INFO.SMART_TV == true) my_outfile << "+";
            if (a[i].TV_INFO.SMART_TV == false) my_outfile << "-";
            if (i + 1 != b) my_outfile << "\n";
        }
    }
    cout << "Перезапись прошла успешно.\nВыберите пункт меню." << endl;
}

void menu(tv*& a, int& b)
{
    int number_in_menu, o_bool = 0;
    do
    {
        printf_s("1. Вывести все телевизоры на экран.\n2. Добавить телевизор.\n3. Удалить телевизор.\n4. Внести изменения.\n5. Перезаписать в файл.\n6. Поиск.\n7. Вычисление.\n8. Закончить работу.\n");
        cout << "> ";
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