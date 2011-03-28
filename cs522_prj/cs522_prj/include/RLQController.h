#ifndef _RLQCONTROLLER_HPP_
#define _RLQCONTROLLER_HPP_

#include "RLController.hpp"
#include "RLAction.hpp"
#include "RLPlayer.hpp"

class RLQController : public RLController
{

public:
	friend class RLPlayer;

	RLQController();
	~RLQController();
	RLQController(const RLQController &otherCtrl);
	RLQController & operator= (const RLQController &otherCtrl);

	// called by RLPlayer
	// calls RLFeature's setFeats fnc
	void decideAction(int step, double greedyProb, RLPlayer* p1, const RLPlayer* opp);	// from abstract RLController class
	void updateModel( RLPlayer* p1, const RLPlayer* opp );	// from abstract RLController class
	double qvalue(double* ft);								// from abstract RLController class

	double getQValues(int dist, int myAct, int oppAct) const { return qValues[dist][myAct][oppAct]; }

private:
	void copy( const RLQController& otherCtrl );
	void cleanup( void );

	double*** qValues;
};

#endif