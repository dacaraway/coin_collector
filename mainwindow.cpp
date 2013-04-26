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

using namespace std;

void MainWindow:: quit()
{
	QApplication::quit();
}

void MainWindow:: directions()
{

	namestring = name->toPlainText();
	if(namestring == 0 || (namestring == "Please Enter a Valid Name") == true)
	{
		name->setText("Please Enter a Valid Name");
	}
	else
	{
		start->hide();
		name->hide();
		namelabel->hide();
		
		QLabel* directionsLabel = new QLabel("Gameplay: Use the keyboard arrows to move around the screen to try to get the coin! \n \n But be careful, the shells are dangerous, expecially the blue one. \n Be sure to grab the green mushroom when it appears, and you will recieve an extra life!!\n \n Hint: For grading purposes only, a cheat button is supplied to clearly demonstrate leveling up,\n otherwise, 3 coins achieves a new level.");
		QPushButton* starter = new QPushButton("COMMENCE THE FUN");
		startscene->addWidget(starter);
		prelogo->setPos(50,175);
		starter->move(250,150);
		startscene->addWidget(directionsLabel);
		directionsLabel->move(45,0);
		
		
		connect(starter, SIGNAL(clicked()), this, SLOT(startGame()));	
	}
}

void MainWindow:: menuFunc()
{
	timer->stop();
	QMessageBox menuBox;
	menuBox.setText("Choose an option:");
	menuBox.setWindowTitle("Menu");
	QPushButton* unpause = menuBox.addButton("UnPause", QMessageBox::ActionRole);
	QPushButton* restartButton = menuBox.addButton("Restart", QMessageBox::ActionRole);
	QPushButton* quitButton = menuBox.addButton("Quit", QMessageBox::ActionRole);


	connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
	connect(restartButton, SIGNAL(clicked()), this, SLOT(resetGame()));
	connect(unpause, SIGNAL(clicked()), this, SLOT(unpauseGame()));
	menuBox.exec();
}

void MainWindow :: unpauseGame()
{
	timer->start();
}

MainWindow:: ~MainWindow()
{

}
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
	
	
	
	start = new QPushButton("Directions");
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
	
	//greenShell2 = NULL;
	//greenShell3 = NULL;
	
	connect(start, SIGNAL(clicked()), this, SLOT(directions()));
}


