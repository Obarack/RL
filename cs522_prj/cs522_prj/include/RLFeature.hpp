
#ifndef _RLFEATURES_HPP_
#define _RLFEATURES_HPP_

#include "RLPlayer.hpp"

#define NUM_OF_FEATS 5

class RLFeature
{
private:
	double feats[NUM_OF_FEATS];
	double prevFeats[NUM_OF_FEATS];
	double featWeight[NUM_OF_FEATS];

public:
	// called by RLController
	// updates features
	void setFeats(const RLPlayer*& p1, const RLPlayer*& opp);	
};

#endif