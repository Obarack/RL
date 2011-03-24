
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
	RLPlayer(int* p, double h);
	RLPlayer(const RLPlayer &otherPlayer);
	RLPlayer & RLPlayer::operator=( const RLPlayer &otherPlayer );

	// called by RLSimulator, 
	// calls RLController
	void makeAction(RLPlayer* opp);

	~RLPlayer();

	RLAction* getAct() const { return act_; }
	void setAct(int act, const int dist) { 
		act_->setAction(act);
		act_->setDist(dist);
	}
	// get-set pos
	int* getPos() const { return pos; };
	void setPos(int* p) { 
		pos[0]=p[0];
		pos[1]=p[1];
	}
	// get-set health
	double getHealth() const { return health; }
	void setHealth(double val) { health = val; }
	// get controller
	RLController* getController(){ return controller; };

private:
	RLController* controller;
	RLAction* act_;

	int* pos;
	double health;


	void copy( const RLPlayer & otherPlayer );
	void cleanup( void );

};

#endif