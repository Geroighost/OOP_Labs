#pragma once
#include <string>
#include <iostream>

using namespace std;

class Calls
{
private:
	string caller_number;
	string caller_name;
	int incoming_or_outgoing;
	string incoming_or_outgoing_number;
private:
	string day_of_call;
	string month_of_call;
	string year_of_call;
	string hour_of_call;
	string minutes_of_call;
private:
	string hours_called;
	string minutes_called;
	string seconds_called;
private:
	float tariff_of_one_minute;
public:
	void Set_Caller_Number(string number) { caller_number = number; }
	void Set_Caller_Name(string row) { caller_name = row; }
	void Set_Incoming_Or_Outgoing(int row) { incoming_or_outgoing = row; }
	void Set_Incoming_Or_Outgoing_Number(string number) { incoming_or_outgoing_number = number; }
	string Get_Caller_Number() { return caller_number; }
	string Get_Caller_Name() { return caller_name; }
	int Get_Incoming_Or_Outgoing() { return incoming_or_outgoing; }
	string Get_Incoming_Or_Outgoing_Number() { return incoming_or_outgoing_number; }
public:
	void Set_Day_Of_Call(string number) { day_of_call = number; }
	void Set_Month_Of_Call(string number) { month_of_call = number; }
	void Set_Year_Of_Call(string number) { year_of_call = number; }
	void Set_Hour_Of_Call(string number) { hour_of_call = number; }
	void Set_Minutes_Of_Call(string number) { minutes_of_call = number; }
	string Get_Day_Of_Call() { return day_of_call; }
	string Get_Month_Of_Call() { return month_of_call; }
	string Get_Year_Of_Call() { return year_of_call; }
	string Get_Hour_Of_Call() { return hour_of_call; }
	string Get_Minutes_Of_Call() { return minutes_of_call; }
public:
	void Set_Hours_Called(string number) { hours_called = number; }
	void Set_Minutes_Called(string number) { minutes_called = number; }
	void Set_Seconds_Called(string number) { seconds_called = number; }
	string Get_Hours_Called() { return hours_called; }
	string Get_Minutes_Called() { return minutes_called; }
	string  Get_Seconds_Called() { return seconds_called; }
public:
	void Set_Tariff_Of_One_Minute(float number) { tariff_of_one_minute = number; }
	float Get_Tariff_Of_One_Minute() { return tariff_of_one_minute; }
public:
	Calls();
	~Calls();
	friend ostream& operator<< (ostream& out, const Calls& Calls);
};