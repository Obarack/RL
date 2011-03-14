#pragma once
#ifndef _RLSIMULATION_HPP
#define _RLSIMULATION_HPP

#include "RLPlayer.hpp"

class RLSimulator
{
private:
	RLPlayer* pl1;
	RLPlayer* pl2;

public:
	RLSimulator(void);
	~RLSimulator(void)	{
		delete pl1;
		delete pl2;
	}
};

#endif
