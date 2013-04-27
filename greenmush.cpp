#include "greenmush.h"

	/* Constructor for a green mushroom sets velocity to 0, sets the check off status to true 
		@param pm Pixmap pointer to show picture
		@param nx Initial x cooridinate to set position
		@param ny Initial y coordinate to set poition  **/
GreenMush:: GreenMush(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
	*pm = pm->scaled(50, 50, Qt::KeepAspectRatio);
	vX = 0;
	vY = 0;
} 
/* Default destructor **/
GreenMush:: ~GreenMush()
{}
/* Sets the X variable of the item
	@return A boolean for the state of the checker **/
bool GreenMush:: getCheck()
{
	return goodCheck;
}

/* Sets the check off status for the mushroom, this is needed because when the mushroom is deleted the checker is set to false, so the mushroom is not deleted more that once off the scene.
		@param checker the checker that is inside the MainWindow **/
void GreenMush:: setCheck(bool checker)
{
	goodCheck = checker;
}
/* The green mushroom does not implement a move function, but derives from class thing which as a pure virtual move function **/
void GreenMush:: move() {}

/* @return 4-- tells switch in MainWindow to execute mushroom collision  **/
int GreenMush :: executePower() {return 4;}


