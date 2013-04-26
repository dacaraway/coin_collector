#include "greenmush.h"

GreenMush:: GreenMush(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
	*pm = pm->scaled(50, 50, Qt::KeepAspectRatio);
	vX = 0;
	vY = 0;
	x = nx;
	y = ny;
	
	goodCheck = true;
	
	setPos(x,y);
} 

GreenMush:: ~GreenMush()
{}


void GreenMush:: setX(int nx)
{
	x= nx;
}
void GreenMush:: setY(int ny)
{
	y = ny;
}

bool GreenMush:: getCheck()
{
	return goodCheck;
}

void GreenMush:: setCheck(bool checker)
{
	goodCheck = checker;
}

void GreenMush:: move() {}
int GreenMush :: executePower() {return 4;}
