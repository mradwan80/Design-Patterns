//the main difference from abstract: abstract has factories, each is used to create objects of specific categories. builder, builds one whole object at a time (with attributes of specific category).//

//I don't use a director, and I don't think I need to.//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


////
class OS
{
public:
	string type;

	OS() {}
	OS(string t) { type = t; }

	void write()
	{
		cout << type << "\n";
	}


};

class Cover
{
public:
	string type;
	
	Cover() {}
	Cover(string t) { type = t; }
	
	void write()
	{
		cout << type << "\n";
	}

};

class Applications
{
public:
	string type;

	Applications() {}
	Applications(string t) { type = t; }
	
	void write()
	{
		cout << type << "\n";
	}

};

////


class Phone
{
	
public:

	//Do they have to be public ?!//
	OS* os;
	Cover* cover;
	Applications* apps;

	Phone() {}

	
	void WriteSpecs()
	{
		os->write();
		cover->write();
		apps->write();
		cout << "-----------------------\n";
	}

};

////

class builder
{

public:

	builder()
	{
	}

	virtual Phone* CreatePhone() = 0;
};

class SamsungBuilder :public builder
{
public:

	SamsungBuilder() {}

	Phone* CreatePhone()
	{
		Phone* phone = new Phone();
		phone->os = new OS("Android");
		phone->cover = new Cover("Samsung Cover");
		phone->apps = new Applications("Samsung Applications");
		
		return phone;

	}

};

class IphoneBuilder :public builder
{
public:
	
	IphoneBuilder() {}

	Phone* CreatePhone()
	{
		Phone* phone = new Phone();

		phone->os = new OS("IOS");
		phone->cover = new Cover("Iphone Cover");
		phone->apps = new Applications("Iphone Applications");

		return phone;
	}

};

////

int main()
{
	int n = 5;
	vector<Phone*> phones(n);


	builder* b;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			b = new SamsungBuilder();
		else
			b = new IphoneBuilder();


		phones[i] = b->CreatePhone();

		delete b;

	}

	for (int i = 0; i < n; i++)
		phones[i]->WriteSpecs();

	

}










