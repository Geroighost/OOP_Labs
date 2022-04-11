#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a, b, c, d, Sum1, Sum2;

    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    Sum1 = a + c;
    Sum2 = b + d;
    for (; Sum2 > 60;)
    {
        Sum1++;
        Sum2 = Sum2 - 60;
    }
    cout << Sum1 << ":" << Sum2 << endl;
    system("pause");
    return 0;
}