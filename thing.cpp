#include "thing.h"

Thing::Thing(QPixmap* p, int nx, int ny) : QGraphicsPixmapItem()
{
	pixMap = p;
	setPixmap(*p);
	x = nx;
	y = ny;
	setPos(x,y);
}

bool Thing:: getCheck()
{
	return goodCheck;
}
