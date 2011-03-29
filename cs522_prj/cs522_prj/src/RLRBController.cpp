
#include "../include/RLRBController.hpp"

int RLRBController::decideAction( int step, double greedyProb, RLPlayer* p1, const RLPlayer* opp )
{
	//int bestAct = rand()%RLAction::ACTION_COUNT;
	//p1->setAct(1, opp->getPos()[0]);
	double rnd = (double) rand()/RAND_MAX;
	int dis = p1->getAct()->getDist();
	int bestAct = -1;

	//cout << "RB rand " << rnd<< endl;
	if(dis == RLAction::CLOSE) 
	{
		if(rnd < 0.8)
			bestAct = RLAction::U_CUT;
		else if (rnd < 1 )
			bestAct = RLAction::BLOCK;
	}
	else if(dis == RLAction::NEAR)
	{
		if(rnd < 0.8)
			bestAct = RLAction::L_KICK;
		else if (rnd < 1 )
			bestAct = RLAction::WALK_F;
	}
	else
	{
		if(rnd < 0.7)
			bestAct = RLAction::RUN_F;
		else
			bestAct = RLAction::WALK_F;
	}
	return bestAct;
	//double rnd = (double) rand()/RAND_MAX;
	//int dis = p1->getAct()->getDist();

	//cout << "RB rand " << rnd<< endl;
	//if(dis == RLAction::CLOSE)
	//	if(rnd < 0.5)
	//		p1->setAct(RLAction::U_CUT, opp->getPos()[0]);
	//	else if (rnd < 0.8 )
	//		p1->setAct(RLAction::L_KICK, opp->getPos()[0]);
	//	else if (rnd < 0.9)
	//		p1->setAct(RLAction::WALK_B, opp->getPos()[0]);
	//	else
	//		p1->setAct(RLAction::BLOCK, opp->getPos()[0]);

	//else if(dis == RLAction::NEAR)
	//	if(rnd < 0.5)
	//		p1->setAct(RLAction::L_KICK, opp->getPos()[0]);
	//	else if (rnd < 0.8 )
	//		p1->setAct(RLAction::BLOCK, opp->getPos()[0]);
	//	else
	//		p1->setAct(RLAction::WALK_F, opp->getPos()[0]);
	//else
	//	if(rnd < 0.7)
	//		p1->setAct(RLAction::RUN_F, opp->getPos()[0]);
	//	else
	//		p1->setAct(RLAction::WALK_F, opp->getPos()[0]);
}

double RLRBController::qvalue( double* ft )
{
	double qTotal = 0;
	for(int i=0; i< NUM_OF_FEATS; i++)
		qTotal += feat->getFeatWeight()[i]*ft[i];

	return qTotal;
}
// do-step in FAController
void RLRBController::updateModel( RLPlayer*& p1, RLPlayer*& opp, int bestAct )
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
	delete c1; c1 = NULL;
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
