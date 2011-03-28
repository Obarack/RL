
#ifndef _RLFACONTROLLER_HPP_
#define _RLFACONTROLLER_HPP_

#include "RLController.hpp"
#include "RLFeature.hpp"

class RLFAController : public RLController
{

public:
	friend class RLFeature;

	RLFAController();
	RLFAController(const RLFAController &otherCtrl);
	RLFAController & operator= (const RLFAController &otherCtrl);

	// called by RLPlayer
	// calls RLFeature's setFeats fnc
	void decideAction(int step, double greedyProb, RLPlayer* p1, const RLPlayer* opp);	// from abstract RLController class

	double qvalue(double* ft);							// from abstract RLController class
	RLFeature* getFeats();


	void updateModel( RLPlayer* p1, const RLPlayer* opp );

	double checkBorder( RLPlayer* p1 ) ;

private:
	RLFeature* feat;

	void copy( const RLFAController& otherCtrl );
	void cleanup( void );

	
};

#endif