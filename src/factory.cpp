#include <vector>
#include <iostream>
using namespace std;

class pet
{
	

public:
	pet() {}

	virtual void makeSound() = 0;
	
};

class dog : public pet
{
	
public:
	
	dog() {}
	
	void makeSound()
	{
		cout << "haw haw\n";
	}
};

class cat : public pet
{
	
public:
	
	cat() {}

	void makeSound()
	{
		cout << "meaw\n";
	}
};

class petfactory
{
public:

	petfactory()
	{}

	dog* getDog()
	{
		return new dog();
	}

	cat* getCat()
	{
		return new cat();
	}

	//can also make one function, and a parameter decides. but not sure if mandatory, or this way is also possible//


};

int main()
{

	petfactory* f = new petfactory;

	int n = 10;

	vector<pet*> animals(10);

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			animals[i] = f->getCat();
		else
			animals[i] = f->getDog();
	}

	for (int i = 0; i < n; i++)
		animals[i]->makeSound();



	return 1;

}








