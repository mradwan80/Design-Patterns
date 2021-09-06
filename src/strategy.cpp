#include <iostream>
using namespace std;



class strategy
{
public:
	virtual void Act() = 0;
};

class DivideAndConquer: public strategy
{
public:
	void Act()
	{
		cout << "Divide and conquer\n";
	}
};

class DynamicProgramming : public strategy
{
public:
	void Act()
	{
		cout << "Dynamic programming\n";
	}
};

class Greedy : public strategy
{
public:
	void Act()
	{
		cout << "Greedy\n";
	}

};

class cls
{
public:
	cls(){}

	cls(int i) 
	{
		switch (i)
		{
		case 0: 
			s = new DivideAndConquer();
			break;
		case 1:
			s = new DynamicProgramming();
			break;
		case 2:
			s = new Greedy();
		};
	};

	strategy* s;

	void setStrategy(int i)
	{
		if (s != nullptr) delete s;

		switch (i)
		{
		case 0:
			s = new DivideAndConquer();
			break;
		case 1:
			s = new DynamicProgramming();
			break;
		case 2:
			s = new Greedy();
		};
	}

	void process()
	{
		s->Act();
	}

};

int main()
{

	cls* obj0 = new cls(0);
	cls* obj1 = new cls(1);
	cls* obj2 = new cls(2);
	cls* obj3 = new cls();

	obj3->setStrategy(0);


	obj0->process();
	obj1->process();
	obj2->process();


	return 1;
}



