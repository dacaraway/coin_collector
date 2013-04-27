#ifndef GREEN_SHELL_H
#define GREEN_SHELL_H

#include "thing.h"

/** The GreenShell class holds all the members for the green shell item which bounces around the screen.
@author Daria Caraway

@pre Thing */
class GreenShell: public Thing
{
	public:
	/** Constructor for a red shell, sets velocity to 3 
		@param pm Pixmap pointer to show picture
		@param nx Initial x cooridinate to set position
		@param ny Initial y coordinate to set poition  **/
		GreenShell(QPixmap *pm, int nx, int ny);
		/** Default destructor **/
		~GreenShell();
		/** Sets the velocities when the shell reaches the bounds of the screen **/
		void move();
		/** @return 1-- tells switch in MainWindow to execute shell collision  **/
		int executePower();
		/** @return the current vX of the greenshell  **/
		double getVelX();
		/** @return the current vY of the greenshell  **/
		double getVelY();
		/** Adds the paramenter to the vX of the object
		@param x The int passed in from MainWIndow **/
		void setVelX(int x);
		/** Adds the paramenter to the vY of the object
		@param y The int passed in from MainWIndow **/
		void setVelY(int y);
		/** sets the vX of the object
		@param x The int passed in from MainWIndow **/
		void setDVelX(int x);
		/** sets the vY of the object
		@param y The int passed in from MainWIndow **/
		void setDVelY(int y);


};

#endif
