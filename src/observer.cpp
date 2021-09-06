#include <iostream>
#include <vector>
using namespace std;

class Button;


class Observer
{
protected:
	Button* btn;
public:
	Observer(Button* b); //can't define it here before defining Button. btn->attach(this) won't work//

	virtual void Do() = 0;
};

////

class ObserverWindow :public Observer
{
public:
	ObserverWindow(Button* b): Observer(b) {}
	void Do()
	{
		//re-render the window//
		cout << "Window re-rendered\n";
	}

};

class ObserverOrder :public Observer
{
public:
	ObserverOrder(Button* b) : Observer(b) {}
	void Do()
	{
		//issue an order//
		cout << "Order issued\n";
	}
};

class ObserverDB :public Observer
{
public:
	ObserverDB(Button* b) : Observer(b) {}
	void Do()
	{
		//update DB//
		cout << "DB updated\n";
	}
};

////

class Button
{

	vector<Observer*> observers;

	void NotifyAll()
	{
		for (auto o : observers)
		{
			o->Do();
		}
	}


public:
	Button() {}

	void attach(Observer* o)
	{
		observers.push_back(o);
	}

	void press()
	{
		NotifyAll();
	}

	
};

////

Observer::Observer(Button* b)
{
	this->btn = b;
	btn->attach(this);
}

////

int main()
{

	

	Button* btn = new Button();
	
	Observer* o0 = new ObserverWindow(btn);
	Observer* o1 = new ObserverOrder(btn);
	Observer* o2 = new ObserverDB(btn);

	btn->press();

	return 1;
}
