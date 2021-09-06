//simply, hide a complex process beside simple functions//

#include <string>
#include <iostream>
using namespace std;

class HR
{
public:

	bool checkQualifications(string candidate)
	{
		//some logic
		return true;
	}
	bool interview(string candidate)
	{
		//some logic
		return true;
	}
	
};

class TechLead
{
public:
	bool checkQualifications(string candidate)
	{
		//some logic
		return true;
	}
	bool technical_interview(string candidate)
	{
		//some logic
		return true;
	}

};

class CTO
{
public:
	void checkQualifications(string candidate) //does not reutrn. CTO does not accept/reject based on qualifications check//
	{
		//some logic
		
	}
	bool culture_interview(string candidate)
	{
		//some logic
		return true;
	}

};


class HiringFacade
{
	HR* hr;
	TechLead* tl;
	CTO* cto;

public:
	HiringFacade()
	{
		hr = new HR();
		tl = new TechLead();
		cto = new CTO();
	}

	bool EvaluateCandidate(string candidate)
	{
		if (!hr->checkQualifications(candidate))
			return false;
		if (!hr->interview(candidate))
			return false;
		
		if (!tl->checkQualifications(candidate))
			return false;
		if (!tl->technical_interview(candidate))
			return false;

		cto->checkQualifications(candidate);
		if (!cto->culture_interview(candidate))
			return false;

		return true;

	}

};


int main()
{

	HiringFacade* facade = new HiringFacade();

	string candidate = "John Doe";

	if (facade->EvaluateCandidate(candidate))
		cout << "Congratulations " << candidate << "! Your application has been accepted.\n";
	else
		cout << "Dear " << candidate << ", Unfortunately, Your application has been rejeected.\n";


}










