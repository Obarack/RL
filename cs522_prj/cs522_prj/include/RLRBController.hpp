#ifndef _RLRBCONTROLLER_HPP_
#define _RLRBCONTROLLER_HPP_

#include "RLController.hpp"
#include "RLFeature.hpp"

class RLRBController : public RLController
{

public:
	friend class RLFeature;

	RLRBController();
	RLRBController(const RLRBController &otherCtrl);
	RLRBController & operator= (const RLRBController &otherCtrl);

	// called by RLPlayer
	// calls RLFeature's setFeats fnc
	void decideAction(int step, double greedyProb, RLPlayer* p1, const RLPlayer* opp);	// from abstract RLController class

	double qvalue(double* ft);							// from abstract RLController class
	RLFeature* getFeats();

	void updateModel( RLPlayer* p1, const RLPlayer* opp );

private:
	RLFeature* feat;

	void copy( const RLRBController& otherCtrl );
	void cleanup( void );


};

#endif