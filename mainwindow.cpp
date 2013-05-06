#include "mainwindow.h"
#include <QLabel> 
#include <QButtonGroup>
#include <QApplication>
#include <QGridLayout>
#include <QTextEdit>
#include <iostream>
#include <QString>
#include <QTextStream>
#include <QTimer>
#include <sstream>
#include <QGraphicsPixmapItem>
#include <fstream>

using namespace std;
/* This slot is connected to the quit button and terminate the program */
void MainWindow:: quit()
{
	QApplication::quit();
}
/* This slot is connected to the directions button on the start screen and updates the startscene to show the directions page */
void MainWindow:: directions()
{
	// checking to see if name has been entered
	namestring = name->toPlainText();
	if(namestring == 0 || (namestring == "Please Enter a Valid Name") == true)
	{
		name->setText("Please Enter a Valid Name");
	}
	else
	{
		//creates directions screen
		start->hide();
		name->hide();
		namelabel->hide();
		prelogo->hide();
		
		QPixmap* directionsPic = new QPixmap("PNGpics/directions.png");

		QGraphicsPixmapItem* directions = new QGraphicsPixmapItem(*directionsPic);
	
		startscene->addItem(directions);
		directions->show();
		view->setFixedSize(1020,800);
		

		QPushButton* starter = new QPushButton("COMMENCE THE FUN");
		startscene->addWidget(starter);
		starter->move(400,700);
		
		
		connect(starter, SIGNAL(clicked()), this, SLOT(startGame()));	
	}
}
/* This slot is connected to the menu button and pauses the game and allows for a resetGame(), quit(), or unpauseGame() */
void MainWindow:: menuFunc()
{
	timer->stop();
	QMessageBox menuBox;
	menuBox.setText("Choose an option:");
	menuBox.setWindowTitle("Menu");
	QPushButton* unpause = menuBox.addButton("Resume", QMessageBox::ActionRole);
	QPushButton* restartButton = menuBox.addButton("Restart", QMessageBox::ActionRole);
	QPushButton* quitButton = menuBox.addButton("Quit", QMessageBox::ActionRole);


	connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
	connect(restartButton, SIGNAL(clicked()), this, SLOT(resetGame()));
	connect(unpause, SIGNAL(clicked()), this, SLOT(unpauseGame()));
	menuBox.exec();
}
/* This slot is connected to the resume button and starts the timer from the menu*/
void MainWindow :: unpauseGame()
{
	timer->start();
}
/* default destructor */
MainWindow:: ~MainWindow()
{

}
/* Constructor is responsible for creating the opening screen and has connections to the directions page */
MainWindow::MainWindow()  
{
	startscene = new QGraphicsScene();
	
	
	mainPlayer = new Mario(700, 300);
	view = new GraphicsView(startscene, mainPlayer, NULL);
	
	view->setFixedSize(800, 800 );
	
	

	QPixmap* logoPic = new QPixmap("PNGpics/prelogo.png");

	prelogo = new QGraphicsPixmapItem(*logoPic);
	
	startscene->addItem(prelogo);
	prelogo->setPos(100,100);
	prelogo->show();
	
	
	// creating button and text box to enter name 
	start = new QPushButton("Next");
	startscene->addWidget(start);
	start->show();
	start->move(200,430);
	
	name = new QTextEdit(" ");
	namelabel = new QLabel("Enter Your Name:");
	name->setFixedHeight(30);
	startscene->addWidget(name);
	startscene->addWidget(namelabel);
	
	name->show();
	name->move(120,400);
	namelabel->show();
	namelabel->move(190,375);

	restart = true;
	mushOpen = false;
	coinCounter = 0;
	//initializing shells that wont show until later
	greenShell2 = NULL;
	greenShell3 = NULL;
	
	connect(start, SIGNAL(clicked()), this, SLOT(directions()));
}

