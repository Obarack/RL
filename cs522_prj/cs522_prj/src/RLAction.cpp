#include "../include/RLAction.hpp"

RLAction::RLAction(): action(L_KICK), dist(0)
{
	setVars();
}

RLAction::RLAction( const RLAction &otherAct )
{
	action = otherAct.action;
	type = otherAct.type;
	value = otherAct.value;
	dist = otherAct.dist;
}

void RLAction::setAction(int val) 
{ 
	action = val; 
	if (action<=U_CUT)
		setType(OFF);
	else if (action<=BLOCK)
		setType(DEF);
	else if (action<=RUN_B)
		setType(NEU);
}

void RLAction::setDist(int val) 
{ 
	if ( val < 2 )
		dist = CLOSE;
	else if ( val < 3 )
		dist = NEAR;
	else dist = FAR;
}

//void RLAction::setPrevDist() 
//{ 
//	prevDist = dist;
//}

void RLAction::setVars()
{
	value = new double*[ACTION_COUNT];
	for (int i=0; i<ACTION_COUNT; i++)
	{
		value[i] = new double[3];
		if(i==L_KICK)
			setVals(i, 5, 10, 0);
		else if(i==U_CUT)
			setVals(i, 10, 5, 0);
			//setVals(i, 50, 15, 0);
		else if(i==BLOCK)
			setVals(i, 8, 10, 0);
		else if(i==WALK_F)
			setVals(i, 0, 5, 10);
		else if(i==WALK_B)
			setVals(i, 10, 5, 0);
		else if(i==RUN_F)
			setVals(i, 0, 0, 8);
		else if(i==RUN_B)
			setVals(i, 5, 2, 0);
	}

}

void RLAction::setVals(int act, double dc, double dn, double df)
{
	value[act][0] = dc;
	value[act][1] = dn;
	value[act][2] = df;
}