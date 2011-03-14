
#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_

class RLController
{
private:
	String name;
	Environment* env;

	double discount = 0.9;
	bool alphaFixed = false;
	double alpha = 0.1;


public:

	virtual void decideAction() = 0;
	virtual double qvalue() = 0;

};

#endif