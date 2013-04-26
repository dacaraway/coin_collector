#include "greenshell.h"

GreenShell:: GreenShell(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
	
	*pm = pm->scaled(50, 50, Qt::KeepAspectRatio);
	vX = 5;
	vY = 5;
	x = nx;
	y = ny;
	
	goodCheck = true;
	
	setPos(x,y);
} 

GreenShell :: ~GreenShell()
{}

double GreenShell:: getVelX()
{
	return vX;
}
double GreenShell:: getVelY()
{
 return vY;
}

void GreenShell:: setVelX(int x)
{
	vX+=x;
}
void GreenShell:: setVelY(int y)
{
	vY += y;
}

void GreenShell:: setDVelX(int x)
{
	vX=x;
}
void GreenShell:: setDVelY(int y)
{
	vY = y;
}

void GreenShell:: setX(int nx)
{
	x= nx;
}
void GreenShell:: setY(int ny)
{
	y = ny;
}

void GreenShell:: move()
{
	x += vX;
    y += vY;

    if ( x < -30 ) 
    {
        vX = -vX;
        x +=vX;
    }

    if ( y < -30 ) 
    {
        vY = -vY;
        y +=vY;
    }
    if ( (x+75) > 990 ) 
    {
         vX = -vX;
         x+=vX;
    }

    if ( (y+75) > 710 ) 
    {
         vY = -vY;
         y+=vY;
    }
    
    setPos(x,y);
}

int GreenShell:: executePower()
{return 1;}
