
#include "../include/RLFAController.hpp"

void RLFAController::decideAction( int step, double greedyProb, RLPlayer* p1, const RLPlayer* opp )
{
	double rnd = (double)rand()/RAND_MAX;

	int bestAct = 0;
	RLPlayer* pl1 = new RLPlayer(*p1);
	RLPlayer* pl2 = new RLPlayer(*opp);
	RLAction* act = pl1->getAct();

	if (rnd < greedyProb)
	{
		pl1->setAct(0, pl2->getPos()[0]);
		// compute new feature values
		feat->setFeats(pl1, opp);
		double bestQValue = qvalue(feat->getFeats());
		double tempQValue = 0;
		
		for (int i=1; i<RLAction::ACTION_COUNT; i++)
		{
			pl1->setAct(i, pl2->getPos()[0]);
			// compute new feature values
			feat->setFeats(pl1, opp);
			tempQValue = qvalue(feat->getFeats());
			if(bestQValue < tempQValue ){
				bestAct = i;
				bestQValue = tempQValue;
			}
		}
	}
	else{
		bestAct = rand()%RLAction::ACTION_COUNT;
	}
	p1->setAct(bestAct, pl2->getPos()[0]);//set the action to the one that gives best q value
	//updateModel(p1, opp);	
}

double RLFAController::qvalue( double* ft )
{
	double qTotal = 0;
	for(int i=0; i< NUM_OF_FEATS; i++)
		qTotal += feat->getFeatWeight()[i]*ft[i];

	return qTotal;
}
// do-step in FAController
void RLFAController::updateModel( RLPlayer* p1, const RLPlayer* opp )
{
	// compute new feature values
	feat->setFeats(p1, opp);

	// compute delta by first computing q-values
	double delta = getPrevReward()/100.0+ getDiscount()*qvalue(feat->getFeats()) - qvalue(feat->getPrevFeat());

	// update feature weights
	double* newW = new double[NUM_OF_FEATS];
	for(int i=0; i< NUM_OF_FEATS; i++)
		newW[i] = feat->getFeatWeight()[i] + getAlpha()*delta*feat->getPrevFeat()[i];

	feat->setFeatWeight(newW);
	printf("w[0]=%f, w[1]=%f, w[2]=%f, w[3]=%f\n", feat->getFeatWeight()[0], 
		feat->getFeatWeight()[1], feat->getFeatWeight()[2],feat->getFeatWeight()[3]);
	//cout<< "Player 1 isHit" << p1->getHit()<<endl;
	// set previous features
	feat->setPrevFeat(feat->getFeats());

	double wallPun = checkBorder(p1);

	int m_dist = abs(opp->getPos()[0] - p1->getPos()[0]);
	p1->getAct()->setDist(m_dist);
	double rwd = p1->updateHealth(opp->getAct());
	// set reward. add up if the player hits the walls
	setPrevReward(rwd+wallPun);	

}

double RLFAController::checkBorder( RLPlayer* p1 )
{
	double wallPun = 0;
	int* newP = p1->getPos();
	p1->setHit(-1);

	if (newP[0] > getBorder()[1])
	{
		newP[0] = getBorder()[1];
		p1->setPos(newP);
		wallPun = -10;
		p1->setHit(1);
	}
	else if (newP[0] < getBorder()[0])
	{
		newP[0] = getBorder()[0];
		p1->setPos(newP);
		wallPun = -10;
		p1->setHit(1);
	}
	return wallPun;
}

RLFAController::RLFAController() /*: RLController()*/
{
	feat = new RLFeature;
}

RLFAController::RLFAController( const RLFAController &otherCtrl )
{
	//printf("fa cc\n");
	copy(otherCtrl);
}

RLFAController & RLFAController::operator=( const RLFAController &otherCtrl )
{
	if ( &otherCtrl != this ) {
		cleanup();
		copy( otherCtrl );
	}
	return *this;
}

void RLFAController::copy( const RLFAController& otherCtrl )
{
	const RLFeature* c1 = static_cast<RLFeature*>(otherCtrl.feat);
	feat = new RLFeature(*c1);
	setReward(otherCtrl.getReward());
	setPrevReward(otherCtrl.getPrevReward());
}

void RLFAController::cleanup( void )
{
	delete feat;
	feat = NULL;
}

RLFeature* RLFAController::getFeats()
{
	return feat;
}
