#ifndef BLUE_SHELL_H
#define BLUE_SHELL_H
#include "thing.h"

class BlueShell: public Thing
{
	public:
		BlueShell(QPixmap *pm, int nx, int ny);
		~BlueShell();
		void move();
		int executePower();
		void setCounter(int counter1);
		void setX(int nx);
		void setY(int ny);
		void setvX(int nvx);
		void setvY(int nvy);
		
	private:
		int counter;
};

#endif