/* Is called when the player collides with the coin, re-randomizes the position of the coin  */
void MainWindow:: resetCoin()
{

	int cRandXR = rand() %870;
	int cRandYR = rand()%350 + 400;
	int x = mainPlayer->pixmap->pos().x();
	int y = mainPlayer->pixmap->pos().y();
	
	// putting distance between coin and player	
	if(cRandXR < x+5000 && cRandXR > x-5000 && cRandYR < y+5000 && cRandYR > y-5000)
	{
		if(cRandXR > x)
		{
			cRandXR += 300;

		}
		else if(cRandXR < x)
		{
			cRandXR -= 300;
		}
		if(cRandYR > y)
		{
			cRandYR += 200;

		}
		else if(cRandYR < y)
		{
			cRandYR -= 200;
		}
		if(cRandXR > 870)
		{
			cRandXR -= 700;
		}
		else if(cRandXR < -20)
		{
			cRandXR += 700;
		}
		if(cRandYR > 500)
		{
			cRandYR -= 500;
		}
		else if(cRandYR < 0)
		{
			cRandYR += 500;
		}
	}
	
	// resetting counter for blue shell path
	counter2 = 0;
	
	//setting new coin and blueshell positions
	coin-> setX(cRandXR);
	coin->setY(cRandYR);
	coin->setPos(cRandXR, cRandYR);

	
	blueShell->setPos(cRandXR - 80,cRandYR - 90);
	blueShell->setX(cRandXR - 80);
	blueShell->setY(cRandYR - 90);
	
	blueShell->setvX(1);
	blueShell->setvY(1);

	
	timer->start();
	
}

