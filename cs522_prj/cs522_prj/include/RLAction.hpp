
#ifndef _RLACTION_HPP_
#define _RLACTION_HPP_

class RLAction
{

public:
	RLAction();
	RLAction(const RLAction &otherAct);

	enum
	{
		L_KICK = 0,
		//		U_KICK,
		//		L_CUT,
		U_CUT,
		BLOCK,
		WALK_F,
		WALK_B,
		RUN_F,
		RUN_B,
		ACTION_COUNT
	};

	enum
	{
		OFF = 0,
		DEF,
		NEU,
		TYPE_COUNT
	};

	enum
	{
		CLOSE = 0,
		NEAR,
		FAR,
		DIST_COUNT
	};

	int getAction() const { return action; }
	void setAction(int val);
	int getType() const { return type; }
	void setType(int val) { type = val; }
	double getValue(int act, int dist) const { return value[act][dist]; }
	int getDist() const { return dist; }
	void setDist(int val);

private:

	int action;
	// 0 - offensive, 1 - defensive, 2 - neutral
	int type;
	// for offensive actions
	double** value;
	// 
	int dist;
	
	void setVars();
	void setVals(int act, double dc, double dn, double gf);
};

#endif