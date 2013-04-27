#ifndef COIN_H
#define COIN_H
#include "thing.h"

/** The coin class holds all the members for the coin item which bounces up and down and increases the score when collided with by mario.
@author Daria Caraway

@pre Thing */

class Coin: public Thing
{
	public:
	/** Constructor for a coin, sets velocity to 2  
		@param pm Pixmap pointer to show picture
		@param nx Initial x cooridinate to set position
		@param ny Initial y coordinate to set poition  **/
		Coin(QPixmap *pm, int nx, int ny);
		/** Default destructor **/
		~Coin();
		/** Moves upward for 20 counts of the timer, moves down for 20 counts, set position to refelct movement **/
		void move();
		/** @return 3-- tells switch in MainWindow to execute coin collision  **/
		int executePower();
		/** Sets the counter to be used for bouncing path in move()
		@param counter1 a counter passed by MainWindow **/
		void setCounter(int counter1);

		
	private:
	/** The counter that is used in move() and set equal to the param in setCounter() **/
		int counter;
};

#endif
