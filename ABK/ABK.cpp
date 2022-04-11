#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    float a, b, K;
    cout << "Сколько килограмм?: ";
    cin >> a, "\n";
    cout << "Сколько рублей?: ";
    cin >> b, "\n";
    cout << b;
    cout << " рублей в ";
    cout << a;
    cout << " килограмм \n";
    cout << "Сколько килограмм?: ";
    cin >> K;
    K = K / a * b;
    cout << "Стоит ", K, " рублей";
    cout << K;
    cout << " рублей";
	system("pause");
	return 0;

}

