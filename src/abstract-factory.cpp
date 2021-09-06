#include <iostream>
#include <vector>
using namespace std;


////
class OS
{
public:
	OS() {}
	virtual void write() = 0;


};
class Android :public OS
{
public:
	Android() {}
	void write()
	{
		cout << "Android\n";
	}

};
class IOS :public OS
{
public:
	IOS() {}
	void write()
	{
		cout << "IOS\n";
	}

};
////

class Cover
{
public:
	Cover() {}
	virtual void write() = 0;

};

class SamsungCover :public Cover
{
public:
	SamsungCover() {}
	void write()
	{
		cout << "Samsung Cover\n";
	}

};

class IphoneCover :public Cover
{
public:
	IphoneCover() {}
	void write()
	{
		cout << "Iphone Cover\n";
	}

};

////

class Applications
{
public:
	Applications() {}
	virtual void write() = 0;

};

class SamsungApplications :public Applications
{
public:
	SamsungApplications() {}
	void write()
	{
		cout << "Samsung Applications\n";
	}
};

class IphoneApplications :public Applications
{
public:
	IphoneApplications() {}
	void write()
	{
		cout << "Iphone Applications\n";
	}
};


////

class factory
{

public:

	factory()
	{
	}

	virtual OS* getOS() = 0;
	virtual Cover* getCover() = 0;
	virtual Applications* getApplications() = 0;

};

class SamsungFactory :public factory
{
public:

	SamsungFactory() {}

	OS* getOS()
	{
		return new Android();
	}
	Cover* getCover()
	{
		return new SamsungCover();
	}
	Applications* getApplications()
	{
		return new SamsungApplications();
	}

};

class IphoneFactory :public factory
{
public:

	IphoneFactory() {}

	OS* getOS()
	{
		return new IOS();
	}
	Cover* getCover()
	{
		return new IphoneCover();
	}
	Applications* getApplications()
	{
		return new IphoneApplications();
	}
};

////

int main()
{
	int n = 5;

	factory* f;

	OS* os;
	Cover* cover;
	Applications* apps;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			f = new SamsungFactory();
		else
			f = new IphoneFactory();

		os=f->getOS();
		cover=f->getCover();
		apps=f->getApplications();

		os->write();
		cover->write();
		apps->write();
		cout << "-----------------\n";

		delete f;
		delete os;
		delete cover;
		delete apps;

	}

}










