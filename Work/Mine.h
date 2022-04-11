#pragma once
using namespace std;

struct lib_info
{
    string AUTHOR;
    string RELEASE_YEAR;
    int QUANTITY = 0;
    bool GIVEN;
    string STORED;
};

struct home_library
{
    string NAME;
    lib_info LIB_INFO;
};

void delete_underscores(string& str) //Работает.
{
    int n = str.length(), i = 0;
    while (i < n)
    {
        if (str[i] == '_')
        {
            str.replace(i, 1, " ");
        }
        i++;
    }
}

void add_underscores(string& str) //Работает.
{
    int n = str.length(), i = 0;
    while (i < n)
    {
        if (str[i] == ' ')
        {
            str.replace(i, 1, "_");
        }
        i++;
    }
}

void number_of_structs(fstream& a, int& b, int& c) //Работает.
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

void createstructs(fstream& a, int b, home_library*& c) //Работает.
{
    char symbol;
    string my_string;
    fstream my_file;
    my_file.open("Log.txt");
    if (my_file.is_open())
    {
        for (int i = 0; i < b; i++)
        {
            my_file >> my_string;
            delete_underscores(my_string);
            c[i].NAME = my_string;
            my_file >> my_string;
            delete_underscores(my_string);
            c[i].LIB_INFO.AUTHOR = my_string;
            my_file >> c[i].LIB_INFO.RELEASE_YEAR;
            my_file >> c[i].LIB_INFO.QUANTITY;
            my_file >> symbol;
            switch (symbol)
            {
            case '+':
            {
                c[i].LIB_INFO.GIVEN = true;
            }
            break;
            case '-':
            {
                c[i].LIB_INFO.GIVEN = false;
            } break;
            }
            my_file >> my_string;
            delete_underscores(my_string);
            c[i].LIB_INFO.STORED = my_string;
        }
    }
    my_file.close();
}

void create_new_struct(int b, home_library*& a) //Работает.
{
    home_library* books = new home_library[b - 1];
    for (int i = 0; i < b - 1; i++)
    {
        books[i].NAME = a[i].NAME;
        books[i].LIB_INFO.AUTHOR = a[i].LIB_INFO.AUTHOR;
        books[i].LIB_INFO.RELEASE_YEAR = a[i].LIB_INFO.RELEASE_YEAR;
        books[i].LIB_INFO.QUANTITY = a[i].LIB_INFO.QUANTITY;
        books[i].LIB_INFO.GIVEN = a[i].LIB_INFO.GIVEN;
        books[i].LIB_INFO.STORED = a[i].LIB_INFO.STORED;
    }
    delete[] a;
    home_library* book_s = new home_library[b];
    for (int i = 0; i < b - 1; i++)
    {
        book_s[i].NAME = books[i].NAME;
        book_s[i].LIB_INFO.AUTHOR = books[i].LIB_INFO.AUTHOR;
        book_s[i].LIB_INFO.RELEASE_YEAR = books[i].LIB_INFO.RELEASE_YEAR;
        book_s[i].LIB_INFO.QUANTITY = books[i].LIB_INFO.QUANTITY;
        book_s[i].LIB_INFO.GIVEN = books[i].LIB_INFO.GIVEN;
        book_s[i].LIB_INFO.STORED = books[i].LIB_INFO.STORED;
    }
    a = book_s;
}

void display(home_library* a, int b) //Работает.
{
    for (int i = 0; i < b; i++)
    {
        cout << "Название книги: " << a[i].NAME << endl;
        cout << "Автор: " << a[i].LIB_INFO.AUTHOR << endl;
        cout << "Дата публикации: " << a[i].LIB_INFO.RELEASE_YEAR << " г." << endl;
        cout << "Количество: " << a[i].LIB_INFO.QUANTITY << endl;
        if (a[i].LIB_INFO.GIVEN == true) cout << "Статус: Отдано" << endl;
        if (a[i].LIB_INFO.GIVEN == false) cout << "Статус: Есть в библиотеке" << endl;
        cout << "Хранится у... : " << a[i].LIB_INFO.STORED << endl;
        cout << endl;
    }
    cout << "Выберите пункт меню." << endl;
}

