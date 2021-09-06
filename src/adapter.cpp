#include<vector>
#include<iostream>
using namespace std;

class TargetAbstract
{
public:
	virtual void Function1() = 0;

};

class Target:TargetAbstract
{
public:
	void Function1()
	{
		cout << "Function1 of Target\n";
	}

};


class Adaptee
{
public:
	Adaptee() {}
	void Function2()
	{
		cout << "Function2 of Adaptee\n";
	}

};


//inherit from target, include an object of adaptee//
class Adapter: public TargetAbstract //or could be just Target?//
{
	Adaptee* A;
public:
	Adapter()
	{
		A = new Adaptee();
	}


	void Function1()
	{
		A->Function2();
	}
};


int main()
{

	Adapter* adp = new Adapter();
	adp->Function1();
}

