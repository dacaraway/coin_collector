#include "greenshell.h"
/* Constructor for a red shell, sets velocity to 3 
		@param pm Pixmap pointer to show picture
		@param nx Initial x cooridinate to set position
		@param ny Initial y coordinate to set poition  **/
GreenShell:: GreenShell(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
	
	*pm = pm->scaled(50, 50, Qt::KeepAspectRatio);
	vX = 3;
	vY = 3;

} 
/* Default destructor **/
GreenShell :: ~GreenShell()
{}
/* @return the current vX of the greenshell  **/
double GreenShell:: getVelX()
{
	return vX;
}
/** @return the current vY of the greenshell  **/
double GreenShell:: getVelY()
{
 return vY;
}
/* Adds the paramenter to the vX of the object
		@param x The int passed in from MainWIndow **/
void GreenShell:: setVelX(int x)
{
	vX+=x;
}
/** Adds the paramenter to the vY of the object
		@param y The int passed in from MainWIndow **/
void GreenShell:: setVelY(int y)
{
	vY += y;
}
/* sets the vX of the object
		@param x The int passed in from MainWIndow **/
void GreenShell:: setDVelX(int x)
{
	vX=x;
}
/* sets the vY of the object
		@param y The int passed in from MainWIndow **/
void GreenShell:: setDVelY(int y)
{
	vY = y;
}
/* Sets the velocities when the shell reaches the bounds of the screen **/
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

/* @return 1-- tells switch in MainWindow to execute shell collision  **/
int GreenShell:: executePower()
{return 1;}
