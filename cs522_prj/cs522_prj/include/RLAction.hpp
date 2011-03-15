
#ifndef _RLACTION_HPP_
#define _RLACTION_HPP_

class RLAction
{

public:
	RLAction();
	RLAction(int act, int ty, int dam);
	RLAction(const RLAction &otherAct);

	int getAction() const { return action; }
	void setAction(int val) { action = val; }
	int getType() const { return type; }
	void setType(int val) { type = val; }
	double getDamage() const { return damage; }
	void setDamage(double val) { damage = val; }

private:

	enum
	{
		L_KICK = 0,
		U_KICK,
		L_CUT,
		U_CUT,
		BLOCK,
		ACTION_COUNT
	};

	int action;
	
	int type;

	double damage;


};

#endif