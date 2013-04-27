#ifndef BLUE_SHELL_H
#define BLUE_SHELL_H
#include "thing.h"

/** The BlueShell class hold all the members for the blue shell item which guards the coin in a square path and kills the player on impact.
@author Daria Caraway

@pre Thing */

class BlueShell: public Thing
{
	public:
		/** Constructor for a blue shell, sets velocity to 1  
		@param pm Pixmap pointer to show picture
		@param nx Initial x cooridinate to set position
		@param ny Initial y coordinate to set poition  **/
		BlueShell(QPixmap *pm, int nx, int ny);
		/** Default destructor **/
		~BlueShell();
		/** Checks counter and sets velocities and updates position based on where item should be in square cycle **/
		void move();
		/** @return 2-- tells switch in MainWindow to execute blue shell collision  **/
		int executePower();
		/** Sets the counter to be used for square path in move()
		@param counter1 a counter passed by MainWindow **/
		void setCounter(int counter1);
		/** Sets the vX variable of the item, used for velocity
		@param nvx An int passed into from MainWindow **/
		void setvX(int nvx);
		/** Sets the vY variable of the item, used for velocity
		@param nvx An int passed into from MainWindow **/
		void setvY(int nvy);

		
		
	private:
		/** The counter that is used in move() and set equal to the param in setCounter() **/
		int counter;
};

#endif
