#include "coin.h"
#include <iostream>

	/* Constructor for a coin, sets velocity to 2  
		@param pm Pixmap pointer to show picture
		@param nx Initial x cooridinate to set position
		@param ny Initial y coordinate to set poition  **/
Coin:: Coin(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
	
	*pm = pm->scaled(50, 50, Qt::KeepAspectRatio);
	vX = 2;
	vY = 2;
} 
/* Default destructor **/
Coin:: ~Coin()
{}
/* Moves upward for 20 counts of the timer, moves down for 20 counts, set position to refelct movement **/
void Coin :: move()
{
	if(counter < 20)
	{
		y-=vY;
		
		setPos(x,y);
	}
	else if(counter >= 20)
	{
		y+=vY;
		setPos(x,y);
	}
}

/* Sets the counter to be used for bouncing path in move()
		@param counter1 a counter passed by MainWindow **/
void Coin :: setCounter(int counter1)
{
	counter = counter1;
}

int Coin :: executePower()
{return 3;}

