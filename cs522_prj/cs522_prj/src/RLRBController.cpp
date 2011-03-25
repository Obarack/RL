
#include "../include/RLRBController.hpp"

void RLRBController::decideAction( int step, double greedyProb, RLPlayer* p1, const RLPlayer* opp )
{
	double rnd = (double) rand()/RAND_MAX;
	int dis = p1->getAct()->getDist();

	cout << "RB rand " << rnd<< endl;
	if(dis == RLAction::CLOSE)
		if(rnd < 0.5)
			p1->setAct(RLAction::U_CUT, opp->getPos()[0]);
		else if (rnd < 0.8 )
			p1->setAct(RLAction::L_KICK, opp->getPos()[0]);
		else if (rnd < 0.9)
			p1->setAct(RLAction::WALK_B, opp->getPos()[0]);
		else
			p1->setAct(RLAction::BLOCK, opp->getPos()[0]);

	else if(dis == RLAction::NEAR)
		if(rnd < 0.5)
			p1->setAct(RLAction::L_KICK, opp->getPos()[0]);
		else if (rnd < 0.8 )
			p1->setAct(RLAction::BLOCK, opp->getPos()[0]);
		else
			p1->setAct(RLAction::WALK_F, opp->getPos()[0]);
	else
		if(rnd < 0.7)
			p1->setAct(RLAction::RUN_F, opp->getPos()[0]);
		else
			p1->setAct(RLAction::WALK_F, opp->getPos()[0]);
}

double RLRBController::qvalue( double* ft )
{
	double qTotal = 0;
	for(int i=0; i< NUM_OF_FEATS; i++)
		qTotal += feat->getFeatWeight()[i]*ft[i];

	return qTotal;
}
// do-step in FAController
void RLRBController::updateModel( RLPlayer* p1, const RLPlayer* opp )
{
	int m_dist = abs(opp->getPos()[0] - p1->getPos()[0]);
	p1->getAct()->setDist(m_dist);
	double rwd = p1->updateHealth(opp->getAct());
}

RLRBController::RLRBController() /*: RLController()*/
{
	feat = new RLFeature;
}

RLRBController::RLRBController( const RLRBController &otherCtrl )
{
	printf("rb cc\n");
	copy(otherCtrl);
}

RLRBController & RLRBController::operator=( const RLRBController &otherCtrl )
{
	if ( &otherCtrl != this ) {
		cleanup();
		copy( otherCtrl );
	}
	return *this;

}

void RLRBController::copy( const RLRBController& otherCtrl )
{
	const RLFeature* c1 = static_cast<RLFeature*>(otherCtrl.feat);
	feat = new RLFeature(*c1);
	setReward(otherCtrl.getReward());
	setPrevReward(otherCtrl.getPrevReward());
}

void RLRBController::cleanup( void )
{
	delete feat;
	feat = NULL;
}

RLFeature* RLRBController::getFeats()
{
	return feat;
}