/* This slot is connected to the reset button but is also called in levelUp() and when a shell collision is made.  
This re-randomizes the position of the shells and coin and resets all variables if restart is true */
void MainWindow :: resetGame()
{
	timer->stop();

// restart is true when the retart button is pushed, not when a life is lost
	if(restart == true)
	{
	
		//resetting all back to original 
		lives = 3;
		score = 0;
		counter3 = 0;
		coinCounter = 0;
		level = 1;
		
		// setting player position
		mainPlayer->pixmap->setPos(700,300);
		mainPlayer->setX(700);
		mainPlayer->setY(300);
		mainPlayer->setPic(4);
		
		// setting shell original velocities
		redShell1 -> setDVelX(1.1);
		redShell1 -> setDVelY(1.1);
	
		greenShell1 -> setDVelX(3);
		greenShell1 -> setDVelY(3);
		
		// only delete it mush is on screen or else it gives error
		if(mushOpen == true)
		{
			gamescene->removeItem(greenMush);
			greenMush->setCheck(true);
			greenMush->setPos(-9999, -9999);
			mushOpen = false;
		}

		// removing big level green shells from list
		if(greenShell3)
		{
			itemsList.pop_back();
			gamescene->removeItem(greenShell3);
			greenShell3 = NULL;
		}
		if(greenShell2)
		{
			itemsList.pop_back();
			gamescene->removeItem(greenShell2);
			greenShell2 = NULL;
		}
		
	}
	
	// will be changed if the function calling needs restart to be false
	restart = true;
	
	
	//finding radnom numbers for all items
	int gsRandXR = rand()%500;
	int gsRandYR = rand()%300;
		
	int cRandXR = rand() %870;
	int cRandYR = rand()%350 + 400;
		
	int gRandXR = rand() %900;
	int gRandYR = rand()%550;
	
	int gsRandXR2 = rand() %500;
	int gsRandYR2 = rand()%300;
	
	int gsRandXR3 = rand() %500;
	int gsRandYR3 = rand()%300;
	
	int rRandXR = rand() %500;
	int rRandYR = rand()%300;

	// finsing x and y for the mario
	int x = mainPlayer->pixmap->pos().x();
	int y = mainPlayer->pixmap->pos().y();

	
	// putting distance between green shells and player
	
	if(gsRandXR < x+500 && gsRandXR > x-500 && gsRandYR < y+500 && gsRandYR > y-500)
	{
		if(gsRandXR > x)
		{
			gsRandXR += 100;

		}
		else if(gsRandXR < x)
		{
			gsRandXR -= 100;
		}
		if(gsRandYR > y)
		{
			gsRandYR += 100;

		}
		else if(gsRandYR < y)
		{
			gsRandYR -= 100;
		}

		if(gsRandXR > 870)
		{
			gsRandXR -= 500;
		}
		else if(gsRandXR < -20)
		{
			gsRandXR += 500;
		}
		if(gsRandYR > 500)
		{
			gsRandYR -= 500;
		}
		else if(gsRandYR < 0)
		{
			gsRandYR += 500;
		}
	}
		
	// distance for the 2nd green shell if exists
	if(greenShell2 && gsRandXR2 < x+500 && gsRandXR2 > x-500 && gsRandYR2 < y+500 && gsRandYR2 > y-500)
	{
		if(gsRandXR2 > x)
		{
			gsRandXR2 += 100;

		}
		else if(gsRandXR2 < x)
		{
			gsRandXR2 -= 100;
		}
		if(gsRandYR2 > y)
		{
			gsRandYR2 += 100;

		}
		else if(gsRandYR2 < y)
		{
			gsRandYR2 -= 100;
		}
		if(gsRandXR2 > 870)
		{
			gsRandXR2 -= 500;
		}
		else if(gsRandXR2 < -20)
		{
			gsRandXR2 += 500;
		}
		if(gsRandYR2 > 500)
		{
			gsRandYR2 -= 500;
		}
		else if(gsRandYR2 < 0)
		{
			gsRandYR2 += 500;
		}
	}
	
	// distance for the third green shell if exists
	if(greenShell3 && gsRandXR3 < x+500 && gsRandXR3 > x-500 && gsRandYR3 < y+500 && gsRandYR3 > y-500)
	{
		if(gsRandXR3 > x)
		{
			gsRandXR3 += 100;

		}
		else if(gsRandXR3 < x)
		{
			gsRandXR3 -= 100;
		}
		if(gsRandYR3 > y)
		{
			gsRandYR3 += 100;

		}
		else if(gsRandYR3 < y)
		{
			gsRandYR3 -= 100;
		}
		if(gsRandXR3 > 870)
		{
			gsRandXR3 -= 500;
		}
		else if(gsRandXR3 < -20)
		{
			gsRandXR3 += 500;
		}
		if(gsRandYR3 > 500)
		{
			gsRandYR3 -= 500;
		}
		else if(gsRandYR3 < 0)
		{
			gsRandYR3 += 500;
		}
	}

	// distance for the red shell
	if(rRandXR < x+700 && rRandXR > x-700 && rRandYR < y+700 && rRandYR > y-700)
	{
		if(rRandXR > x)
		{
			cRandXR += 100;

		}
		else if(rRandXR < x)
		{
			rRandXR -= 100;
		}
		if(rRandYR > y)
		{
			rRandYR += 100;

		}
		else if(rRandYR < y)
		{
			rRandYR -= 100;
		}
		if(rRandXR > 870)
		{
			rRandXR -= 500;
		}
		else if(rRandXR < -20)
		{
			rRandXR += 500;
		}
		if(rRandYR > 500)
		{
			rRandYR -= 500;
		}
		else if(rRandYR < 0)
		{
			rRandYR += 500;
		}
	}
		
	// distance between coin and player
	if(cRandXR < x+5000 && cRandXR > x-5000 && cRandYR < y+5000 && cRandYR > y-5000)
	{
		if(cRandXR > x)
		{
			cRandXR += 300;

		}
		else if(cRandXR < x)
		{
			cRandXR -= 300;
		}
		if(cRandYR > y)
		{
			cRandYR += 200;

		}
		else if(cRandYR < y)
		{
			cRandYR -= 200;
		}
		if(cRandXR > 870)
		{
			cRandXR -= 700;
		}
		else if(cRandXR < -20)
		{
			cRandXR += 700;
		}
		if(cRandYR > 500)
		{
			cRandYR -= 500;
		}
		else if(cRandYR < 0)
		{
			cRandYR += 500;
		}
	}
		
	
	// putting distance bewteen mush and player
	if(gRandXR < x+500 && gRandXR > x-500 && gRandYR < y+500 && gRandYR > y-500)
	{
		if(gRandXR > x)
		{
			gRandXR += 100;

		}
		else if(gRandXR < x)
		{
			gRandXR -= 100;
		}
		if(gRandYR > y)
		{
			gRandYR += 100;

		}
		else if(gRandYR < y)
		{
			gRandYR -= 100;
		}
		if(gRandXR > 870)
		{
			gRandXR -= 500;
		}
		else if(gRandXR < -20)
		{
			gRandXR += 500;
		}
		if(gRandYR > 500)
		{
			gRandYR -= 500;
		}
		else if(gRandYR < 0)
		{
			gRandYR += 500;
		}
	}
		
	
	
	counter= 0;
	counter2 = 0;

	// setting all positions and own variable to reflect rand numbers
	
	greenShell1->setPos(gsRandXR, gsRandYR);
	greenShell1->setX(gsRandXR);
	greenShell1->setY(gsRandYR);
	
	if(greenShell2)
	{
		greenShell2->setPos(gsRandXR2, gsRandYR2);
		greenShell2->setX(gsRandXR2);
		greenShell2->setY(gsRandYR2);
	}
	
	if(greenShell3)
	{
		greenShell2->setPos(gsRandXR3, gsRandYR3);
		greenShell2->setX(gsRandXR3);
		greenShell2->setY(gsRandYR3);
	}
	
	
	redShell1->setPos(rRandXR,rRandYR);
	redShell1->setX(rRandXR);
	redShell1->setY(rRandYR);
	
	coin->setPos(cRandXR, cRandYR);
	coin->setX(cRandXR);
	coin->setY(cRandYR);
	
	blueShell->setPos(cRandXR - 80,cRandYR - 90);
	
	blueShell->setX(cRandXR - 80);
	blueShell->setY(cRandYR - 90);
	
	blueShell->setvX(1);
	blueShell->setvY(1);

	
	timer->start();
	
}

