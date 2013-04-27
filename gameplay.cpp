#include <QtGui/QApplication>
#include "mainwindow.h"

using namespace std;


/** @mainpage CSCI 102 PA 4 by Daria Caraway
*Submitted April 12th 2013


@section purpose Purpose/verview

	The purpose of this program is create a fun game in which the user can use the arrow keys to move Mario to an obective, the coin.  When Mario reaces the coin, it will move to naother random location.
	There are three shells that arrive on the screen.  The blue spiked shells guards the coin in a square path and kills on impact.  The green shell bounces around the frame and takes away a life,
	as does the red shell which follows the user.  Every three coins a new level will be reached and the game will speed up, on the 4th and 8th level a new green shell will be added, and the shells
	will slow down, but after the 8th level the shells always speed up.  The green mushroom appears after a 200 timer interval and gives an extra life to the user.
	
	
	
@section requirements Requirements for the game

	The requirements for this game were that it was to have five moving things, mine being : the green shell, the red shell, the blue shell, the mushroom, and the coin.  The game was also to have levels and lives.
	Every level the game is to speed up, eventually making it impossible to avoid that shells.  The game must take in use input and allow the player to play, mine allows for 
	arrow key presses.  Lastly, the game is to have a std list that checks for collisions between the objects.
	
	The last requirement is for the player to HAVE FUNNN!!!!! 
	
	**/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
