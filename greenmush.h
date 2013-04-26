#ifndef GREEN_MUSH_H
#define GREEN_MUSH_H
#include "thing.h"

class GreenMush: public Thing
{
	public:
		GreenMush(QPixmap *pm, int nx, int ny);
		~GreenMush();
		void move();
		int executePower();
		void setX(int nx);
		void setY(int ny);
		void setCheck(bool checker);
		bool getCheck();

		
	private:
		bool goodCheck;
};
#endif
