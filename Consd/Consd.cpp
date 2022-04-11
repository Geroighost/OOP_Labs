#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n, a;
	ifstream ios;
	ios.open("input.txt");
	ios >> n;
	ios.close();
	int Sum = 0;
	if (n < 0) a = 0;
	else if (n > 0) a = 1;
	if (a = 1)
	{
		for (int i = 0; i <= n; i++)
		{
			Sum = Sum + i;
		}
	}
	if (a = 0)
	{
		for (int i = 0; i >= n; i--)
		{
			Sum = Sum + i;
		}
	}
	ofstream oos;
	oos.open("output.txt");
	oos << Sum;
	oos.close();
	system("pause");
	return 0;
}