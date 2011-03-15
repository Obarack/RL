#pragma once
#ifndef _RLSIMULATION_HPP
#define _RLSIMULATION_HPP

#include "RLPlayer.hpp"

class RLSimulator
{

public:
	RLSimulator(void);
	~RLSimulator(void)	{
		delete pl1;
		delete pl2;
	};

	void runSimulation();

private:
	RLPlayer* pl1;
	RLPlayer* pl2;

};

#endif
