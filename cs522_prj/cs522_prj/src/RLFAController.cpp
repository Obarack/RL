
#include "../include/RLFAController.hpp"

void RLFAController::decideAction( const RLPlayer* p1, const RLPlayer* opp )
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
}

double RLFAController::qvalue( double* ft )
{
	double qTotal = 0;
	for(int i=0; i< NUM_OF_FEATS; i++)
		qTotal += feat->getFeatWeight()[i]*ft[i];

	return qTotal;
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