/* This slot is connected to the start button and allocates memory for the game view and scene 
and creates the items and adds them to the scene as well as sets all variable and counters to origin */
void MainWindow::startGame()
{	
		// graphics scene and view created to show game sections
		view->setFixedSize(1200, 900 );
		gamescene= new QGraphicsScene();
		gameview = new QGraphicsView(gamescene);
		
		scene = new QGraphicsScene();
		view->setScene(scene);
		
		scene->clearFocus();
		
		view->setFocusPolicy(Qt :: StrongFocus);
		
		view->setFocus();
			
		gameview->setFixedSize(1000, 700 );
		gamescene->setSceneRect(0,0,950,650);
		
		//setting the background of the game
		backgroundPic1 = new QPixmap("PNGpics/background1.png");
		backgroundPic2 = new QPixmap("PNGpics/background2.png");
		backgroundPic3 = new QPixmap("PNGpics/background3.png");
		backgroundPic4 = new QPixmap("PNGpics/background4.png");
		
		QBrush* backgroundBrush1 = new QBrush(*backgroundPic1);
		
		gamescene->setBackgroundBrush(*backgroundBrush1);
			
		QGridLayout* layout = new QGridLayout();
		view->setLayout(layout);
		layout->addWidget(gameview, 2, 0, 10,5);

		// set texts to start
		lives = 3;
		level = 1;
		score = 0;

	
		QPixmap* logoPic = new QPixmap("PNGpics/logo.png");
		QLabel* logo = new QLabel();
		logo->setPixmap(*logoPic);
		layout->addWidget(logo, 0, 1 , Qt::AlignHCenter);
		
		// menu button
		menu = new QPushButton("Menu  //  Pause");
		layout->addWidget(menu, 6, 10 , 1, 3, Qt::AlignHCenter);
		
		//cheat button
		QPushButton* cheat = new QPushButton("Cheat // Level Up");
		layout->addWidget(cheat, 7, 10 , 1, 3, Qt::AlignHCenter);

		QString name2("Name: ");
		name2.append(namestring);

		QLabel* name1 = new QLabel(name2);
		layout->addWidget(name1, 2, 10, 1, 3 , Qt::AlignHCenter);
		
		//setting original score
		stringstream ss;
		ss<< score;
		
		string str = ss.str();
		const char* cstr = str.c_str();
		
		QString score2("Score: ");
		score2.append(cstr);
		
		score1 = new QLabel(score2);
		layout->addWidget(score1, 4, 10 , 1 , 3, Qt::AlignHCenter);
		
		//setting original lives
		stringstream ss1;
		ss1<< lives;
		
		string str1 = ss1.str();
		const char* cstr1 = str1.c_str();
		
		QString lives2("Lives: ");
		lives2.append(cstr1);
		
		lives1 = new QLabel(lives2);
		layout->addWidget(lives1, 5, 10 , 1 , 3, Qt::AlignHCenter);
		
		//setting original level
		stringstream ss2;
		ss2<< level;
		
		string str2 = ss2.str();
		const char* cstr2 = str2.c_str();
		
		QString level2("Level: ");
		level2.append(cstr2);
		
		level1 = new QLabel(level2);
		layout->addWidget(level1, 3, 10 , 1 , 3, Qt::AlignHCenter);
		
		// all pixmaps are created here
		greenShellPic = new QPixmap("PNGpics/greenshell.png");
		redShellPic = new QPixmap("PNGpics/redshell.png");
		coinPic = new QPixmap("PNGpics/coin.png");
		blueShellPic = new QPixmap("PNGpics/blueshell.png");
		greenMushPic = new QPixmap("PNGpics/greenmushroom.png");

		counter = 0;
		counter2 = 0;
		counter3 = 0;	

		gamescene->clear();


		// finding original random locations
		int gsRandX = rand()%900;
		int gsRandY = rand()%600;
		
		int cRandX = rand() %900;
		int cRandY = rand()%600;
		
		int gRandX = rand() %900;
		int gRandY = rand()%600;

		// putting distance between shell and player
		while(gsRandX < 900 && gsRandX > 500 && gsRandY < 500 && gsRandY > 50)
		{
			gsRandX = rand()%900;
			gsRandY = rand()%600;
		}
		
		// putting distance between coin and player
		while(cRandX < 900 && cRandX > 500 && cRandY < 500 && cRandY > 50)
		{
			cRandX = rand()%900;
			cRandY = rand()%600;
		}
		
		// putting distance bewteen mush and player
		while(gRandX < 900 && gRandX > 500 && gRandY < 500 && gRandY > 50)
		{
			gRandX = rand()%900;
			gRandY = rand()%600;
		}
		
		
		// items created
		redShell1 = new RedShell(redShellPic, 80, 400);
		greenShell1 = new GreenShell(greenShellPic, gsRandX, gsRandY);
		coin = new Coin(coinPic, cRandX, cRandY);
		blueShell = new BlueShell(blueShellPic,cRandX - 80,cRandY - 90);
		greenMush = new GreenMush(greenMushPic,-9999 , -9999);
		
		// adding items to collisions list
		itemsList.push_back(redShell1);
		itemsList.push_back(greenShell1);
		itemsList.push_back(coin);
		itemsList.push_back(blueShell);		
		itemsList.push_back(greenMush);		

		// adding items to scene
		gamescene->addItem(mainPlayer->pixmap); 
		gamescene->addItem(redShell1);
		gamescene->addItem(greenShell1);
		gamescene->addItem(coin);
		gamescene->addItem(blueShell);

	
    	timer = new QTimer(this);
    	timer->setInterval(50);
		timer->start();

		connect(cheat, SIGNAL(clicked()), this, SLOT(levelUp()));
		connect(menu, SIGNAL(clicked()), this, SLOT(menuFunc()));
    	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));


}

