#include "redshell.h"
#include <cmath>
#include <iostream>

using namespace std;

RedShell :: RedShell(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
	*pm = pm->scaled(50, 50, Qt::KeepAspectRatio);
	vX = 1.1;
	vY = 1.1;
	x = nx;
	y = ny;
	goodCheck = true;
}

RedShell:: ~RedShell()
{}

double RedShell:: getVelX()
{
	return vX;
}
double RedShell:: getVelY()
{
 return vY;
}

void RedShell:: setVelX(int x)
{
	vX+=x;
}
void RedShell:: setVelY(int y)
{
	vY += y;
}
void RedShell:: setDVelX(int x)
{
	vX=x;
}
void RedShell:: setDVelY(int y)
{
	vY = y;
}


void RedShell:: setX(int nx)
{
	x= nx;
}
void RedShell:: setY(int ny)
{
	y = ny;
}

void RedShell::move(QPointF point)
{
	// finding projectile angle
	double dy = (point.y() +50) - pos().y();
	double dx = point.x() - pos().x();

	
		double angle = dy/dx;

		double velocityX = abs(cos(angle) * vX);
		double velocityY = abs(sin(angle) * vY);
	
		if(dx > 0)
		{
			x= x + velocityX;
		}
		if (dx < 0)
		{
			x = x - velocityX;
		}
		if ( dx == 0)
		{
			x=x;
		}
		if(dy > 0)
		{
			y = y + velocityY;
		}
		if(dy < 0)
		{
			y = y -velocityY;
		}
		if ( dy == 0)
		{
			y=y;
		}
	
		setPos(x,y);
	
}


void RedShell :: move()
{
	setPos(x,y);
}

int RedShell::executePower()
{return 1;}

