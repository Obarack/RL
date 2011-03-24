
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
	health = 100;
}

RLPlayer::RLPlayer(int* p, double h)
{
	controller = new RLFAController;
	act_ = new RLAction;
	pos = new int[2];
	pos[0] = p[0];
	pos[1] = p[1];
	health = h;
}

void RLPlayer::makeAction( RLPlayer* opp )
{
	printf("this->pos: %d, %d, %f\n", this->getPos()[0], this->getPos()[1], this->getHealth());
	printf("opp->pos: %d, %d, %f\n", opp->getPos()[0], opp->getPos()[1], opp->getHealth());
	printf("opp->act: %d, %d\n", opp->getAct()->getAction(), opp->getAct()->getDist());
	
	controller->decideAction(1, 0.8, this, opp);
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
	act_ = new RLAction(*otherPlayer.act_);

	pos[0] = otherPlayer.pos[0];
	pos[1] = otherPlayer.pos[1];
	health = otherPlayer.health;
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

