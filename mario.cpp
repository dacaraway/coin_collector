#include "mario.h"

#include <iostream>

using namespace std;

	/* Constructor for a Mario, sets velocity to 0 and the original pixmap to left picture.  Also declares all the the pictures for the different directions.  
		@param nx Initial x cooridinate to set position
		@param ny Initial y coordinate to set poition  **/
Mario :: Mario(int nx, int ny)
{
	x = nx;
	y = ny;
	vX=0;
	vY=0;
	
	pixmap = new QGraphicsPixmapItem();

	rightMarioPic =  new QPixmap("PNGpics/mariorunningaheadE.png");
	upMarioPic = new QPixmap("PNGpics/marioUP.png");
	leftMarioPic = new QPixmap("PNGpics/mariorunningaheadW.png");

	pixmap->setPixmap(*leftMarioPic);

	pixmap->setPos(x,y);
	
}
/* Default destructor **/
Mario:: ~Mario()
{}
/* Moves mario the given veolicty based on keyPressEvent() in the GraphicsView class, sets the bounds for the screen so Mario cannot go off **/
void Mario::move_()
{
	x+=vX;
	y+= vY;
	 
	if(x>870 || x<-55)
	{
		x-=vX;
	}
	if(y<-25 || y>550)
	{
		y-=vY;
	}
	pixmap->setPos(x,y);
}
/* Sets the vX and vY variable of the item, used for velocity
		@param tx the int to be set for vX 
		@param ty the int to be set for vY **/
void Mario:: setVel(int tx, int ty)
{
	vX = tx;
	vY = ty;
}
/* Sets the pixmap based on keyPressEvent() in the GraphicsView class
		@param number The number passed by the key presses to pick through the swtich**/
void Mario:: setPic(int number)
{
	switch(number)
	{
		case 1:
		{	
			pixmap->setPixmap(*upMarioPic);
			break;
		}
			
		case 2:
		{	
			pixmap->setPixmap(*rightMarioPic);
			break;

		}
		case 3:
		{
			pixmap->setPixmap(*upMarioPic);
			break;
		}
		case 4:
		{
			pixmap->setPixmap(*leftMarioPic);
			break;
		}
	}
}
/* Sets the X variable of the item
		@param nx An int passed into from MainWindow **/
void Mario:: setX(int nx)
{
	x= nx;
}
/* Sets the Y variable of the item
	@param ny An int passed into from MainWindow **/
void Mario:: setY(int ny)
{
	y = ny;
}


