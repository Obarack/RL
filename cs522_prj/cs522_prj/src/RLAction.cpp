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

void RLAction::setVars()
{
	value = new double*[ACTION_COUNT];
	for (int i=0; i<ACTION_COUNT; i++)
	{
		value[i] = new double[3];
		if(i==L_KICK)
			setVals(i, 50, 100, 0);
		else if(i==U_CUT)
			setVals(i, 100, 25, 0);
		else if(i==BLOCK)
			setVals(i, 20, 10, 0);
	}

}

void RLAction::setVals(int act, double dc, double dn, double df)
{
	value[act][0] = dc;
	value[act][1] = dn;
	value[act][2] = df;
}