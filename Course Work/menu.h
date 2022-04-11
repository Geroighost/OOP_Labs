#pragma once
#include "Pharmacy.h"
#include <vector>

class Menu
{
public:
	void record_in_file(vector<Pills> Pill, vector<Devices> Device);
	void read_elements_from_file(vector<Pills>& Pill, vector<Devices>& Device);
	Menu();
	void output_data_on_monitor(vector<Pills> Pill, vector<Devices> Device);
	void calculation_discount(vector<Pills> Pill, vector<Devices> Device);
	void add(vector<Pills>& Pill, vector<Devices>& Device);
	void deleting(vector<Pills>& Pill, vector<Devices>& Device);
	void edit(vector<Pills>& Pill, vector<Devices>& Device);
	void search(vector<Pills>& Pill, vector<Devices>& Device);
	void big_menu(vector<Pills> Pill, vector<Devices> Device);
};

