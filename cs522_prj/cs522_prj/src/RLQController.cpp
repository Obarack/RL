#include "../include/RLQController.h"


RLQController::RLQController(void)
{
	qValues = new double**[RLAction::DIST_COUNT];
	visits = new int**[RLAction::DIST_COUNT];
	for (int i=0; i<RLAction::DIST_COUNT; i++)
	{
		qValues[i] = new double*[RLAction::ACTION_COUNT];
		visits[i] = new int*[RLAction::ACTION_COUNT];
		for (int j=0; j<RLAction::ACTION_COUNT; j++) 
		{
			qValues[i][j] = new double[RLAction::ACTION_COUNT];
			visits[i][j] = new int[RLAction::ACTION_COUNT];
			for (int k=0; k<RLAction::ACTION_COUNT; k++)
			{
				qValues[i][j][k] = 0;
				visits[i][j][k] = 0;
			}
		}
	}
	sarsa = true;
}


RLQController::~RLQController(void)
{
	delete [] qValues;
	delete [] visits;
	qValues = NULL;
}

int RLQController::decideAction(int step, double greedyProb, RLPlayer* p1, const RLPlayer* opp)
{
	double rnd = (double)rand()/RAND_MAX;

	int bestAct = -1;
	RLPlayer* pl1 = new RLPlayer(*p1);
	RLPlayer* pl2 = new RLPlayer(*opp);

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
	//p1->setAct(bestAct, pl2->getPos()[0]);//set the action to the one that gives best q value

	delete pl1;	delete pl2;
	pl1 = NULL;	pl2 = NULL;

	return bestAct;
}

void RLQController::updateModel( RLPlayer*& p1, RLPlayer*& opp, int bestAct )
{
	RLPlayer* pl1 = new RLPlayer(*p1);
	RLPlayer* pl2 = new RLPlayer(*opp);
	int d = pl1->getAct()->getPrevDist();		// get previous distance between players
	int a1 = pl1->getPrevAct()->getAction();	// get first player's action
	int a2 = pl2->getPrevAct()->getAction();	// get second player's action

	// sarsa learning
	if (isSarsa())
	{
		double newDatum = getPrevReward() + getDiscount()*getQValues(d, a1, a2);
		visits[d][a1][a2]++;	// update visits on that state
		setAlpha(1.0/visits[d][a1][a2]);

		qValues[d][a1][a2] = (1-getAlpha())*(qValues[d][a1][a2]) + getAlpha()*newDatum;

		double wallPun = checkBorder(p1);

		int m_dist = abs(opp->getPos()[0] - p1->getPos()[0]);
		p1->getAct()->setDist(m_dist);
		double rwd = p1->updateHealth(opp->getAct());
		// set reward. add up if the player hits the walls
		setPrevReward(rwd+wallPun);	
	}

	delete pl1;	delete pl2;
	pl1 = NULL;	pl2 = NULL;
}

double RLQController::qvalue(double* ft)
{
	return 0;
}