void add(home_library*& a, int& b)
{
    char word;
    b++;
    create_new_struct(b, a);
    for (int i = 0; i < b; i++)
    {
        if (i == b - 1)
        {
            cin.ignore(255, '\n');
            cout << "Введите название книги:\n> ";
            getline(cin, a[i].NAME);
            cout << "Введите автора:\n> ";
            getline(cin, a[i].LIB_INFO.AUTHOR);
            cout << "Введите дату публикации:\n> ";
            getline(cin, a[i].LIB_INFO.RELEASE_YEAR);
            cout << "Введите количество таких книг в библиотеке:\n> ";
            cin >> a[i].LIB_INFO.QUANTITY;
            cout << "Введите [+], если книга отдана, [-], если она хранится в библиотеке:\n> ";
            cin >> word;
            if (word == '+') a[i].LIB_INFO.GIVEN = true;
            if (word == '-') a[i].LIB_INFO.GIVEN = false;
            cin.ignore(255, '\n');
            cout << "Введите ФИО человека, у которого хранится эта книга (если она хранится у Вас, введите 'Я'):\n> ";
            getline(cin, a[i].LIB_INFO.STORED);
        }
    }
    cout << "Добавление прошло успешно.\nВыберите пункт меню." << endl;
}

void del(home_library* a, int& b)
{
    string auth, name;
    int number = 0, number1 = 0, ooo_bool = 0, oooo_bool = 0;
    cout << "Введите автора, чью книгу вы хотите удалить:\n";
    for (int i = 0; i < b; i++)
    {
        if (ooo_bool == 1)
            for (int n = 0; n < i; n++)
                if (a[i].LIB_INFO.AUTHOR == a[n].LIB_INFO.AUTHOR)
                {
                    oooo_bool++;
                }
        if (oooo_bool == 0) cout << a[i].LIB_INFO.AUTHOR << "\n";
        ooo_bool++;
        oooo_bool = 0;
    }
    cin.ignore(255, '\n');
    cout << "> ";
    getline(cin, auth);
    for (int i = 0; i < b; i++) if (auth == a[i].LIB_INFO.AUTHOR) number1++;
    if (number1 == 0) cout << "С таким именем книг не обнаружено." << endl;
    if (number1 == 1)
    {
        cout << "Найдена одна книга от данного автора. Удаляем её..." << endl;
        for (int i = 0; i < b; i++)
        {
            if (number == 1)
            {
                a[i - 1].NAME = a[i].NAME;
                a[i - 1].LIB_INFO.AUTHOR = a[i].LIB_INFO.AUTHOR;
                a[i - 1].LIB_INFO.RELEASE_YEAR = a[i].LIB_INFO.RELEASE_YEAR;
                a[i - 1].LIB_INFO.QUANTITY = a[i].LIB_INFO.QUANTITY;
                a[i - 1].LIB_INFO.GIVEN = a[i].LIB_INFO.GIVEN;
                a[i - 1].LIB_INFO.STORED = a[i].LIB_INFO.STORED;
            }
            if (auth == a[i].LIB_INFO.AUTHOR) number = 1;
        }
    }
    if (number1 > 1)
    {
        cout << "Найдено несколько (" << number1 << ") книг от данного автора. Выберите, пожалуйста, нужную из приведённых:\n";
        for (int i = 0; i < b; i++) if (auth == a[i].LIB_INFO.AUTHOR) cout << a[i].NAME << endl;
        cout << "> ";
        getline(cin, name);
        for (int i = 0; i < b; i++)
        {
            if (number == 1)
            {
                a[i - 1].NAME = a[i].NAME;
                a[i - 1].LIB_INFO.AUTHOR = a[i].LIB_INFO.AUTHOR;
                a[i - 1].LIB_INFO.RELEASE_YEAR = a[i].LIB_INFO.RELEASE_YEAR;
                a[i - 1].LIB_INFO.QUANTITY = a[i].LIB_INFO.QUANTITY;
                a[i - 1].LIB_INFO.GIVEN = a[i].LIB_INFO.GIVEN;
                a[i - 1].LIB_INFO.STORED = a[i].LIB_INFO.STORED;
            }
            if (name == a[i].NAME) number = 1;
        }
        if (number == 0) cout << "Книг от данного автора с таким названием не обнаружено." << endl;
    }
    if (number == 1) b--;
    cout << "Выберите пункт меню." << endl;
}

