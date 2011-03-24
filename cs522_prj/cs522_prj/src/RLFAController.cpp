
#include "../include/RLFAController.hpp"

void RLFAController::decideAction( int step, double greedyProb, RLPlayer* p1, const RLPlayer* opp )
{
	double rnd = rand()/RAND_MAX;

	int bestAct = 0;
	RLAction* act = p1->getAct();

	if (rnd < greedyProb)
	{
		p1->setAct(0,act->getDist());
		// compute new feature vals
		feat->setFeats(p1, opp);
		double bestQValue = qvalue(feat->getFeats());
		double tempQValue = 0;
		
		for (int i=1; i<RLAction::ACTION_COUNT; i++)
		{
			p1->setAct(i,act->getDist());
			// compute new feature vals
			feat->setFeats(p1, opp);
			tempQValue = qvalue(feat->getFeats());
			if(bestQValue < tempQValue ){
				bestAct = i;
				bestQValue = tempQValue;
			}
		}
	}else{

		bestAct = rand()%RLAction::ACTION_COUNT;
	}
	p1->setAct(bestAct, act->getDist());//set the action to the one that gives best q value
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
void RLFAController::updateModel( const RLPlayer* p1, const RLPlayer* opp ) 
{

	// compute new feature vals
	feat->setFeats(p1, opp);

	// compute delta by first computing q-vals
	double delta = getPrevReward()+ getDiscount()*qvalue(feat->getFeats()) - qvalue(feat->getPrevFeat());

	// update feature weights
	double* newW = new double[NUM_OF_FEATS];
	for(int i=0; i< NUM_OF_FEATS; i++)
		newW[i] = feat->getFeatWeight()[i] + getAlpha()*delta*feat->getPrevFeat()[i];

	feat->setFeatWeight(newW);
	printf("w[0]=%f, w[1]=%f, w[2]=%f\n", feat->getFeatWeight()[0], 
		feat->getFeatWeight()[1], feat->getFeatWeight()[2]);
	// set previous features
	feat->setPrevFeat(feat->getFeats());

	// set reward
	setPrevReward(p1->getAct()->getValue(p1->getAct()->getAction(),p1->getAct()->getDist()));
}

RLFAController::RLFAController() /*: RLController()*/
{
	feat = new RLFeature;
}

RLFAController::RLFAController( const RLFAController &otherCtrl )
{
	printf("fa cc\n");
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
