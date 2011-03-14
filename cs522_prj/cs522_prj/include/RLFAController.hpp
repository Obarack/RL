
#ifndef _RLFACONTROLLER_HPP_
#define _RLFACONTROLLER_HPP_

#include "RLFeature.hpp"

class RLFAController::RLController
{
private:
	RLFeature* feat;
	double reward;
	double prevReward;

public:
	
	// called by RLPlayer
	// calls RLFeature's setFeats fnc
	virtual void decideAction(const RLPlayer*& p1, const RLPlayer*& opp);	// from abstract RLController class

	virtual double qvalue();							// from abstract RLController class

};

#endif