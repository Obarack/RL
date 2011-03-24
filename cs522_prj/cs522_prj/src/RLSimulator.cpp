#include "../include/RLSimulator.h"


RLSimulator::RLSimulator(void)
{
	int p1pos[2] = {-10,0};
	int p2pos[2] = {10,0};
	pl1 = new RLPlayer(p1pos, 100);
	pl2 = new RLPlayer(p2pos, 100);

	((RLFAController*)(pl1->getController()))->getFeats()->setFeats(pl1, pl2);
}

void RLSimulator::runSimulation()
{
	int step = 30;
	
	int* tmp = new int[2];
	tmp[0] = 1;
	tmp[1] = 2;

	for ( int i=0; i<step; i++ )
	{
		int dist= (rand()%2);
		// store first players state
		RLPlayer prevP1 = *pl1;
		pl1->setPos(tmp);
		pl1->setAct(2, dist);
		//p1 select the best action
		pl1->makeAction(pl2);
		pl2->makeAction(&prevP1);

		((RLFAController*)(pl1->getController()))->updateModel(pl1,pl2);
	}
}


void main()
{
	RLSimulator* sim = new RLSimulator;
	sim->runSimulation();
}
