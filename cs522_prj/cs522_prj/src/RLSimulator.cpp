#include "../include/RLSimulator.h"


RLSimulator::RLSimulator(void)
{
	int p1pos[2] = {5,0};
	int p2pos[2] = {6,0};
	pl1 = new RLPlayer(p1pos, 9000, 0);
	pl2 = new RLPlayer(p2pos, 9000, 1);

	// initialize the features for the FA controlled player 
	((RLFAController*)(pl1->getController()))->getFeats()->setFeats(pl1, pl2);
}

void RLSimulator::runSimulation()
{
	int step = 10;
	
	int* tmp = new int[2];
	tmp[0] = 1;
	tmp[1] = 2;

	cout<< "Player FA : "<< pl1->toString();
	cout<< "Player RB : "<< pl2->toString();

	for ( int i=0; i<step; i++ )
	{
		// store first players state
		RLPlayer* prevP1 = new RLPlayer(*pl1);
		// player 1 select its action based on the percentage of greedy exploitation
		pl1->makeAction(pl2);
		// player 2 select its action based on predefined rules 
		pl2->makeAction(prevP1);

		((RLFAController*)(pl1->getController()))->updateModel(pl1,pl2);
		((RLRBController*)(pl2->getController()))->updateModel(pl2,pl1);

		cout<< "Player FA : "<< pl1->toString();
		cout<< "Player RB : "<< pl2->toString();
	}
}


void main()
{
	RLSimulator* sim = new RLSimulator;
	sim->runSimulation();
}