void MainWindow:: resetCoin()
{
	
	int cRandXR = rand() %900;
	int cRandYR = rand()%450 + 100;
	int x = mainPlayer->pixmap->pos().x();
	int y = mainPlayer->pixmap->pos().y();
	
	// putting distance between coin and player
	while(cRandXR < x+500 && cRandXR > x-500 && cRandYR < y+500 && cRandYR > y-500)
	{
		cRandXR = rand()%900;
		cRandYR = rand()%550;
	}
		
	
	counter2 = 0;
	
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
void MainWindow :: resetGame()
{
	//timer->stop();

	int gsRandXR = rand()%900;
	int gsRandYR = rand()%550;
		
	int cRandXR = rand() %900;
	int cRandYR = rand()%450 + 100;
		
	int gRandXR = rand() %900;
	int gRandYR = rand()%550;
	/*
	int gsRandXR2 = rand() %900;
	int gsRandYR2 = rand()%550;
	
	int gsRandXR3 = rand() %900;
	int gsRandYR3 = rand()%550;
	*/
	
	int rRandXR = rand() %900;
	int rRandYR = rand()%550;

	
	int x = mainPlayer->pixmap->pos().x();
	int y = mainPlayer->pixmap->pos().y();
	
	// putting distance between green shell and player
	while(gsRandXR < x+500 && gsRandXR > x-500 && gsRandYR < y+500 && gsRandYR > y-500)
	{
		gsRandXR = rand()%900;
		gsRandYR = rand()%550;
	}
	/*
	// putting distance between green shell and player
	while(gsRandXR2 < x+500 && gsRandXR2 > x-500 && gsRandYR2 < y+500 && gsRandYR2 > y-500)
	{
		gsRandXR2 = rand()%900;
		gsRandYR2 = rand()%550;
	}
	
	// putting distance between green shell and player
	while(gsRandXR3 < x+500 && gsRandXR3 > x-500 && gsRandYR3 < y+500 && gsRandYR3 > y-500)
	{
		gsRandXR3 = rand()%900;
		gsRandYR3 = rand()%550;
	}
	*/
	// putting distance between red shell and player
	while(rRandXR < x+500 && rRandXR > x-500 && rRandYR < y+500 && rRandYR > y-500)
	{
		rRandXR = rand()%900;
		rRandYR = rand()%550;
	}
		
	// putting distance between coin and player
	while(cRandXR < x+500 && cRandXR > x-500 && cRandYR < y+500 && cRandYR > y-500)
	{
		cRandXR = rand()%900;
		cRandYR = rand()%550;
	}
		
	// putting distance bewteen mush and player
	while(gRandXR < x+500 && gRandXR > x-500 && gRandYR < y+500 && gRandYR > y-500)
	{
		gRandXR = rand()%900;
		gRandYR = rand()%550;
	}
	
	if(restart == true)
	{
		lives = 3;
		score = 0;
		counter3 = 0;
		coinCounter = 0;
		level = 1;

		mainPlayer->pixmap->setPos(700,300);
		mainPlayer->setX(700);
		mainPlayer->setY(300);
		mainPlayer->setPic(4);
		
		
		redShell1 -> setDVelX(1.1);
		redShell1 -> setDVelY(1.1);
	
		greenShell1 -> setDVelX(5);
		greenShell1 -> setDVelY(5);

		
		if(mushOpen == true)
		{
			gamescene->removeItem(greenMush);
			greenMush->setCheck(true);
			greenMush->setPos(-9999, -9999);
			mushOpen = false;
		}
		
		/*
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
			greenShell3 = NULL;
		}
		*/
	}
	
	restart = true;
	
	counter= 0;
	counter2 = 0;
	//counter3 = 0;
	

	
	//mushOpen = false;
	//greenMush->setCheck(true);
	
	greenShell1->setPos(gsRandXR, gsRandYR);
	greenShell1->setX(gsRandXR);
	greenShell1->setY(gsRandYR);
	/*
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
	*/
	
	redShell1->setPos(80,400);
	redShell1->setX(80);
	redShell1->setY(400);
	
	coin->setPos(cRandXR, cRandYR);
	coin->setX(cRandXR);
	coin->setY(cRandYR);
	
	//greenMush->setPos(gRandXR, gRandYR);
	blueShell->setPos(cRandXR - 80,cRandYR - 90);
	
	blueShell->setX(cRandXR - 80);
	blueShell->setY(cRandYR - 90);
	
	blueShell->setvX(1);
	blueShell->setvY(1);
	
	timer->start();

}

void MainWindow::startGame()
{	

	//namestring = name->toPlainText();
	//if(namestring == 0 || (namestring == "Please Enter a Valid Name") == true)
	//{
		//name->setText("Please Enter a Valid Name");
	//}

	//else
	//{
		view->setFixedSize(1200, 900 );
		//grabKeyboard();
		gamescene= new QGraphicsScene();
		gameview = new QGraphicsView(gamescene);
		
		scene = new QGraphicsScene();
		view->setScene(scene);
		
		scene->clearFocus();
		
		view->setFocusPolicy(Qt :: StrongFocus);
		
		view->setFocus();
			
		gameview->setFixedSize(1000, 700 );
		gamescene->setSceneRect(0,0,950,650);
		
		QPixmap* backgroundPic = new QPixmap("PNGpics/background1.png");
		QPixmap* backgroundPM = new QPixmap(*backgroundPic);
		QBrush* backgroundBrush = new QBrush(*backgroundPM);
		
		gamescene->setBackgroundBrush(*backgroundBrush);
			
		QGridLayout* layout = new QGridLayout();
		view->setLayout(layout);
		layout->addWidget(gameview, 2, 0, 10,5);

		lives = 3;
		level = 1;
		score = 0;

	
		QPixmap* logoPic = new QPixmap("PNGpics/logo.png");
		QLabel* logo = new QLabel();
		logo->setPixmap(*logoPic);
		layout->addWidget(logo, 0, 1 , Qt::AlignHCenter);
		
		menu = new QPushButton("Menu  //  Pause");
		layout->addWidget(menu, 6, 10 , 1, 3, Qt::AlignHCenter);
		
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
		

		greenShellPic = new QPixmap("PNGpics/greenshell.png");
		redShellPic = new QPixmap("PNGpics/redshell.png");
		coinPic = new QPixmap("PNGpics/coin.png");
		blueShellPic = new QPixmap("PNGpics/blueshell.png");
		greenMushPic = new QPixmap("PNGpics/greenmushroom.png");

		counter = 0;
		counter2 = 0;
		counter3 = 0;	

		gamescene->clear();

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
		
		
		redShell1 = new RedShell(redShellPic, 80, 400);
		greenShell1 = new GreenShell(greenShellPic, gsRandX, gsRandY);
		coin = new Coin(coinPic, cRandX, cRandY);
		blueShell = new BlueShell(blueShellPic,cRandX - 80,cRandY - 90);
		greenMush = new GreenMush(greenMushPic,-9999 , -9999);
		

		itemsList.push_back(redShell1);
		itemsList.push_back(greenShell1);
		itemsList.push_back(coin);
		itemsList.push_back(blueShell);		
		itemsList.push_back(greenMush);		

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

	//}
}

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
	
	if(counter == 40)
	{
		counter = 0;
	}
	
	if(counter2 == 600)
	{
		counter2 = 0;
	}
	
	if(counter3% 300 == 0)
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


	redShell1->move(mainPlayer->pixmap->pos());
	greenShell1->move();
	
	/*
	if(greenShell2)
	{
		greenShell2->move();
	}
	*/
	
	blueShell->setCounter(counter2);
	blueShell->move();
	coin->setCounter(counter);
	coin->move();
	
	list<Thing*>:: iterator it = itemsList.begin();
	for(it = itemsList.begin(); it!= itemsList.end(); ++it)
	{

			if(mainPlayer->pixmap->collidesWithItem(*it))
			{			
				int obj = (*it)->executePower();
				{
					if(obj == 1)
					{
						timer->stop();
						if(lives == 1)
						{
							die();
							break;
						}
						else
						{
							minusLife();
							break;
						}
					}
				
					if(obj == 2)
					{
						timer->stop();
						die();
						break;
					}
				
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
					if(obj == 4 && greenMush->getCheck() == true)
					{
						timer->stop();
						
						//cout << greenMush->getCheck() << endl;
						
						gamescene->removeItem(greenMush);
						greenMush->setCheck(true);
						greenMush->setPos(-9999, -9999);

						lives++;
						
						//cout << greenMush->getCheck() << endl;
						
						mushOpen = false;
						
						timer->start();
						break;
					}
			
				}
			}
			else {}
	}

}

