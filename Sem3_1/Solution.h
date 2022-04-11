#pragma once
#include <fstream>
#include <iostream>

using namespace std;

class Abstract
{
public:
	virtual void Just_another_method_with_override() = 0;
};

class Solution : public Abstract
{
protected:
	float number_a;
	float number_b;
	float number_c;
public:
	friend ostream& operator<< (ostream& out, const Solution& N1)
	{
		out << "a = " << N1.number_a << ", " << "b = " << N1.number_b << ", " << "c = " << N1.number_c;
		return out;
	}
	void method_Discriminant(float&, float&);
	void method_coef_prop(float&, float&);
	Solution();
	Solution(float a, float b, float c);
	Solution(float b, float c) : Solution(1, b, c) {}
	Solution(float c) : Solution(1, 1, c) {}
	~Solution();
	void Just_a_method();
	void Just_another_method_with_override() override;
	float get_A() { return number_a; }
	float get_B() { return number_b; }
	float get_C() { return number_c; }
	void set_A(float number) { number_a = number; }
	void set_B(float number) { number_b = number; }
	void set_C(float number) { number_c = number; }
};

/*class Cubic_Solution : public Solution, public Abstract
{
private:
	float* x = 0;
public:
	float cubic_Solution_Method(float *x);
	Cubic_Solution();
	~Cubic_Solution()
	{
		cout << "2cl destroyed." << endl;
	}
	Cubic_Solution(float a, float b, float c);
	Cubic_Solution(float b, float c) : Cubic_Solution(1, b, c) {};
	Cubic_Solution(float c) : Cubic_Solution(1, 1, c) {};
	void Just_another_method_with_override() override;
};
*/
class Third_Class
{
public:
	Third_Class()
	{

	}
	~Third_Class()
	{
		cout << "3cl destroyed." << endl;
	}
};

class Fourty_Class
{
private:
	int nomber;
	weak_ptr<Fourty_Class> nimber;
public:
	Fourty_Class()
	{
		nomber = 0;
	}
	Fourty_Class(int num) : nomber(num)
	{
		cout << nomber << " создан." << endl;
	}
	~Fourty_Class()
	{
		cout << "4cl destroyed." << endl;
	}
	friend bool Up(shared_ptr<Fourty_Class>& tc1, shared_ptr<Fourty_Class>& tc2)
	{
		if (!tc1 || !tc2) return false;
		tc1->nimber = tc2;
		tc2->nimber = tc1;
		cout << tc1->nomber << " теперь " << tc2->nomber << endl;
		return true;
	}
};

class Fifth_Class
{
public:
	Fifth_Class()
	{

	}
	~Fifth_Class()
	{
		cout << "5cl destroyed." << endl;
	}
	void Just_a_method();
};