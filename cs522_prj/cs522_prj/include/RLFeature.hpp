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

	~RLFeature()
	{
		delete feats;
		delete prevFeats;
		delete featWeight;

		feats = NULL;
		prevFeats = NULL;
		featWeight = NULL;
	}
	// called by RLController
	// updates features
	void setFeats(const RLPlayer* p1, const RLPlayer* opp);	
	// get feature values
	double* getFeats() const { return feats; }
	// get/set feature weights
	double* getFeatWeight() const { return featWeight; }
	void setFeatWeight(double* val)
	{ 
		for (int i=0; i<NUM_OF_FEATS; i++)
		{
			featWeight[i] = val[i];
		}
	}
	// get/set previous features	
	double* getPrevFeat() const { return prevFeats; }
	void setPrevFeat(double* val)
	{ 
		for (int i=0; i<NUM_OF_FEATS; i++)
		{
			prevFeats[i] = val[i];
		}
	}

	void initializeFeat();

private:
	double* feats;
	double* prevFeats;
	double* featWeight;
};

#endif