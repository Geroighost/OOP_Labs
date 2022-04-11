#pragma once

class ClassB1
{
private:
	int value_B1;
public:
	ClassB1();
	int Get_value_B1() { return value_B1; }
};

class ClassB2
{
private:
	int value_B2;
public:
	ClassB2();
	int Get_value_B2() { return value_B2; }
};

class ClassD1 : public ClassB1
{
private:
	float value_D1;
public:
	ClassD1();
	float Get_value_D1() { return value_D1; }
};

class ClassD2 : private ClassB2
{
private:
	float value_D2;
public:
	ClassD2();
	float Get_value_D2() { return value_D2; }
};

class ClassD3 : private ClassD1, public ClassD2
{
private:
	double value_D3;
public:
	ClassD3();
	double Get_value_D3() { return value_D3; }
};