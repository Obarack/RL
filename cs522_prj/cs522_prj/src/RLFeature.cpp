
#include "../include/RLFAController.hpp"

void RLFeature::setFeats( const RLPlayer* p1, const RLPlayer* opp )
{
	//WARNING : number of features is set in RLFeature.hpp
	double healthDiffP1 = (p1->getPrevHealth()-p1->getHealth());
	double healthDiffOp = (opp->getPrevHealth()-opp->getHealth());
	// health
	feats[0] = (healthDiffP1 - healthDiffOp)/2; 
	//WARNING : FEature normalization!! is it meaningful???
	// distance in x-direction
	feats[1] = (p1->getPos()[0] - opp->getPos()[0])/2;
	// distance in y-direction
	//feats[2] = p1->getPos()[1] - opp->getPos()[1];
	// damage
	feats[2] = p1->getAct()->getValue(p1->getAct()->getAction(), p1->getAct()->getDist())/10;
	feats[5] = opp->getAct()->getValue(opp->getAct()->getAction(), opp->getAct()->getDist())/10;
	//WARNING : FEature normalization!! is it meaningful???
	// hitting the wall
	feats[3] = p1->getHit();
	feats[4] = p1->getAct()->getDist();
}

RLFeature::RLFeature(const RLPlayer* p1, const RLPlayer* opp)
{
	initializeFeat();
	setFeats(p1, opp);
}

RLFeature::RLFeature()
{
	feats = new double[NUM_OF_FEATS];
	prevFeats = new double[NUM_OF_FEATS];
	featWeight = new double[NUM_OF_FEATS];
	initializeFeat();
}

RLFeature::RLFeature( const RLFeature &otherFeat )
{
	feats = new double[NUM_OF_FEATS];
	prevFeats = new double[NUM_OF_FEATS];
	featWeight = new double[NUM_OF_FEATS];

	for(int i=0; i<NUM_OF_FEATS; i++)
	{
		feats[i] = otherFeat.feats[i];
		prevFeats[i] = otherFeat.prevFeats[i];
		featWeight[i] = otherFeat.featWeight[i];
	}
}

void RLFeature::initializeFeat()
{
	for( int i=0; i<NUM_OF_FEATS; i++ ){
		prevFeats[i] = 0;
		featWeight[i] = 1;
	}
}

