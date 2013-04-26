#ifndef THING_H
#define THING_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QPixmap>

using namespace std;
class Thing: public QGraphicsPixmapItem
{
	public:
		Thing(QPixmap *pm, int nx, int ny);
		virtual void move() = 0;
		virtual int executePower() = 0;
		virtual void setX(int nx) = 0;
		virtual void setY(int ny) = 0;
		bool getCheck();

		
	protected:
		double x;
		double y;
		int vX;
		int vY;
		bool goodCheck;
		QPixmap* pixMap;
};


#endif

