#ifndef THING_H
#define THING_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QPixmap>

/** The Thing class is the base class for all of the objects in the game
@author Daria Caraway

@post BlueShell
@post RedShell
@post GreenShell
@post Coin
@post GreenMush  */
class Thing: public QGraphicsPixmapItem
{
	public:
	/** Constructor for a Thing, sets pixMap, x and y, sets initial position.  
		@param pm Pixmap pointer to show picture
		@param nx Initial x cooridinate to set position
		@param ny Initial y coordinate to set poition  **/
		Thing(QPixmap *pm, int nx, int ny);
		/** A pure virtual function for the things to move  **/
		virtual void move() = 0;
		/** A pure virtual function for the things to return their power identifier **/
		virtual int executePower() = 0;
		/** A pure virtual function for the things to set their y  **/
		void setX(int nx);
		/** A pure virtual function for the things to set their y  **/
		void setY(int ny);
		/** @return A boolean to help when iterating for collisions  **/
		bool getCheck();

		
	protected:
	/** The current x location of the thing  **/
		double x;
		/** The current y location of the thing  **/
		double y;
		/** The current x velocity of the thing  **/
		double vX;
		/** The current y velocity of the thing  **/
		double vY;
		/** The bool returned in getCheck()  **/
		bool goodCheck;
		/** The current picture set to the object  **/
		QPixmap* pixMap;
};


#endif

