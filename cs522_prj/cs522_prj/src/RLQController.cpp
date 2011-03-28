#include "../include/RLQController.h"


RLQController::RLQController(void)
{
	qValues = new double**[RLAction::DIST_COUNT];
	for (int i=0; i<RLAction::DIST_COUNT; i++)
	{
		qValues[i] = new double*[RLAction::ACTION_COUNT];
		for (int j=0; j<RLAction::ACTION_COUNT; j++) 
		{
			qValues[i][j] = new double[RLAction::ACTION_COUNT];
			for (int k=0; k<RLAction::ACTION_COUNT; k++)
			{
				qValues[i][j][k] = 0;
			}
		}
	}
}


RLQController::~RLQController(void)
{
	delete [] qValues;
	qValues = NULL;
}

void RLQController::decideAction(int step, double greedyProb, RLPlayer* p1, const RLPlayer* opp)
{
	double rnd = (double)rand()/RAND_MAX;

	int bestAct = 0;
	RLPlayer* pl1 = new RLPlayer(*p1);
	RLPlayer* pl2 = new RLPlayer(*opp);
	RLAction* act = pl1->getAct();

	if (rnd < greedyProb)
	{
		//pl1->setAct(0, pl2->getPos()[0]);
		// compute new feature values
		int startAct = rand()%RLAction::ACTION_COUNT;
		double bestQValue = getQValues(pl1->getAct()->getDist(), startAct, pl2->getAct()->getAction());
		double tempQValue = 0;

		for (int i=1; i<RLAction::ACTION_COUNT; i++)
		{
			startAct = (startAct+1)%RLAction::ACTION_COUNT;

			tempQValue = getQValues(pl1->getAct()->getDist(),startAct, pl2->getAct()->getAction());
			if(bestQValue < tempQValue ){
				bestAct = startAct;
				bestQValue = tempQValue;
			}
		}
	}
	else{
		bestAct = rand()%RLAction::ACTION_COUNT;
	}
	p1->setAct(bestAct, pl2->getPos()[0]);//set the action to the one that gives best q value
}

void RLQController::updateModel( RLPlayer* p1, const RLPlayer* opp )
{

}

double RLQController::qvalue(double* ft)
{
	return 0;
}
