#include "graphicsview.h"
#include <QKeyEvent>
#include <iostream>

using namespace std;

GraphicsView :: GraphicsView(QGraphicsScene* scene, Mario* mario, QWidget* p) : QGraphicsView(scene, p)
{
	mainPlayer = mario;
}

GraphicsView :: ~GraphicsView () {}

void GraphicsView:: keyPressEvent(QKeyEvent *event)
{
	//cout << "hi" << endl;
	QGraphicsView:: keyPressEvent(event);
	
	switch(event->key())
	{
		case Qt::Key_Left:
			mainPlayer->setVel(-8,0);
			mainPlayer->setPic(4);
			mainPlayer->move_();
			mainPlayer->setPrevDirec(4);
			break;
			
		case Qt::Key_Right:
			mainPlayer->setVel(8,0);
			mainPlayer->setPic(2);
			mainPlayer->move_();
			mainPlayer->setPrevDirec(2);
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


