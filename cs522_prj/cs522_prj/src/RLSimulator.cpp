#include "../include/RLSimulator.h"
#include <fstream>

RLSimulator::RLSimulator(void)
{
	int p1pos[2] = {5,0};
	int p2pos[2] = {6,0};
	pl1 = new RLPlayer(p1pos, 90000, 0);
	pl2 = new RLPlayer(p2pos, 90000, 1);

	// initialize the features for the FA controlled player 
	((RLFAController*)(pl1->getController()))->getFeats()->setFeats(pl1, pl2);
}

void RLSimulator::runSimulation()
{
	int step = 100000;
	
	int* tmp = new int[2];
	tmp[0] = 1;
	tmp[1] = 2;

	/*cout<< "Player FA : "<< pl1->toString();
	cout<< "Player RB : "<< pl2->toString();*/

	for ( int i=0; i<step; i++ )
	{
		// store first players state
		RLPlayer* prevP1 = new RLPlayer(*pl1);
		// player 1 select its action based on the percentage of greedy exploitation
		int bestAct1 = pl1->makeAction(pl2);
		// player 2 select its action based on predefined rules 
		int bestAct2 = pl2->makeAction(prevP1);

		((RLFAController*)(pl1->getController()))->updateModel(pl1,pl2, bestAct1);
		((RLRBController*)(pl2->getController()))->updateModel(pl2,pl1, bestAct2);

		delete prevP1;
		prevP1 = NULL;

		//cout<< "Player FA : "<< pl1->toString();
		//cout<< "Player RB : "<< pl2->toString();
	}

	ofstream myfile;
	myfile.open ("Rewards.txt");
	vector<double> rewards = pl1->getController()->getAllReward();
	for( int i = 0; i< rewards.size(); i++ )
		myfile <<rewards.at(i) << endl;
	myfile.close();
}


void main()
{
	RLSimulator* sim = new RLSimulator;
	sim->runSimulation();
}
