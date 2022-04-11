#include "Calls.h"
#include <string>
#include <iostream>
using namespace std;

Calls::Calls()
{
	caller_number = " ";
	caller_name = " ";
	incoming_or_outgoing = 0;
	incoming_or_outgoing_number = " ";
	day_of_call = " ";
	month_of_call = " ";
	year_of_call = " ";
	hour_of_call = " ";
	minutes_of_call = " ";
	hours_called = " ";
	minutes_called = " ";
	seconds_called = " ";
	tariff_of_one_minute = 0.0;
}
Calls::~Calls()
{
}

ostream& operator<< (ostream& out, const Calls& Calls)
{
	out << "Номер абонента: " << Calls.caller_number << "\n   Имя абонента: " << Calls.caller_name << "\n   Входящий или исходящий номер: " << Calls.incoming_or_outgoing_number << "\n   Тип звонка: ";
	if (Calls.incoming_or_outgoing == 1)
		out << "Входящий";
	else if (Calls.incoming_or_outgoing == 2)
		out << "Исходящий";
	out << "\n   Дата звонка: " << Calls.day_of_call << "." << Calls.month_of_call << "." << Calls.year_of_call << " " << Calls.hour_of_call << ":" << Calls.minutes_of_call << "\n   Время звонка: " << Calls.hours_called << ":" << Calls.minutes_called << ":" << Calls.seconds_called << "\n   Тариф абонента на одну минуту звонка: " << Calls.tariff_of_one_minute << endl;
	return out;
}