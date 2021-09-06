
//very similar to adapter. except that we don't adapt two classes. we just interface to one.//
//in adapter, you call functions of Target, but use functions of adaptee.//
//in proxy, you call functions of real, but then wrapped functions of proxy are used.//


#include <iostream>
using namespace std;

class Subject
{
public:
	virtual void Request() = 0;


};

class Real : public Subject
{
public:
	void Request()
	{
		cout << "Request function of Real\n";
	}
};

class Proxy: public Subject
{

	Real* real;

public:

	Proxy() 
	{
		real = new Real();
	}

	void Request()
	{
		cout << "Request function of Proxy\n";
		real->Request();
	}

};

int main()
{
	Proxy* proxy = new Proxy();
	proxy->Request();

}









