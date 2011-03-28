
#ifndef _CONTROLLER_HPP_
#define _CONTROLLER_HPP_


#include <iostream>
#include <vector>

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
		reward = 0;
		prevReward = 0;
		// borders of the playground on x-axis
		border = new int[2];
		border[0] = 0;
		border[1] = 10;
	};

	virtual void decideAction(int step, double greedyProb, RLPlayer* p1, const RLPlayer* opp)=0;
	virtual double qvalue(double* ft)=0;
	virtual void updateModel( RLPlayer* p1, const RLPlayer* opp )=0;

	// get/set for the member variables
	double getDiscount() const { return discount; }
	void setDiscount(double val) { discount = val; }
	bool getAlphaFixed() const { return alphaFixed; }
	void setAlphaFixed(bool val) { alphaFixed = val; }
	double getAlpha() const { return alpha; }
	void setAlpha(double val) { alpha = val; }
	double getReward() const { return reward; }
	void setReward(double val) { reward = val; }
	double getPrevReward() const { return prevReward; }
	void setPrevReward(double val) { prevReward = val; allReward.push_back(prevReward); }
	vector<double> getAllReward() const { return allReward; }
	void setAllReward(vector<double> val) { allReward = val; }
	int* getBorder() const { return border; }

private:
	string name;

	double discount;

	bool alphaFixed;
	double alpha;
	double reward;
	double prevReward;
	vector<double> allReward;
	int* border;
	
};

#endif