#include "coin.h"
#include <iostream>


Coin:: Coin(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
	
	*pm = pm->scaled(50, 50, Qt::KeepAspectRatio);
	vX = 2;
	vY = 2;
	x = nx;
	y = ny;
	goodCheck = true;
	
	setPos(x,y);
} 

Coin:: ~Coin()
{}

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

void Coin:: setX(int nx)
{
	x= nx;
}
void Coin:: setY(int ny)
{
	y = ny;
}


void Coin :: setCounter(int counter1)
{
	counter = counter1;
}

int Coin :: executePower()
{return 3;}

