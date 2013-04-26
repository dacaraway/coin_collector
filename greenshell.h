#ifndef GREEN_SHELL_H
#define GREEN_SHELL_H

#include "thing.h"


class GreenShell: public Thing
{
	public:
		GreenShell(QPixmap *pm, int nx, int ny);
		~GreenShell();
		void move();
		int executePower();
		double getVelX();
		double getVelY();
		void setVelX();
		void setVelY();
		void setVelX(int x);
		void setVelY(int y);
		void setDVelX(int x);
		void setDVelY(int y);
		void setX(int nx);
		void setY(int ny);
};

#endif
