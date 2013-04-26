#include "mario.h"

#include <iostream>

using namespace std;

Mario :: Mario(int nx, int ny)
{
	x = nx;
	y = ny;
	vX=0;
	vY=0;
	
	pixmap = new QGraphicsPixmapItem();

	rightMarioPic =  new QPixmap("PNGpics/mariorunningaheadE.png");
	upMarioPic = new QPixmap("PNGpics/marioUP.png");
	leftMarioPic = new QPixmap("PNGpics/mariorunningaheadW.png");

	pixmap->setPixmap(*leftMarioPic);

	pixmap->setPos(x,y);
	
	//pixmap->setFlag(QGraphicsItem::ItemIsFocusable);

	
	prevDirec = 4;
	
}

Mario:: ~Mario()
{}

void Mario::move_()
{
	x+=vX;
	y+= vY;
	 
	if(x>870 || x<-55)
	{
		x-=vX;
	}
	if(y<-25 || y>550)
	{
		y-=vY;
	}
	pixmap->setPos(x,y);
}

void Mario:: setVel(int tx, int ty)
{
	vX = tx;
	vY = ty;
}

void Mario:: setPrevDirec(int num)
{
	prevDirec=num;
}

void Mario:: setPic(int number)
{
	switch(number)
	{
		case 1:
		{	
			if(prevDirec == 2)
			{
				pixmap->setPixmap(*upMarioPic);	
			}
			if(prevDirec == 4)
			{
				pixmap->setPixmap(*upMarioPic);
			}
			break;
		}
		case 2:
		{	
			pixmap->setPixmap(*rightMarioPic);
			break;

		}
		case 3:
		{
			pixmap->setPixmap(*upMarioPic);
			break;
		}
		case 4:
		{
			pixmap->setPixmap(*leftMarioPic);
			break;
		}
	}
}

void Mario:: setX(int nx)
{
	x= nx;
}
void Mario:: setY(int ny)
{
	y = ny;
}


