#include "graphicsview.h"
#include <QKeyEvent>
#include <iostream>

using namespace std;

/* Constructor for a blue shell, sets velocity to 1  
		@param scene A QGraphicsScene that is passed to the QGraphicsView constuctor
		@param mario The main player that is passed to the item to allow for the moving of the mario
		@param p A Widget that can be used to pass in the MainWindow that is there for experimentation by Prof. Redekopp  **/

GraphicsView :: GraphicsView(QGraphicsScene* scene, Mario* mario, QWidget* p) : QGraphicsView(scene, p)
{
	mainPlayer = mario;
}
/* Default destructor **/
GraphicsView :: ~GraphicsView () {}

/* Handles the arrow key presses, sets the appririate velocity, picture and moves the Mario that was passed in to the constructor **/
void GraphicsView:: keyPressEvent(QKeyEvent *event)
{

	QGraphicsView:: keyPressEvent(event);
	
	switch(event->key())
	{
		case Qt::Key_Left:
			mainPlayer->setVel(-8,0);
			mainPlayer->setPic(4);
			mainPlayer->move_();
			break;
			
		case Qt::Key_Right:
			mainPlayer->setVel(8,0);
			mainPlayer->setPic(2);
			mainPlayer->move_();
			break;
			
		case Qt::Key_Up:
			mainPlayer->setVel(0,-8);
			mainPlayer->setPic(1);
			mainPlayer->move_();
			break;
			
		case Qt::Key_Down:
			mainPlayer->setVel(0,8);
			mainPlayer->setPic(3);
			mainPlayer->move_();
			break;
	}
	
}


