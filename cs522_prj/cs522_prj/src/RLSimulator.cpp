#include "../include/RLSimulator.h"


RLSimulator::RLSimulator(void)
{
	pl1 = new RLPlayer;
	pl2 = new RLPlayer;
}

void RLSimulator::runSimulation()
{
	int step = 1;
	
	int* tmp = new int[2];
	tmp[0] = 1;
	tmp[1] = 2;

	for ( int i=0; i<step; i++ )
	{
		// store first players state
		RLPlayer prevP1 = *pl1;
		pl1->setPos(tmp);
		pl1->setAct(2, 1, 10);
		pl1->makeAction(pl2);
		pl1->makeAction(&prevP1);
		prevP1.makeAction(pl1);
	}
}


void main()
{
	RLSimulator* sim = new RLSimulator;
	sim->runSimulation();
}
