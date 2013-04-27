#include "blueshell.h"
	/* Constructor for a blue shell, sets velocity to 1  
		@param pm Pixmap pointer to show picture
		@param nx Initial x cooridinate to set position
		@param ny Initial y coordinate to set poition  **/
BlueShell:: BlueShell(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
	*pm = pm->scaled(50, 50, Qt::KeepAspectRatio);
	vX = 1;
	vY = 1;
	x = nx;
	y = ny;
	// bool to see if iterator should explore this object
	goodCheck = true;
	
	setPos(x,y);
} 
/* Default destructor **/
BlueShell :: ~BlueShell()
{}
/* Checks counter and sets velocities and updates position based on where item should be in square cycle **/
void BlueShell:: move()
{
	if(counter <= 150)
	{
		x+=vX;
	}
	if(counter > 150 && counter <= 300)
	{
		y+=vY;
	}
	if(counter > 300 && counter <= 450)
	{
		x-=vX;
	}
	if(counter > 450)
	{
		y-=vY;
	}
	
	setPos(x,y);

}
/* @return 2-- tells switch in MainWindow to execute blue shell collision  **/
int BlueShell:: executePower()
{
	return 2;
}
	/* Sets the X variable of the item
		@param nx An int passed into from MainWindow **/
void BlueShell:: setX(int nx)
{
	x= nx;
}
/* Sets the Y variable of the item
		@param nx An int passed into from MainWindow **/
void BlueShell:: setY(int ny)
{
	y = ny;
}
/* Sets the vX variable of the item, used for velocity
		@param nvx An int passed into from MainWindow **/
void BlueShell:: setvX(int nvx)
{
	vX= nvx;
}
/* Sets the vY variable of the item, used for velocity
		@param nvx An int passed into from MainWindow **/
void BlueShell:: setvY(int nvy)
{
	vY = nvy;
}
/* Sets the counter to be used for square path in move()
		@param counter1 a counter passed by MainWindow **/
void BlueShell:: setCounter(int counter1)
{
	counter = counter1;
}





