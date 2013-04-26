#ifndef COIN_H
#define COIN_H
#include "thing.h"

class Coin: public Thing
{
	public:
		Coin(QPixmap *pm, int nx, int ny);
		~Coin();
		void move();
		int executePower();
		void setCounter(int counter1);
		void setX(int nx);
		void setY(int ny);
		
	private:
		int counter;
};

#endif