/* This slot is connected to timer timeout() signal and calls the move() function for every item.  
It handles the collisions of the items with the layer and calls the appropriate action functions. */
void MainWindow:: handleTimer()
{
	gameview->setFocusPolicy(Qt:: NoFocus);

	// creating string for score
	stringstream ss;
	ss<< score;
		
	string str = ss.str();
	const char* cstr = str.c_str();
		
	QString score2("Score: ");
	score2.append(cstr);
	
	score1->setText(score2);
		
		
	// creating string for lives
	
	stringstream ss1;
	ss1<< lives;
		
	string str1 = ss1.str();
	const char* cstr1 = str1.c_str();
		
	QString lives2("Lives: ");
	lives2.append(cstr1);
	
	lives1->setText(lives2);
	
	// creating string for level
	
	stringstream ss2;
	ss2<< level;
		
	string str2 = ss2.str();
	const char* cstr2 = str2.c_str();
		
	QString level2("Level: ");
	level2.append(cstr2);
	
	level1->setText(level2);

	
		
	counter++;
	counter2++;
	counter3++;
	
	// coin bouncing cycle
	if(counter == 40)
	{
		counter = 0;
	}
	
	// blueshell cycle
	if(counter2 == 600)
	{
		counter2 = 0;
	}
	
	// greenmush cycle
	if(counter3% 200 == 0)
	{

		if(greenMush->getCheck() == true && mushOpen == false)
		{
			int gRandX = rand() %900;
			int gRandY = rand()%600;
			
			greenMush->setCheck(true);
			mushOpen = true;
			
			greenMush->setPos(gRandX, gRandY);
			gamescene->addItem(greenMush);
		}
	}

	// calling all items to move
	redShell1->move(mainPlayer->pixmap->pos());
	greenShell1->move();
	
	if(greenShell2)
	{
		greenShell2->move();
	}
		if(greenShell3)
	{
		greenShell3->move();
	}

	blueShell->setCounter(counter2);
	blueShell->move();
	coin->setCounter(counter);
	coin->move();
	
	// iterating through list to find colisions
	list<Thing*>:: iterator it = itemsList.begin();
	for(it = itemsList.begin(); it!= itemsList.end(); ++it)
	{
		if(mainPlayer->pixmap->collidesWithItem(*it))
		{			
			int obj = (*it)->executePower();
			{
				// shells collison
				if(obj == 1)
				{
					timer->stop();
					// dies if no more lives available
					if(lives == 1)
					{
						die();
						break;
					}
					// takes away life else
					else
					{
						minusLife();
						break;
					}
				}
				// blue shell collision. kills player
				if(obj == 2)
				{
					timer->stop();
					die();
					break;
				}
				// coin colision, score updated, coin moved.  Levels up if coin counter is 3
				if(obj == 3)
				{
					timer->stop();
					coinCounter++;
					score += (100 * level);
					resetCoin();
					if(coinCounter % 3 == 0)
					{
						score += 500;
						levelUp();
						break;
					}
					break;
				}
				// mushroom collision adds life, removes from scene // only entered if the mushroom has not alread been deleted fset
				if(obj == 4 && greenMush->getCheck() == true)
				{
					timer->stop();
					
					gamescene->removeItem(greenMush);
					greenMush->setCheck(true);
					greenMush->setPos(-9999, -9999);
					lives++;
						
					mushOpen = false;
						
					timer->start();
					break;
				}
			
			}
		}
	}
}
 /* Is called when there are no more lives left or the player collides with the blueshell. 
 Ends the game with a QMessgae box showing the score and an option to restart or quit */
