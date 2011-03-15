
#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_


#include <iostream>

using namespace std;

class RLController
{
public:
	friend class RLPlayer;

	RLController()
	{
		discount = 0.9;
		alphaFixed = false;
		alpha = 0.1;
	};

	virtual void decideAction(const RLPlayer* p1, const RLPlayer* opp)=0;
	virtual double qvalue()=0;

private:
	string name;

	double discount;
	bool alphaFixed;
	double alpha;

};

#endif