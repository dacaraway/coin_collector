#ifndef MARIO_H
#define MARIO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QLabel>



/** The Mario class holds all the members for the main player which can move around the screen to collect the coin
@author Daria Caraway
 */
class Mario
{
	public:
	/** Constructor for a Mario, sets velocity to 0 and the original pixmap to left picture.  Also declares all the the pictures for the different directions.  
		@param nx Initial x cooridinate to set position
		@param ny Initial y coordinate to set poition  **/
		Mario(int nx, int ny);
		/** Default destructor **/
		~Mario();
		/** Moves mario the given veolicty based on keyPressEvent() in the GraphicsView class, sets the bounds for the screen so Mario cannot go off **/
		void move_();
		/** Sets the vX and vY variable of the item, used for velocity
		@param tx the int to be set for vX 
		@param ty the int to be set for vY **/
		void setVel(int tx, int ty);
		/** Sets the pixmap based on keyPressEvent() in the GraphicsView class
		@param number The number passed by the key presses to pick through the swtich**/
		void setPic(int number);
		/**The Pixmap item that shows on the screen **/
		QGraphicsPixmapItem* pixmap;
		/** Sets the X variable of the item
		@param nx An int passed into from MainWindow **/
		void setX(int nx);
		/** Sets the Y variable of the item
		@param ny An int passed into from MainWindow **/
		void setY(int ny);

		
	private:
		/** The current x coordinate of the object **/
		int x;
		/** The current y coordinate of the object **/
		int y;
		/** The current x velocity of the object **/
		int vX;
		/** The current y coordinate of the object **/
		int vY;
		
		/** The picture shown when morio moves up or down **/
		QPixmap* upMarioPic;
		/** The picture shown when morio moves right **/
		QPixmap* rightMarioPic;
		/** The picture shown when morio moves left **/
		QPixmap* leftMarioPic;

		
};


#endif
