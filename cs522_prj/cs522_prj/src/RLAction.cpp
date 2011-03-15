#include "../include/RLAction.hpp"

RLAction::RLAction(): action(L_KICK), type(0), damage(0)
{
}

RLAction::RLAction( int act, int ty, int dam ) : action(act), type(ty), damage(dam)
{
}

RLAction::RLAction( const RLAction &otherAct )
{
	action = otherAct.action;
	type = otherAct.type;
	damage = otherAct.damage;
}
