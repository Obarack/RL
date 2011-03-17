
#include "../include/RLFAController.hpp"

void RLFeature::setFeats( const RLPlayer* p1, const RLPlayer* opp )
{
	// health
	feats[0] = p1->getHealth() - opp->getHealth();
	// distance in x-direction
	feats[1] = p1->getPos()[0] - opp->getPos()[0];
	// distance in y-direction
	feats[2] = p1->getPos()[1] - opp->getPos()[1];
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

