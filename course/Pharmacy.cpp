#include "Pharmacy.h"
#include <string>
#include <iostream>
using namespace std;

Pharmacy::Pharmacy()
{
		name = " ";
		manufacturer = " ";
		price = 0.0;
		discount = 0.0;
}

void Pharmacy::Price_with_discount()
{
	float result;
	result = price - (price * (discount * 0.01));
	cout << "Цена с учётом скидки: " << result << " руб." << endl;
}

Pharmacy::~Pharmacy()
{
}
