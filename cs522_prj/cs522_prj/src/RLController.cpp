
#include "../include/RLController.hpp"
#include "../include/RLPlayer.hpp"

double RLController::checkBorder( RLPlayer*& p1 )
{
	double wallPun = 0;
	int* newP = new int[2];
	p1->setHit(-1);
	newP[0] = p1->getPos()[0];
	newP[1] = p1->getPos()[1];

	if (newP[0] > getBorder()[1])
	{
		newP[0] = getBorder()[1];
		p1->setPos(newP);
		wallPun = -10;
		p1->setHit(1);
	}
	else if (newP[0] < getBorder()[0])
	{
		newP[0] = getBorder()[0];
		p1->setPos(newP);
		wallPun = -10;
		p1->setHit(1);
	}

	delete newP;	newP = NULL;
	return wallPun;
};