void MainWindow:: die()
	
{
		--lives;
		
		stringstream ss1;
		ss1<< lives;
		
		string str1 = ss1.str();
		const char* cstr1 = str1.c_str();
		
		QString lives2("Lives: ");
		lives2.append(cstr1);
	
		lives1->setText(lives2);
		
		
		QMessageBox losebox;
		
		stringstream ss , bb;
		ss<< score;
		
		string str = ss.str();
		str = "GAME OVER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n  	  Score: " +str;
		bb << coinCounter;
		string c = bb.str();
		str += "\n	  Coins: " + c;
		const char* cstr = str.c_str();

		
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
*/
void MainWindow:: minusLife()
{
	--lives;
	score -= 50;
	timer->stop();
	restart = false;
	resetGame();
}

void MainWindow :: levelUp()
{
	redShell1 -> setVelX(redShell1->getVelX() + .2);
	redShell1 -> setVelY(redShell1->getVelY() + .2);
	
	greenShell1 -> setVelX(greenShell1->getVelX() + 1);
	greenShell1 -> setVelY(greenShell1->getVelY() + 1);
	restart = false;
	
	coinCounter = 0;
	
	level++;
	/*
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
	
	
	
	
	if(level == 3)
	{
		int gsRandX = rand() %900;
		int gsRandY = rand()%600;

		// putting distance between shell and player
		while(gsRandX < 900 && gsRandX > 500 && gsRandY < 500 && gsRandY > 50)
		{
			gsRandX = rand()%900;
			gsRandY = rand()%600;
		}
		
		
		greenShell2 = new GreenShell(greenShellPic,gsRandX, gsRandY); 
		greenShell2 -> setVelX(greenShell1->getVelX());
		greenShell2 -> setVelY(greenShell1->getVelY());
		gamescene->addItem(greenShell2);
		itemsList.push_back(greenShell2);
		
	
	}
	
	if(level == 6)
	{
		int gsRandX = rand() %900;
		int gsRandY = rand()%600;

		// putting distance between shell and player
		while(gsRandX < 900 && gsRandX > 500 && gsRandY < 500 && gsRandY > 50)
		{
			gsRandX = rand()%900;
			gsRandY = rand()%600;
		}
		
		
		greenShell3 = new GreenShell(greenShellPic,gsRandX, gsRandY); 
		greenShell3 -> setVelX(greenShell1->getVelX());
		greenShell3 -> setVelY(greenShell1->getVelY());
		gamescene->addItem(greenShell3);
		itemsList.push_back(greenShell3);
		
	
	}
	
	*/
	timer->stop();

	resetGame();
	
}

void MainWindow::show() 
{
    view->show();
}
	
