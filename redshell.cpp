#include "redshell.h"
#include <cmath>
#include <iostream>

using namespace std;
/* Constructor for a red shell, sets velocity to 1.1  
	@param pm Pixmap pointer to show picture
	@param nx Initial x cooridinate to set position
	@param ny Initial y coordinate to set poition  **/
RedShell :: RedShell(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
	*pm = pm->scaled(50, 50, Qt::KeepAspectRatio);
	vX = 1.1;
	vY = 1.1;
}

/* Default destructor **/
RedShell:: ~RedShell()
{}
/* @return the current vX of the redshell  **/
double RedShell:: getVelX()
{
	return vX;
}
/* @return the current vY of the redshell  **/
double RedShell:: getVelY()
{
 return vY;
}
/* Adds the paramenter to the vX of the object
	@param x The int passed in from MainWIndow **/
void RedShell:: setVelX(double x)
{
	vX+=x;
}
/* Adds the parameter vY of the object
	@param y The int passed in from MainWIndow **/
void RedShell:: setVelY(double y)
{
	vY += y;
}
/* sets the vX of the object
	@param x The int passed in from MainWIndow **/
void RedShell:: setDVelX(double x)
{
	vX=x;
}
/* sets the vY of the object
	@param y The int passed in from MainWIndow **/
void RedShell:: setDVelY(double y)
{
	vY = y;
}


/* Takes the position of the mainPLayer and uses trig to calculate the angle that needs to be traveled, and sets the velocity and direction accordingly
	@param point The position of the main player passed by MainWindow **/
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

/* The RedShell class implements its own move function, but this one is pure virtual within Thing **/
void RedShell :: move()
{
	setPos(x,y);
}
/* @return 1-- tells switch in MainWindow to execute shell collision  **/
int RedShell::executePower()
{return 1;}

