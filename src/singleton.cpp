#include <iostream>
using namespace std;

class One
{
	static One *Instance;

	int value;

	One() {}

public:
	

	static One* getInstance();

	void SetValue(int val)
	{
		value = val;
	}

	void writeVaue()
	{
		cout << "value: " << value << "\n";
	}

};

One* One::Instance = nullptr;

One* One::getInstance()
{
	if (One::Instance == nullptr)
		Instance = new One();
	return Instance;
}

int main()
{

	One* o0 = One::getInstance();
	o0->SetValue(7);

	o0->writeVaue();

	One* o1 = One::getInstance();
	o1->SetValue(4);

	o0->writeVaue();	//value changes, even though o1 issued SetValue(4), because it is a singleton//

}


