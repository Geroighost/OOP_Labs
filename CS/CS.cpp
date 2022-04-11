#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	int number_in_cin, number1 = 0, number2 = 0, number3 = 0, number_of_replaces = 0;
	ifstream ios;
	ios.open("input.txt");
	ios >> number_in_cin;
	ios.close();
	number1 = number_in_cin;
	for (int buf, nmbr, nmbr1 = 0; number1 > 5;)
	{
		nmbr1 = 0;
		number3 = number1;
		buf = 0;
		do
		{
			number2 = number3 % 10;
			if (number2 == 6)
			{
				nmbr = pow(10, buf);
				nmbr1 = nmbr1 + nmbr;
				number_of_replaces++;
			}
			number3 = number3 / 10;
			buf++;
		} while (number3 != 0);
		number1 = (number1 - nmbr1) / 2;
	}
	ofstream oos;
	oos.open("output.txt");
	oos << number_of_replaces;
	oos.close();
	system("pause");
	return 0;
}