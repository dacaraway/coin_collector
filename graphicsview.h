#ifndef GRAPHICS_VIEW_H
#define MGRAPHICS_VIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "mario.h"

/** The GraphicsView class inherits from QGraphics view and exists solely to steal the focus and handle the key press events */

class GraphicsView: public QGraphicsView
{
	public: 
	/** Constructor for a blue shell, sets velocity to 1  
		@param scene A QGraphicsScene that is passed to the QGraphicsView constuctor
		@param mario The main player that is passed to the item to allow for the moving of the mario
		@param p A Widget that can be used to pass in the MainWindow that is there for experimentation by Prof. Redekopp  **/
		GraphicsView(QGraphicsScene* scene, Mario* mario, QWidget* p);
		/**Default destructor **/
		~GraphicsView();
		/** Handles the arrow key presses, sets the appririate velocity, picture and moves the Mario that was passed in to the constructor **/
		void keyPressEvent(QKeyEvent *event);
	private:
		/** A Mario pointer that is set equal to the Mario passed into the constructor to move him on the screen, used in keyPressEvent()   **/
		Mario* mainPlayer;
};

#endif