void MainWindow:: die()
{
		--lives;
		// starting string to show in message box
		stringstream ss1;
		ss1<< lives;
		
		string str1 = ss1.str();
		const char* cstr1 = str1.c_str();
		
		QString lives2("Lives: ");
		lives2.append(cstr1);
	
		lives1->setText(lives2);
		
		string hsList[10];
		
		ifstream text("highscores.txt");
		
		if(text)
		{
			for(int i=0; i<10; i++)
			{
				string name1;
				text >> name1;
				int score1;
				text >> score1;
			
				stringstream total;
				total << name1 << " " << score1;
			
				string final = total.str();
			
				hsList[i] = final;
			}
			text.close();
		}
		
		else
		{
			for(int i=0; i<10; i++)
			{
				stringstream num;
				
				string name3 = "NONE";
				
				num << name3 << " " << 0;
				string final;
				
				final = num.str();
				
				hsList[i] = final;
				
			}
		}
		
		
		for(int i=0; i<10; i++)
		{
			string snew = hsList[i];
			stringstream ss(snew);
			
			string name;
			ss >> name;
			int scoreR;
			
			ss >> scoreR;
			
			if(score > scoreR)
			{
				string cName;
				cName = namestring.toStdString();
				
				for(int j=9; j>=i+1; j--)
				{
					hsList[j] = hsList[j-1];
				} 
				
				string name = cName;
				
				stringstream total;
				total << cName << " " << score;
			
				string final = total.str();
			
				hsList[i] = final; 
				
				break;

			}
		
		}
		
		ofstream outText("highscores.txt");

			for(int i=0; i<10; i++)
			{
				string string = hsList[i];
				
				outText << string << " ";
			}
			
			outText.close();
		
		// message box for losing
		QMessageBox losebox;
		
		stringstream ss;
		ss << score;
		string str = ss.str();
		
		ifstream text1("highscores.txt");
		
		stringstream ss2;
		for(int i=0; i<10; i++)
		{
			string string1;
			string string2;
			text1 >> string1;
			text1 >> string2;
			
			
			ss2 << string1 << " " << string2 << "\n" << endl;
			
		}
		
		str = "GAME OVER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n  	  Score: " +str;
	
		str += "\n \n \n                   High Scores:";
		
		str += "\n \n";
		
		string str2 = ss2.str();
		str += str2;
		const char* cstr = str.c_str();

		// buttons for box
		losebox.setText(cstr);
		losebox.setWindowTitle("Play Again");
		QPushButton* quitButton = losebox.addButton("Quit", QMessageBox::ActionRole);
		QPushButton* restartButton = losebox.addButton("Restart", QMessageBox::ActionRole);

		connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
		connect(restartButton, SIGNAL(clicked()), this, SLOT(resetGame()));
		losebox.exec();
}
/*
void MainWindow:: keyPressEvent(QKeyEvent *event)
{	
	cout << "key found" << endl;
	
	QWidget :: keyPressEvent(event);
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
*/


