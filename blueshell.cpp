#include "blueshell.h"

BlueShell:: BlueShell(QPixmap *pm, int nx, int ny) : Thing(pm,nx,ny)
{
	*pm = pm->scaled(50, 50, Qt::KeepAspectRatio);
	vX = 1;
	vY = 1;
	x = nx;
	y = ny;
	goodCheck = true;
	
	setPos(x,y);
} 

BlueShell :: ~BlueShell()
{}

void BlueShell:: move()
{
	if(counter <= 150)
	{
		x+=vX;
	}
	if(counter > 150 && counter <= 300)
	{
		y+=vY;
	}
	if(counter > 300 && counter <= 450)
	{
		x-=vX;
	}
	if(counter > 450)
	{
		y-=vY;
	}
	
	setPos(x,y);

}

int BlueShell:: executePower()
{
	return 2;
}
	
void BlueShell:: setX(int nx)
{
	x= nx;
}
void BlueShell:: setY(int ny)
{
	y = ny;
}

void BlueShell:: setvX(int nvx)
{
	vX= nvx;
}
void BlueShell:: setvY(int nvy)
{
	vY = nvy;
}

void BlueShell:: setCounter(int counter1)
{
	counter = counter1;
}





