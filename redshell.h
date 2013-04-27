#ifndef RED_SHELL_H
#define RED_SHELL_H

#include "thing.h"



/** The RedShell class holds all the members for the red shell item which follows around the player.
@author Daria Caraway

@pre Thing */
class RedShell: public Thing
{
	public:
	/** Constructor for a red shell, sets velocity to 1.1  
		@param pm Pixmap pointer to show picture
		@param nx Initial x cooridinate to set position
		@param ny Initial y coordinate to set poition  **/
		RedShell(QPixmap *pm, int nx, int ny);
		/** Default destructor **/
		~RedShell();
		/** The RedShell class implements its own move function, but this one is pure virtual within Thing **/
		void move();
		/** Takes the position of the mainPLayer and uses trig to calculate the angle that needs to be traveled, and sets the velocity and direction accordingly
		@param point The position of the main player passed by MainWindow **/
		void move(QPointF point);
		/** @return 1-- tells switch in MainWindow to execute shell collision  **/
		int executePower();
		/** @return the current vX of the redshell  **/
		double getVelX();
		/** @return the current vY of the redshell  **/
		double getVelY();
		/** Adds the paramenter to the vX of the object
		@param x The int passed in from MainWIndow **/
		void setVelX(double x);
		/** Adds the parameter vY of the object
		@param y The int passed in from MainWIndow **/
		void setVelY(double y);
		/** sets the vX of the object
		@param x The int passed in from MainWIndow **/
		void setDVelX(double x);
		/** sets the vY of the object
		@param y The int passed in from MainWIndow **/
		void setDVelY(double y);



};

#endif
