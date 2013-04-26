#ifndef RED_SHELL_H
#define RED_SHELL_H

#include "thing.h"

class RedShell: public Thing
{
	public:
		RedShell(QPixmap *pm, int nx, int ny);
		~RedShell();
		void move();
		void move(QPointF point);
		int executePower();
		double getVelX();
		double getVelY();
		void setVelX(int x);
		void setVelY(int y);
		void setDVelX(int x);
		void setDVelY(int y);
		void setX(int nx);
		void setY(int ny);
	
};

#endif
