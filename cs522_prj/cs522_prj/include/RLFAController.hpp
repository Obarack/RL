
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
	void decideAction(int step, double greedyProb, RLPlayer* p1, const RLPlayer* opp);	// from abstract RLController class

	double qvalue(double* ft);							// from abstract RLController class
	RLFeature* getFeats();

	void updateModel( const RLPlayer* p1, const RLPlayer* opp );

private:
	RLFeature* feat;

	void copy( const RLFAController& otherCtrl );
	void cleanup( void );

	
};

#endif