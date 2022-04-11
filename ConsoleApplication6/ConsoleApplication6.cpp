// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

using namespace std;
void mtrtz(int**, int, int);
void trnspmtrtz(int**, int**, int, int);
void sum(int**, int**, int**, int, int);
void diff(int**, int**, int**, int, int);
void multiplicotion(int**, float**, int, int);
void print(int**, int, int);
void print(float**, int, int);

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    //Ввод
    int nstr, nstb;
    nstb = 0;
    cout << "Введите порядок матрицы:\n> ";
    cin >> nstr;
    nstb = nstr;
    //Создание начальной
    int** mass = new int* [nstr];
    for (int i = 0; i < nstr; i++) mass[i] = new int[nstb];
    cout << "Матрица:" << endl;
    mtrtz(mass, nstr, nstb);
    //Транспонирование
    int** masstransformer = new int* [nstr];
    for (int i = 0; i < nstr; i++) masstransformer[i] = new int[nstb];
    cout << "Матрица транспонированная:" << endl;
    trnspmtrtz(mass, masstransformer, nstr, nstb);
    //Сумма
    int** masssum = new int* [nstr];
    for (int i = 0; i < nstr; i++) masssum[i] = new int[nstb];
    sum(masssum, mass, masstransformer, nstr, nstb);
    //Создание новой матрицы
    float** multiplic = new float* [nstr];
    for (int i = 0; i < nstr; i++) multiplic[i] = new float[nstr];
    //Произведение
    multiplicotion(masssum, multiplic, nstr, nstb);
    cout << "Произведение с суммой матриц:\n";
    print(multiplic, nstr, nstb);
    //Разность и произведение
    diff(masssum, mass, masstransformer, nstr, nstb);
    multiplicotion(masssum, multiplic, nstr, nstb);
    cout << "\nПроизведение с разностью матриц:\n";
    print(multiplic, nstr, nstb);
    return 0;
}

void mtrtz(int** r, int x, int y)
{
    srand(time(NULL));
    for (int i = 0; i < x; i++) for (int t = 0; t < y; t++) r[i][t] = rand() % 101;
    print(r, x, y);
}

void trnspmtrtz(int** r, int** n, int x, int y)
{
    for (int i = 0; i < x; i++) for (int t = 0; t < x; t++) n[i][t] = r[t][i];
    print(n, x, y);
}

void sum(int** x, int** y, int** z, int p, int q)
{
    for (int i = 0; i < p; i++)
        for (int t = 0; t < q; t++) x[i][t] = y[i][t] + z[i][t];
}

void diff(int** x, int** y, int** z, int p, int q)
{
    for (int i = 0; i < p; i++)
        for (int t = 0; t < q; t++) x[i][t] = y[i][t] - z[i][t];
}

void multiplicotion(int** y, float** x, int p, int q)
{
    for (int i = 0; i < p; i++)
        for (int t = 0; t < q; t++) x[i][t] = y[i][t] * 0.5;
}

void print(int** n, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int t = 0; t < y; t++) cout << n[i][t] << " ";
        cout << endl;
        cout << endl;
    }
}

void print(float** n, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int t = 0; t < y; t++) cout << n[i][t] << " ";
        cout << endl;
        cout << endl;
    }
}
