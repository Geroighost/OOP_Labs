#include <iostream>
#include "string"

using namespace std;

struct price
{
    string tovar;
    string mag;
    int stoim;
};
    
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    string nazv;
    int n = 0, flag,i=0;
    flag = 0;
    cout<<"Введите размер массива:";
    cin>>n;
    price *spisok = new price[n];
    for (int i = 0; i < n; i++);
    {
        cout<<"Товар №"<<i+1<<":";
        cout<<"\nВведите название товара:";
        cin >> spisok[i].tovar;
        cout<<"\nВведите название магазина,в котором находится данный товар:";
        cin >> spisok[i].mag;
        cout<<"\nВведите стоимость товара в рублях:";
        cin >> spisok[i].stoim;  
    }
    cout<<"\nВведите название товара,чтобы узнать информацию о нем:";
    cin >> nazv;
    for (int i = 0; i < n; i++)
    {
        if (nazv == spisok[i].tovar)
        {
            cout << "Магазин:" << spisok[i].mag << "Стоимость:" << spisok[i].stoim;
            flag++;
        }
    }
    if (flag == 0)
    {
        cout << "Данного товара нет в наличие";
    }

    return 0;
}

