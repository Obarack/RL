
#include "../include/RLPlayer.hpp"


RLPlayer::RLPlayer( const RLPlayer &otherPlayer )
{
	copy(otherPlayer);
}

RLPlayer::RLPlayer()
{
	controller = new RLFAController;
	act_ = new RLAction;
	pos = new int[2];
	pos[0] = 0;
	pos[1] = 0;
}

RLPlayer::RLPlayer(RLController* rlCont, RLAction* rlAct, int* p)
{
	controller = rlCont;
	act_ = rlAct;
	pos = new int[2];
	pos[0] = p[0];
	pos[1] = p[1];
}

void RLPlayer::makeAction( RLPlayer* opp )
{
	printf("opp->pos: %d, %d\n", opp->getPos()[0], opp->getPos()[1]);
	printf("opp->act: %d, %d\n", opp->getAct()->getAction(), opp->getAct()->getType());
}

RLPlayer::~RLPlayer()
{
	cleanup();
}

void RLPlayer::copy( const RLPlayer & otherPlayer )
{
	pos = new int[2];
	const RLFAController* c1 = static_cast<RLFAController*>(otherPlayer.controller);
	controller = new RLFAController(*c1);
	//*controller = *otherPlayer.controller;
	act_ = new RLAction(*otherPlayer.act_);
	//*act_ = *otherPlayer.act_;
	pos[0] = otherPlayer.pos[0];
	pos[1] = otherPlayer.pos[1];
}

void RLPlayer::cleanup( void )
{
	delete controller;
	delete act_;
	delete pos;
}
RLPlayer & RLPlayer::operator=( const RLPlayer &otherPlayer )
{

	if ( &otherPlayer != this ) {
		cleanup();
		copy( otherPlayer );
	}
	return *this;

}