#include <iostream>
#include "Classes.h"

using namespace std;

int main()
{
    ClassB1 Class_B1;
    cout << "B1:\n" <<  Class_B1.Get_value_B1() << endl;
    cout << endl;
    ClassB2 Class_B2;
    cout << "B2:\n" << Class_B2.Get_value_B2() << endl;
    cout << endl;
    ClassD1 Class_D1;
    cout << "D1:\n";
    cout << Class_D1.Get_value_B1() << " " << Class_D1.Get_value_D1() << endl;
    cout << endl;
    ClassD2 Class_D2;
    cout << "D2:\n";
    cout << Class_D2.Get_value_D2() << endl;
    cout << endl;
    ClassD3 Class_D3;
    cout << "D3:\n";
    cout << Class_D3.Get_value_D2() << " " << Class_D3.Get_value_D3() << endl;
    cout << "END." << endl;
    system("pause");
    return 0;
}
