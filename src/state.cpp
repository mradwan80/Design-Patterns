#include <iostream>
using namespace std;

enum codestate {null, implemented, tested};

class State
{
	
public:
	virtual void handle() = 0;
};


class nullState: public State
{
public:
	void handle()
	{
		cout << "implement the code\n";
	}

};

class implementedState : public State
{
public:
	void handle()
	{
		cout << "test the code\n";
	}

};

class testedState : public State
{
public:
	void handle()
	{
		cout << "deploy the code\n";
	}

};


class Code
{
	State* S;
public:
	
	Code() { S = nullptr; }
	
	void setState(codestate cs)
	{
		if (S != nullptr) delete S;
		
		switch (cs)
		{
		case null:
			S = new nullState();
			break;
		case implemented:
			S = new implementedState();
			break;
		case tested:
			S = new testedState();

		}
	}

	void request()
	{
		S->handle();
	}

};


int main()
{

	Code* code = new Code();

	code->setState(null);
	code->request();
	
	code->setState(implemented);
	code->request();
	
	code->setState(tested);
	code->request();

	return 1;
}

