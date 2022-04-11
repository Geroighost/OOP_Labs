#include <iostream>

using namespace std;

class SomeCS
{
public:
	int x;
	int y;
	int get_x() { return x; }
	int get_y() { return y; }
};

class CSimpleTr
{
public:
	SomeCS* that;
	SomeCS* previous;
public:
	CSimpleTr() : previous(NULL), that(new SomeCS) {};
	CSimpleTr(const CSimpleTr& _st) : that(new SomeCS(*(_st.that))), previous(NULL) {};
	~CSimpleTr() { delete that; delete previous; }
	CSimpleTr& operator=(const CSimpleTr& _st)
	{
		if (this != &_st)
		{
			delete that;
			that = new SomeCS(*(_st.that));
		}
		return *this;
	}
	void BeginTrans()
	{
		delete previous;
		previous = that;
		that = new SomeCS(*previous);
	}
	void Commit()
	{
		delete previous;
		previous = NULL;
	}
	void Rollback()
	{
		if (previous != NULL)
		{
			delete that;
			that = previous;
			previous = NULL;
		}
	}
	SomeCS* operator->() { return that; }
};

int main()
{
	CSimpleTr Clss;
	Clss->x = 6;
	Clss->y = 8;
	cout << "x = " << Clss->get_x() << " y = " << Clss->get_y() << endl;
	Clss.BeginTrans();
	Clss->x = 7;
	Clss->y = 11;
	cout << "x = " << Clss->get_x() << " y = " << Clss->get_y() << endl;
	Clss.Rollback();
	cout << "x = " << Clss->get_x() << " y = " << Clss->get_y() << endl;
	Clss.BeginTrans();
	Clss->x = 7;
	Clss->y = 11;
	Clss.Commit();
	cout << "x = " << Clss->get_x() << " y = " << Clss->get_y() << endl;
	return 0;
}