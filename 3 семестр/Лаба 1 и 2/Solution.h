#pragma once
class Solution
{
private:
	float number_a;
	float number_b;
	float number_c;
public:
	void method_Discriminant(float&, float&);
	void method_coef_prop(float&, float&);
	Solution();
	Solution(float a, float b, float c);
	Solution(float b, float c): Solution(1, b, c) {}
	Solution(float c): Solution(1, 1, c) {}
	~Solution();
	int get_A() { return number_a; }
	int get_B() { return number_b; }
	int get_C() { return number_c; }
	void set_A(float number) { number_a = number; }
	void set_B(int number) { number_b = number; }
	void set_C(int number) { number_c = number; }
};

