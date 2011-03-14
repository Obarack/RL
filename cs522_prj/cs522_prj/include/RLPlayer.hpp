
#ifndef _RLPLAYER_HPP_
#define _RLPLAYER_HPP_

#include "RLController.hpp"
#include "RLAction.hpp"

class RLPlayer
{
private:
	RLController* controller;
	RLAction* act;
	int pos[2];

public:
	RLPlayer();
	RLPlayer(const &otherPlayer);

	// called by RLSimulator, 
	// calls RLController
	void makeAction(const RLPlayer*& opp);

	~RLPlayer()
	{
		delete controller;
		delete act;
		delete [] pos;
	}
};

#endif