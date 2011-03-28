
#ifndef _RLPLAYER_HPP_
#define _RLPLAYER_HPP_

#include "RLController.hpp"
#include "RLFAController.hpp"
#include "RLRBController.hpp"
#include "RLAction.hpp"
#include <sstream>
class RLPlayer
{

public:

	friend class RLController;
	friend class RLAction;

	RLPlayer();
	RLPlayer(int* p, double h, int controllerType=0);
	RLPlayer(const RLPlayer &otherPlayer);
	RLPlayer & RLPlayer::operator=( const RLPlayer &otherPlayer );

	// called by RLSimulator, 
	// calls RLController
	void makeAction(const RLPlayer* opp);

	~RLPlayer();

	RLAction* getAct() const { return act_; }
	void setAct(int act, int oXPos);

	RLAction* getPrevAct() const{ return prevAct_;}
	void setPrevAction(){ *prevAct_ = *act_;}

	// get-set pos
	int* getPos() const { return pos; };
	void setPos(int* p) { 
		setPrevPos(pos);	// store previous position
		pos[0] = p[0];
		pos[1] = p[1];
	}
	// get/set previous position
	int* getPrevPos() const { return prevPos; };
	void setPrevPos(int* p) { 
		prevPos[0] = p[0];
		prevPos[1] = p[1];
	}
	// get-set health
	double getHealth() const { return health; }
	void setHealth(double val) { health = val; }
	// get-set previous health
	double getPrevHealth() const { return prevHealth; }
	void setPrevHealth(double val) { prevHealth = val; }
	// get controller
	RLController* getController(){ return controller; };
	double updateHealth(RLAction* oppAct);
	string toString();
	int getHit() const { return isHit; }
	void setHit(int val) { isHit = val; }

private:
	RLController* controller;
	RLAction* act_;
	RLAction* prevAct_;

	int* pos;
	int* prevPos;
	double health;
	double prevHealth;

	void copy( const RLPlayer & otherPlayer );
	void cleanup( void );
	void updatePos(int dir);
	int isHit;

};

#endif