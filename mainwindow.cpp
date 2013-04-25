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
	QGraphicsScene* startscene = new QGraphicsScene();
	
	mainPlayer = new Mario(700, 300);
	

	view = new GraphicsView(startscene, mainPlayer);


	QPixmap* logoPic = new QPixmap("PNGpics/prelogo.png");

	QGraphicsPixmapItem* prelogo = new QGraphicsPixmapItem(*logoPic);
	
	startscene->addItem(prelogo);
	prelogo->setPos(100,100);
	prelogo->show();
	
	
	
	start = new QPushButton("Start Game");
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
	
	clearFocus();
	
	name->setFocus();
	
	
	connect(start, SIGNAL(clicked()), this, SLOT(startGame()));
}


void MainWindow:: resetCoin()
{
	
	int cRandXR = rand() %900;
	int cRandYR = rand()%700;
	
	
	coin-> setX(cRandXR);
	coin->setY(cRandYR);
	coin->setPos(cRandXR, cRandYR);
	blueShell->setPos(cRandXR - 80,cRandYR - 90);
	
	blueShell->setX(cRandXR - 80);
	blueShell->setY(cRandYR - 90);
	
	timer->start();
	
}
void MainWindow :: resetGame()
{


	int gsRandXR = rand()%900;
	int gsRandYR = rand()%600;
		
	int cRandXR = rand() %900;
	int cRandYR = rand()%600;
		
	int gRandXR = rand() %900;
	int gRandYR = rand()%600;
		
	if(cRandXR == gsRandXR && cRandYR == gsRandYR)
	{
		cRandXR += 100;
	}
	
	// putting distance between shell and player
	while(gsRandXR < 900 && gsRandXR > 500 && gsRandYR < 500 && gsRandYR > 50)
	{
		gsRandXR = rand()%900;
		gsRandYR = rand()%600;
	}
		
	// putting distance between coin and player
	while(cRandXR < 900 && cRandXR > 500 && cRandYR < 500 && cRandYR > 50)
	{
		cRandXR = rand()%900;
		cRandYR = rand()%600;
	}
		
	// putting distance bewteen mush and player
	while(gRandXR < 900 && gRandXR > 500 && gRandYR < 500 && gRandYR > 50)
	{
		gRandXR = rand()%900;
		gRandYR = rand()%600;
	}
	
	if(restart == true)
	{
		lives = 3;
		score = 0;
		coinCounter=0;
		level = 0;
	}
	
	counter= 0;
	counter2 = 0;
	counter3 = 0;
	
	restart = true;
	
	greenShell1->setPos(gsRandXR, gsRandYR);
	greenShell1->setX(gsRandXR);
	greenShell1->setY(gsRandYR);
	
	redShell1->setPos(80,400);
	redShell1->setX(80);
	redShell1->setY(400);
	
	coin->setPos(cRandXR, cRandYR);
	coin->setX(cRandXR);
	coin->setY(cRandYR);
	
	greenMush->setPos(gRandXR, gRandYR);
	blueShell->setPos(cRandXR - 80,cRandYR - 90);
	blueShell->setX(cRandXR - 80);
	blueShell->setY(cRandYR - 90);
	
	timer->start();

}

void MainWindow::startGame()
{	

	namestring = name->toPlainText();
	if(namestring == 0 || (namestring == "Please Enter a Valid Name") == true)
	{
		name->setText("Please Enter a Valid Name");
	}

	else
	{
		gamescene= new QGraphicsScene();
		gameview = new QGraphicsView(gamescene);

		scene = new QGraphicsScene();
		
		
		view->setScene(scene);
		
	
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
		
		if(cRandX == gsRandX && cRandY == gsRandY)
		{
			cRandX += 100;
		}
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
		greenMush = new GreenMush(greenMushPic,gRandX , gRandY - 90);
		

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
    	timer->setInterval(30);
		timer->start();


		connect(menu, SIGNAL(clicked()), this, SLOT(menuFunc()));
    	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));

	}
}

void MainWindow:: handleTimer()
{

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

	
		
	counter ++;
	counter2++;
	counter3++;
	if(counter == 40)
	{
		counter = 0;
	}
	
	if(counter2 == 1000)
	{
		counter2 = 0;
	}
	

	if(counter3% 300 == 0)
	{
		if(greenMush->getCheck() == true && mushOpen == false)
		{
			cout << "adding item" << endl;
			greenMush->setCheck(true);
			mushOpen = true;
		
			gamescene->addItem(greenMush);
		}
	}


	redShell1->move(mainPlayer->pixmap->pos());
	greenShell1->move();
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
						greenMush->setCheck(false);
						
						lives++;
						
						//cout << greenMush->getCheck() << endl;
						
						mushOpen = false;
						
						
						timer->start();
						cout << "hi" << endl;
						break;
					}
			
				}
			}
			else {}
	}

}

void MainWindow:: die()
	
{
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
	
	level++;
	timer->stop();
	resetGame();
	
}

void MainWindow::show() 
{
    view->show();
}
	
