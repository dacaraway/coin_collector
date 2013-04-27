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

/** The MainWindow class that is responsible for creating the entire screen of the game, dealing with every collion and 
keeping track of every item.

@author Daria Caraway */

class MainWindow : public QWidget 
{
    Q_OBJECT
    
public:
	 /** Constructor is responsible for creating the opening screen and has connections to the directions page */
    explicit MainWindow();
     /** default destructor */
    ~MainWindow();
    /**  Allows the window to be shown when called from main */
    void show();
    /** Is called when there are no more lives left or the player collides with the blueshell. Ends the game with a QMessgae box showing the score and an option to restart or quit */
    void die();
    /**  Is called when a shell collides with the player.  It takes away a life from the player and calls resetGame() */
    void minusLife();
    /** Is called when the player collides with the coin, re-randomizes the position of the coin  */
    void resetCoin();
    
private:
	/**  The main GraphicsScene that holds all widgets and scenes which is allocated in startGame() */
	 QGraphicsScene* scene;
	 /** The main GraphicsView of my own class GraphicsView which is allocated in the constructor */
	 GraphicsView* view;
	 /**  The GraphicsScene for the start screen where the name is entered which is allocated in the constructor */
	 QGraphicsScene* startscene;
	 /**  The push button that calles menu() which is allocated in startGame() */
	 QPushButton* menu;
	 /**  The string that is read in from the text box which is allocated in the constructor */
	 QString namestring;
	 /** The secondary view that holds the scene for the game box */
	 QGraphicsView* gameview;
	 /** The secondary scene that holds all the game play items */
   	 QGraphicsScene* gamescene;
   	 /** The item that holds the opening screen logo */
   	 QGraphicsPixmapItem* prelogo;
   	 /** The text box where the player enters his/her name which is allocated in the constructor */
   	 QTextEdit* name;
   	 /**  The push button that calles startGame() which is allocated in the directions() */
   	 QPushButton* start;
   	 /**  The label that labels the name */
   	 QLabel* namelabel;
   	 /**  The main player which is from the Mario class allocated in startGame() */
   	 Mario* mainPlayer;
   	 /**  The red shell that follows the mario, allocated in startGame()*/
   	 RedShell* redShell1;
   	 /**  The first green shell that is allocated in startGame() */
   	 GreenShell* greenShell1;
   	 /**  The second green shell that is added when the level reaches 4, allocated in levelUp() */
   	 GreenShell* greenShell2;
   	 /**  The third green shell that is added when the level reaches 8, allocated in levelUp() */
   	 GreenShell* greenShell3;
   	 /**  The blue shell that guards the coin allocated in startGame() */
   	 BlueShell* blueShell;
   	 /**  The mushroom that adds a life allocated in startGame() */
   	 GreenMush* greenMush;
   	 /**  The coin that is to be retrived, allocated in startGame() */
   	 Coin* coin;
   	 /**  The timer that is used to signal handleTimer() */
   	 QTimer* timer;
   	 /**  The list of all things that inherit from type Thing, is used to detect collisions on the screen */
   	 list<Thing*> itemsList;
   	 /**  The label for the score */
   	 QLabel* score1; 
   	 /**  The label for the number of lives left */
   	 QLabel* lives1; 
   	 /**  The label for the surrent level */
   	 QLabel* level1;
   	 /**  The picture for the green shell */	
	 QPixmap* greenShellPic;
	  /**  The picture for the red shell */
	 QPixmap* redShellPic;
	  /**  The picture for the coin */
	 QPixmap* coinPic;
	  /**  The picture for the blue shell */
	 QPixmap* blueShellPic;
	  /**  The picture for the green mushroom */
	 QPixmap* greenMushPic;

   	 //void keyPressEvent(QKeyEvent *event);
   	  /**  The counter to time the coin bounces */
   	 int counter;
   	  /**  The counter to time the blue shell square movement */
   	 int counter2;
   	  /**  The counter to time the green mushroom appearences */
   	 int counter3;
   	  /**  The variable to hold the number of lives */
   	 int lives;
   	  /**  The variable to hold the score */
   	 int score;
   	  /**  A boolean variable that is set to true when the whole game needs to be reset in resetGame() to clear the score and reset lives, and set to false when the player has just collided with a shell and the whole game doesn't need to be reset in resetGame() just the items. */
   	 bool restart;
   	  /**  The counter that keeps track of the coins to add shells when 4 or 8 are collected in levelUp() */
   	 int coinCounter;
   	 /**  The variable to hold the current level */
   	 int level;
   	 /**  A boolean to help prevent double deletion of the shell from the scene, set to true when the mushroom is on the screen */
   	 bool mushOpen;

public slots:
	/** This slot is connected to the menu button and pauses the game and allows for a resetGame() with restart as true, quit(), or unpauseGame() */
	void menuFunc();
	/** This slot is connected to the start button and allocates memory for the game view and scene and creates the items and adds them to the scene as well as sets all variable and counters to origin */
	void startGame();
	/** This slot is connected to the quit button and terminate the program */
	void quit();
	/** This slot is connected to timer timeout() signal and calls the move() function for every item.  It handles the collisions of the items with the layer and calls the appropriate action functions. */
	void handleTimer();
	/** This slot is connected to the reset button but is also called in levelUp() and when a shell collision is made.  This re-randomizes the position of the shells and coin and resets all variables if restart is true */
	void resetGame();
	/** This slot is connected to the resume button and starts the timer from the menu*/
	void unpauseGame();
	/** This slot is called when 3 coins have been collected and is connected to cheat, it calls resetGame() with reset set to false, and increases the volocity of the shells as well as increasing the level variable. */
    void levelUp();
    /** This slot is connected to the directions button on the start screen and updates the startscene to show the directions page */
    void directions();
	
    
};

#endif
