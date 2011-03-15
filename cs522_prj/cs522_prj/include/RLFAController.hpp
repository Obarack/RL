
#ifndef _RLFACONTROLLER_HPP_
#define _RLFACONTROLLER_HPP_

#include "RLController.hpp"
#include "RLFeature.hpp"

class RLFAController : public RLController
{

public:
	RLFAController();
	RLFAController(const RLFAController &otherCtrl);
	RLFAController & operator= (const RLFAController &otherCtrl);

	// called by RLPlayer
	// calls RLFeature's setFeats fnc
	void decideAction(const RLPlayer* p1, const RLPlayer* opp);	// from abstract RLController class
	double qvalue();							// from abstract RLController class

private:
	RLFeature* feat;
	double reward;
	double prevReward;
	void copy( const RLFAController& otherCtrl );
	void cleanup( void );

};

#endif