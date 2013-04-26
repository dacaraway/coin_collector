#ifndef GRAPHICS_VIEW_H
#define MGRAPHICS_VIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "mario.h"

class GraphicsView: public QGraphicsView
{
	public: 
		GraphicsView(QGraphicsScene* scene, Mario* mario, QWidget* p);
		~GraphicsView();
		void keyPressEvent(QKeyEvent *event);
	private:
		Mario* mainPlayer;
};

#endif
