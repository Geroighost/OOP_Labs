#include <iostream>
#include "string"

using namespace std;

void vvod(struct book*, int);
void restrt(int &);
void disply(struct book*, int);

struct book
{
    string FAM;
    string NAZV;
    int YEAR;
};

int main()
{
    string lastname;
    int numberofbooks, bill, o1, i;
    bill = 0;
    o1 = 0;
    setlocale(LC_ALL, "RUSSIAN");
    cout << "Примечание: Переключите на английскую раскладку и вместо пробелов ставьте символ [_].";
    cout << "\nВведите количество книг:\n> ";
    cin >> numberofbooks;
    book* books = new book[numberofbooks];
    vvod(books, numberofbooks);
    do
    {
        disply(books, numberofbooks);
        restrt(o1);
    } while (o1 == 0);
    cout << "Сеанс закончен.";
    return 0;
}

void vvod(book* c, int d)
{
    for (int i = 0; i < d; i++)
    {
        cout << "\nКнига №" << i + 1 << ":";
        cout << "\nВведите фамилию автора:\n> ";
        cin >> c[i].FAM;
        cout << "\nВведите название книги:\n> ";
        cin >> c[i].NAZV;
        cout << "\nВведите год издания:\n> ";
        cin >> c[i].YEAR;
    }
}

void restrt(int &n)
{
    cout << "\nХотите повторить?\n1. Да\n2. Нет";
    int i, o;
    o = 0;
    do
    {
    cout << "\n> ";
    cin >> i;
    switch (i)
    {
    case 1:
    {
        o++;
    }
    break;
    case 2:
    {
        o++;
        n++;
    }
    break;
    default: cout << "\nВведёное вами число не из меню.";
    }
    } while (o == 0);
    o--;
}

void disply(book* c, int d)
{
    int bill = 0;
    string lastname;
    cout << "Введите фамилию автора, чтобы найти соответствующие книги:\n> ";
    cin >> lastname;
    for (int i = 0; i < d; i++)
    {
        if (lastname == c[i].FAM)
        {
            cout << "\nНазвание книги: " << c[i].NAZV << "\nГод издания: " << c[i].YEAR;
            bill++;
        }
    }
    if (bill == 0) cout << "Данной фамилии нет в записях.";
}
