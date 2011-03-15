
#ifndef _RLPLAYER_HPP_
#define _RLPLAYER_HPP_

#include "RLController.hpp"
#include "RLFAController.hpp"
#include "RLAction.hpp"

class RLPlayer
{

public:

	friend class RLController;
	friend class RLAction;

	RLPlayer();
	RLPlayer(RLController* rlCont, RLAction* rlAct, int* p);
	RLPlayer(const RLPlayer &otherPlayer);
	RLPlayer & RLPlayer::operator=( const RLPlayer &otherPlayer );

	// called by RLSimulator, 
	// calls RLController
	void makeAction(RLPlayer* opp);
	int* getPos(){ return pos; };
	void setPos(int* p) { 
		pos[0]=p[0];
		pos[1]=p[1];
	}

	~RLPlayer();

	RLAction* getAct() const { return act_; }
	void setAct(int act, int ty, int dam) { 
		act_->setAction(act);
		act_->setType(ty); 
		act_->setDamage(dam);	
	}

private:
	RLController* controller;
	RLAction* act_;

	int* pos;
	void copy( const RLPlayer & otherPlayer );
	void cleanup( void );

};

#endif