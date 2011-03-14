
#ifndef _RLACTION_HPP_
#define _RLACTION_HPP_

class RLAction
{
private:

	enum
	{
		L_KICK = 0;
		U_KICK;
		L_CUT;
		U_CUT;
		BLOCK;
		ACTION_COUNT
	} ACTION_TYPE;

	int type;
	double damage;

public:


};

#endif