/*  Is called when a shell collides with the player.  It takes away a life from the player and calls resetGame() */
void MainWindow:: minusLife()
{
	--lives;
	score -= 50;
	restart = false;
	resetGame();
}

/* This slot is called when 3 coins have been collected and is connected to cheat, 
it calls resetGame() with reset set to false, and increases the volocity of the shells 
as well as increasing the level variable. */
void MainWindow :: levelUp()
{
	timer->stop();
	
	int modL;
			level++;
	modL= level%4;

	
	switch(modL)
	{
		case 1:
		{
			QBrush* backgroundBrush1 = new QBrush(*backgroundPic1);
		
			gamescene->setBackgroundBrush(*backgroundBrush1);
			break;
		}
		case 2:
		{
			QBrush* backgroundBrush2 = new QBrush(*backgroundPic2);
		
			gamescene->setBackgroundBrush(*backgroundBrush2);
			break;
		}
		case 3:
		{
			QBrush* backgroundBrush3 = new QBrush(*backgroundPic3);
		
			gamescene->setBackgroundBrush(*backgroundBrush3);
			break;
		}
		case 0:
		{
			QBrush* backgroundBrush4 = new QBrush(*backgroundPic4);
		
			gamescene->setBackgroundBrush(*backgroundBrush4);
			break;
		}
		
	}
	
	
	
	// shells get faster
	redShell1 -> setVelX(redShell1->getVelX() + .1);
	redShell1 -> setVelY(redShell1->getVelY() + .1);
	
	greenShell1 -> setVelX(greenShell1->getVelX() + .5);
	greenShell1 -> setVelY(greenShell1->getVelY() + .5);
	restart = false;
	
	coinCounter = 0;
	

	
	if(greenShell2)
	{
		greenShell2 -> setVelX(greenShell2->getVelX() + 1);
		greenShell2 -> setVelY(greenShell2->getVelY() + 1);
	}
	
	if(greenShell3)
	{
		greenShell3 -> setVelX(greenShell3->getVelX() + 1);
		greenShell3 -> setVelY(greenShell3->getVelY() + 1);
	}
	// shells added if reach level 3 or 6
	if(level == 4)
	{
		greenShell1->setDVelX(3);
		greenShell1->setDVelY(3);
		
		redShell1->setDVelX(1.1);
		redShell1->setDVelY(1.1);
		
		int gsRandX = rand() %900;
		int gsRandY = rand()%600;
		int x = mainPlayer->pixmap->pos().x();
		int y = mainPlayer->pixmap->pos().y();

		// putting distance between shell and player
		if(gsRandX < x+500 && gsRandX > x-500 && gsRandY < y+500 && gsRandY > y-500)
		{
			if(gsRandX > x)
			{
				gsRandX += 100;

			}
			else if(gsRandX < x)
			{
				gsRandX -= 100;
			}
			if(gsRandY > y)
			{
				gsRandY+= 100;

			}
			else if(gsRandY < y)
			{
				gsRandY -= 100;
			}
	
			if(gsRandX > 870)
			{
				gsRandX-= 500;
			}
			else if(gsRandX < -20)
			{
				gsRandX += 500;
			}
			if(gsRandY > 500)
			{
				gsRandY -= 500;
			}
			else if(gsRandY < 0)
			{
				gsRandY += 500;
			}
		}
		
			
		greenShell2 = new GreenShell(greenShellPic,gsRandX, gsRandY); 
		greenShell2 -> setDVelX(greenShell1->getVelX());
		greenShell2 -> setDVelY(greenShell1->getVelY());
		gamescene->addItem(greenShell2);
		itemsList.push_back(greenShell2);
	}
	
	if(level == 8)
	{
		greenShell1->setDVelX(3);
		greenShell1->setDVelY(3);
		
		greenShell2->setDVelX(3);
		greenShell2->setDVelY(3);
		
		
		redShell1->setDVelX(1.1);
		redShell1->setDVelY(1.1);
		
		int gsRandX = rand() %900;
		int gsRandY = rand()%600;
		int x = mainPlayer->pixmap->pos().x();
		int y = mainPlayer->pixmap->pos().y();

		// putting distance between shell and player
		if(gsRandX < x+500 && gsRandX > x-500 && gsRandY < y+500 && gsRandY > y-500)
		{
			if(gsRandX > x)
			{
				gsRandX += 100;

			}
			else if(gsRandX < x)
			{
				gsRandX -= 100;
			}
			if(gsRandY > y)
			{
				gsRandY+= 100;

			}
			else if(gsRandY < y)
			{
				gsRandY -= 100;
			}

			if(gsRandX > 870)
			{
				gsRandX-= 500;
			}
			else if(gsRandX < -20)
			{
				gsRandX += 500;
			}
			if(gsRandY > 500)
			{
				gsRandY -= 500;
			}
			else if(gsRandY < 0)
			{
				gsRandY += 500;
			}	
		}
		
		greenShell3 = new GreenShell(greenShellPic,gsRandX, gsRandY); 
		greenShell3 -> setDVelX(greenShell1->getVelX());
		greenShell3 -> setDVelY(greenShell1->getVelY());
		gamescene->addItem(greenShell3);
		itemsList.push_back(greenShell3);

	}
	// resets game for new level
	resetGame();
	
}
 /* Is called when there are no more lives left or the player collides with the blueshell. 
 Ends the game with a QMessgae box showing the score and an option to restart or quit */
void MainWindow::show() 
{
    view->show();
}
	
