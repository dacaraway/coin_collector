#ifndef GREEN_MUSH_H
#define GREEN_MUSH_H
#include "thing.h"

/** The GreenMush class hold all the members for the green mushroom item which appears at a certain timer interval and adds a life when retrieved.
@author Daria Caraway

@pre Thing */

class GreenMush: public Thing
{
	public:
		/** Constructor for a green mushroom sets velocity to 0, sets the check off status to true 
		@param pm Pixmap pointer to show picture
		@param nx Initial x cooridinate to set position
		@param ny Initial y coordinate to set poition  **/
		GreenMush(QPixmap *pm, int nx, int ny);
		/** Default destructor **/
		~GreenMush();
		/** The green mushroom does not implement a move function, but derives from class thing which as a pure virtual move function **/
		void move();
		/** @return 4-- tells switch in MainWindow to execute mushroom collision  **/
		int executePower();
		/** Sets the check off status for the mushroom, this is needed because when the mushroom is deleted the checker is set to false, so the mushroom is not deleted more that once off the scene.
		@param checker the checker that is inside the MainWindow **/
		void setCheck(bool checker);
		/** Sets the X variable of the item
		@return A boolean for the state of the checker **/
		bool getCheck();


		
	private:
		/** Boolean that helps make sure the mushroom does not get removed from the scene more that once **/
		bool goodCheck;
};
#endif