void search(home_library* a, int b)
{
    int number, o_bool = 0;
    do
    {
        cout << "Что вы хотите найти?\n1. Все книги от к.-л. автора.\n2. Кто написал ту или иную книгу.\n3. Выйти.\n> ";
        cin >> number;
        switch (number)
        {
        case 1:
        {
            string author;
            int o = 0, oo_bool = 0;
            cout << "Введите инициалы автора, записанные в программе:\n> ";
            cin.ignore(255, '\n');
            getline(cin, author);
            cout << "Все книги данного автора:";
            for (int i = 0; i < b; i++)
            {
                if (author == a[i].LIB_INFO.AUTHOR)
                {
                    if (oo_bool == 0)
                    {
                        cout << " ";
                        oo_bool++;
                    }
                    else cout << ", ";
                    cout << a[i].NAME;
                    o++;
                }
            }
            if (o == 0) cout << " нет/не найдены.";
            if(o >= 1) cout << ".";
            cout << endl;
        }
        break;
        case 2:
        {
            string name;
            int oo_bool = 0;
            cout << "Введите название книги:\n> ";
            cin.ignore(255, '\n');
            getline(cin, name);
            for (int i = 0; i < b; i++)
            {
                if (name == a[i].NAME)
                {
                    cout << "Книга была написана автором " << a[i].LIB_INFO.AUTHOR;
                    oo_bool++;
                }
            }
            if (oo_bool == 0) cout << "Книга с таким названием не найдена.";
            cout << endl;
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

void calculation(home_library* a, int b)
{
    int number, o_bool = 0;
    cout << "";
    do
    {
        cout << "Что вы хотите вычислить?\n1. Самое большое количество одинаковых книг.\n2. Количество отданных книг.\n3. Выйти.\n> ";
        cin >> number;
        switch (number)
        {
        case 1:
        {
            int max = 0, o = 0;
            for (int i = 0; i < b; i++) if (a[i].LIB_INFO.QUANTITY > max) max = a[i].LIB_INFO.QUANTITY;
            for (int i = 0; i < b; i++)
                if (max == a[i].LIB_INFO.QUANTITY) cout << a[i].LIB_INFO.QUANTITY << " -- " << a[i].NAME << endl;
        }
        break;
        case 2:
        {
            int number = 0;
            cout << "Количество отданных: ";
            for (int i = 0; i < b; i++) if (a[i].LIB_INFO.GIVEN == true) number++;
            cout << number << "\nОтданные книги:";
            for (int i = 0; i < b; i++) if (a[i].LIB_INFO.GIVEN == true)
            {
                cout << " ";
                cout << a[i].NAME;
            }
            cout << endl;
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

void edit(home_library*& a, int b)
{
    int o_bool = 0, number_menu, edit_int, bool_number = 0, bool_number_2 = 0, oo_bool = 0, ooo_bool = 0, oooo_bool = 0;
    char edit_char;
    string edit_string, author, name;
    cout << "Выберите автора:\n";
    for (int i = 0; i < b; i++)
    {
        if (ooo_bool == 1)
            for (int n = 0; n < i; n++)
                if (a[i].LIB_INFO.AUTHOR == a[n].LIB_INFO.AUTHOR)
                {
                    oooo_bool++;
                }
        if (oooo_bool == 0) cout << a[i].LIB_INFO.AUTHOR << "\n";
        ooo_bool++;
        oooo_bool = 0;
    }
    do
    {
        cin.ignore(255, '\n');
        cout << "> ";
        getline(cin, author);
        if (bool_number < 2)
        {
            for (int i = 0; i < b; i++) if (author == a[i].LIB_INFO.AUTHOR) o_bool++;
            if (o_bool == 0)
            {
                cout << "Повторите ввод.\n";
                bool_number++;
            }
        }
        else
        {
            cout << "Вы ввели автора неправильно 3 раза подряд. Желаете выйти в меню для выбора другой операции?\n1. Да, выйти в меню.\n2. Нет, попробовать ещё.\n> ";
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
        cout << "Выберите название книги:\n";
        for (int i = 0; i < b; i++) if (author == a[i].LIB_INFO.AUTHOR) cout << a[i].NAME << "\n";
        do
        {
            cout << "> ";
            getline(cin, name);
            if (bool_number < 2)
            {
                for (int i = 0; i < b; i++) if (name == a[i].NAME) o_bool++;
                if (o_bool == 0)
                {
                    cout << "Повторите ввод.\n";
                    bool_number++;
                }
            }
            else
            {
                cout << "Вы ввели название неправильно 3 раза подряд. Желаете выйти в меню для выбора другой операции?\n1. Да, выйти в меню.\n2. Нет, попробовать ещё.\n> ";
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
                cout << "Выберите, что вы хотите изменить:\n1. Название\n2. Автора\n3. Дату публикации\n4. Количество\n5. Отдано/Не отдано\n6. Хранится у...\n7. Выйти в главное меню\n> ";
                cin >> number_menu;
                switch (number_menu)
                {
                case 1:
                {
                    for (int i = 0; i < b; i++)
                        if (author == a[i].LIB_INFO.AUTHOR)
                            if (name == a[i].NAME)
                            {
                                cin.ignore(255, '\n');
                                cout << "Введите изменение:\n> ";
                                getline(cin, a[i].NAME);
                                break;
                            }
                    o_bool++;
                }
                break;
                case 2:
                {
                    for (int i = 0; i < b; i++)
                        if (author == a[i].LIB_INFO.AUTHOR)
                            if (name == a[i].NAME)
                            {
                                cin.ignore(255, '\n');
                                cout << "Введите изменение:\n> ";
                                getline(cin, a[i].LIB_INFO.AUTHOR);
                                break;
                            }
                    o_bool++;
                }
                break;
                case 3:
                {
                    for (int i = 0; i < b; i++)
                        if (author == a[i].LIB_INFO.AUTHOR)
                            if (name == a[i].NAME)
                            {
                                cin.ignore(255, '\n');
                                cout << "Введите изменение:\n> ";
                                getline(cin, a[i].LIB_INFO.RELEASE_YEAR);
                                break;
                            }
                    o_bool++;
                }
                break;
                case 4:
                {
                    for (int i = 0; i < b; i++)
                        if (author == a[i].LIB_INFO.AUTHOR)
                            if (name == a[i].NAME)
                            {
                                cout << "Введите изменение:\n> ";
                                cin >> edit_int;
                                a[i].LIB_INFO.QUANTITY = edit_int;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 5:
                {
                    for (int i = 0; i < b; i++)
                        if (author == a[i].LIB_INFO.AUTHOR)
                            if (name == a[i].NAME)
                            {
                                cout << "Введите изменение (отдано [+] или хранится в библиотеке [-]):\n> ";
                                cin >> edit_char;
                                if (edit_char == '+') a[i].LIB_INFO.GIVEN = true;
                                if (edit_char == '-') a[i].LIB_INFO.GIVEN = false;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 6:
                {
                    for (int i = 0; i < b; i++)
                        if (author == a[i].LIB_INFO.AUTHOR)
                            if (name == a[i].NAME)
                            {
                                cin.ignore(255, '\n');
                                cout << "Введите изменение:\n> ";
                                getline(cin, a[i].LIB_INFO.STORED);
                                break;
                            }
                    o_bool++;
                }
                break;
                case 7:
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

void rewrite(home_library* a, int b)
{
    string my_string;
    ofstream my_outfile;
    my_outfile.open("Log.txt");
    if (my_outfile.is_open())
    {
        for (int i = 0; i < b; i++)
        {
            my_string = a[i].NAME;
            add_underscores(my_string);
            my_outfile << my_string << " ";
            my_string = a[i].LIB_INFO.AUTHOR;
            add_underscores(my_string);
            my_outfile << my_string << " ";
            my_outfile << a[i].LIB_INFO.RELEASE_YEAR << " ";
            my_outfile << a[i].LIB_INFO.QUANTITY << " ";
            if (a[i].LIB_INFO.GIVEN == true) my_outfile << "+ ";
            if (a[i].LIB_INFO.GIVEN == false) my_outfile << "- ";
            my_string = a[i].LIB_INFO.STORED;
            add_underscores(my_string);
            my_outfile << my_string << " ";
            if (i + 1 != b) my_outfile << "\n";
        }
    }
    cout << "Перезапись прошла успешно.\nВыберите пункт меню." << endl;
}

void menu(home_library*& a, int& b)
{
    int number_in_menu, o_bool = 0;
    do
    {
        printf_s("1. Вывести все книги на экран.\n2. Добавить книгу.\n3. Удалить книгу.\n4. Внести изменения.\n5. Перезаписать в файл.\n6. Поиск.\n7. Вычисление.\n8. Закончить работу.\n");
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