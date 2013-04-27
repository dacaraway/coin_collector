#include "thing.h"

/* Constructor for a Thing, sets pixMap, x and y, sets initial position.  
		@param pm Pixmap pointer to show picture
		@param nx Initial x cooridinate to set position
		@param ny Initial y coordinate to set poition  **/


Thing::Thing(QPixmap* p, int nx, int ny) : QGraphicsPixmapItem()
{
	pixMap = p;
	setPixmap(*p);
	x = nx;
	y = ny;
	setPos(x,y);
	goodCheck = true;
}
/* @return A boolean to help when iterating for collisions  **/
bool Thing:: getCheck()
{
	return goodCheck;
}

/* Sets the X variable of the item
	@param nx An int passed into from MainWindow **/
void Thing:: setX(int nx)
{
	x= nx;
}
/* Sets the Y variable of the item
	@param ny An int passed into from MainWindow **/
void Thing:: setY(int ny)
{
	y = ny;
}

