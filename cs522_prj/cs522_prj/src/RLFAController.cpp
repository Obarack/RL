
#include "../include/RLFAController.hpp"

void RLFAController::decideAction( const RLPlayer* p1, const RLPlayer* opp )
{

}

double RLFAController::qvalue()
{
	return 0;
}

RLFAController::RLFAController()
{

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
	reward = otherCtrl.reward;
	prevReward = otherCtrl.prevReward;
}

void RLFAController::cleanup( void )
{
	delete feat;
	feat = NULL;
}
