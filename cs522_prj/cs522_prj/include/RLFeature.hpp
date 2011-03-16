
#ifndef _RLFEATURE_HPP_
#define _RLFEATURE_HPP_

#include "RLPlayer.hpp"

#define NUM_OF_FEATS 3

class RLFeature
{
public:

	friend class RLPlayer;

	RLFeature();
	RLFeature(const RLFeature &otherFeat);	
	RLFeature(const RLPlayer* p1, const RLPlayer* opp);
	// called by RLController
	// updates features
	void setFeats(const RLPlayer* p1, const RLPlayer* opp);	

private:
	double feats[NUM_OF_FEATS];
	double prevFeats[NUM_OF_FEATS];
	double featWeight[NUM_OF_FEATS];

};

#endif