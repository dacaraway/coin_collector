#ifndef MARIO_H
#define MARIO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QLabel>


class Mario
{
	public:
		Mario(int nx, int ny);
		~Mario();
		void move_();
		void setVel(int tx, int ty);
		void setPic(int number);
		QGraphicsPixmapItem* pixmap;
		void setPrevDirec(int num);
		void setX(int nx);
		void setY(int ny);

		
	private:
		int x;
		int y;
		int vX;
		int vY;

		QPixmap* upMarioPic;
		QPixmap* rightMarioPic;
		QPixmap* leftMarioPic;
		int prevDirec;
		QGraphicsView* view_;

		
};


#endif
