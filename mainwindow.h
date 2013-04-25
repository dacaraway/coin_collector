#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTextEdit>
#include <QWidget>
#include <QRadioButton>
#include <QListView>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QTimer>
#include <QMessageBox>
#include "mario.h"
#include "redshell.h"
#include "greenshell.h"
#include "coin.h"
#include "blueshell.h"
#include "greenmush.h"
#include <list>
#include "graphicsview.h"



class MainWindow : public QWidget 
{
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();
    void show();
    void die();
    void minusLife();
    void levelUp();
    void resetCoin();
    
private:
	 QGraphicsScene* scene;
	 GraphicsView* view;
	 QPushButton* menu;
	 QString namestring;
	 QGraphicsView* gameview;
   	 QGraphicsScene* gamescene;
   	 QTextEdit* name;
   	 QPushButton* start;
   	 QLabel* namelabel;
   	 Mario* mainPlayer;
   	 RedShell* redShell1;
   	 GreenShell* greenShell1;
   	 BlueShell* blueShell;
   	 GreenMush* greenMush;
   	 Coin* coin;
   	 QTimer* timer;
   	 list<Thing*> itemsList;
   	 QLabel* score1; 
   	 QLabel* lives1; 
   	 QLabel* level1;
   	 	
	QPixmap* greenShellPic;
	QPixmap* redShellPic;
	QPixmap* coinPic;
	QPixmap* blueShellPic;
	QPixmap* greenMushPic;

   	 //void keyPressEvent(QKeyEvent *event);
   	 int counter;
   	 int counter2;
   	 int counter3;
   	 int lives;
   	 int score;
   	 bool restart;
   	 int coinCounter;
   	 int level;
   	 bool mushOpen;


  

public slots:
	void menuFunc();
	void startGame();
	void quit();
	void handleTimer();
	void resetGame();
	void unpauseGame();

	
    
};

#endif
