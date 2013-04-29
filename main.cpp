#include "main.h"
#include <iostream>
using namespace std;

Main::Main(QApplication *mainapp)  {
    //Sets data member app to QApp
    app = mainapp;
    //Sets game condition to not in play
    inPlay = false; paused = false;
    
    count = 0; runningRam=0; intscore = 0;
    
    //Creates GraphicWindow
    view = new GraphicWindow(this);
    
    //Push Buttons
    start = new QPushButton("&Start", this);
    quit  = new QPushButton("&Quit", this);
    
    //Protagonist
    redekopp = new QPixmap("./Images/redekopp.png");
    protagonist = new Redekopp(redekopp, 250, 250);
    
    //SCORE
    score  = new QLabel(this);
    score->setFrameStyle( QFrame::WinPanel | QFrame::Sunken );
    score->setAlignment( Qt::AlignCenter );
    setScore();
    
    //LIVES
    lives = new QLabel(this);
    lives->setFrameStyle( QFrame::WinPanel | QFrame::Sunken );
    lives->setAlignment( Qt::AlignCenter );
    setLife();
    
    //Timer
    speed = 101;
    timer = new QTimer(this);
    timer->setInterval(speed);
    
    //Background
    /*
    background = new QPixmap("./Images/compsci.jpg");
    view->scene->setBackgroundBrush(background->scaled
    (WINDOW_MAX_X,WINDOW_MAX_Y,Qt::IgnoreAspectRatio));
    */
    //Connects
    connect(start, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(quit , SIGNAL(clicked()), this, SLOT(exitGame()));
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    
    //Sets focus for MainWindow
    setFocus();
    
    QWidget *window = new QWidget;
    
    QHBoxLayout *startquit = new QHBoxLayout;
    startquit->addWidget(start);
    startquit->addWidget(quit);
    
    QHBoxLayout *display = new QHBoxLayout;
    display->addWidget(score);
    display->addWidget(lives);
    
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(display);
    layout->addWidget(view);
    layout->addLayout(startquit);
    
    window->setLayout(layout);
    window->show();
    
    setCentralWidget(window);
}
/*
void Main::show() {
    
}*/

void Main::startGame()
{
	if(inPlay)
	{
		if(timer->isActive())
		{
			timer->stop();
		}
		clear();
		protagonist->lifeReset();
		count = 1; intscore = 0;  speed=101;
		timer->setInterval(speed);
		if(runningRam)
		{
			delete ram; runningRam=0;
		}
		setScore(); setLife();
		//PRECLUDES SCENE SHIFT
	  	makeUp(); makeDown(); makeLeft(); makeRight();
		if(!timer->isActive())
		{
			timer->start();
			paused=false;
		}
		
		return;
	}
	  inPlay = true;
	  board = new Grid*[SIZE];
	  double wh = 50;
	  double x, y; x=y=100;
	  count = 0;
	  for(int i=0; i<DIM; i++)
	  {
	  	for(int j=0; j<DIM; j++)
	  	{
	  	  Grid* temp = new Grid(x,y,wh,wh);
	  	  x+=wh;
	  	  board[count]=temp;
	  	  view->scene->addItem(board[count]); count++;
	  	}
	  	x=100;
	  	y+=wh;
	  }
	  view->scene->addItem(protagonist);
	  //PRECLUDES SCENE SHIFT
	  makeUp(); makeDown(); makeLeft(); makeRight();

          timer->start();
}

void Main::exitGame()
{
	app->exit();
}

void Main::keyPressEvent( QKeyEvent *e ) {
	//We need to find out which key was pressed
	//Let’s say we want to use the 4 arrow keys
	if(!inPlay)
		return;
	switch (e->key()) 
	{
		case Qt::Key_A://Qt::Key_Left :
			if(!paused) protagonist->move_left();	break;
		case Qt::Key_D://Qt::Key_Right :
			if(!paused) protagonist->move_right();	break;
		case Qt::Key_W://Qt::Key_Up :
			if(!paused) protagonist->move_up();	break;
		case Qt::Key_S://Qt::Key_Down:
			if(!paused) protagonist->move_down();	break;
		case Qt::Key_P:
			if(!paused)
			{
				timer->stop();
				paused = true;
			}
			else
			{
				timer->start(); 
				paused = false;
			}
			break;
		case Qt::Key_C:
			if(speed>20)
			{
				speed-=10; cout<<"SPEED IS NOW: "<<speed<<endl;
				timer->setInterval(speed);
			}
			break;
	}
}

void Main::handleTimer()
{
	//POINTER CODE
	if(count%10==0)
	{
		srand(time(NULL));
		int dir = rand()%4+1;
		if(dir==1)
		{
		     makeUp();
		}
		else if(dir==2)
		{
		     makeLeft();
		}
		else if(dir==3)
		{
		     makeRight();
		}
		else if(dir==4)
		{
		     makeDown();
		}
	}
	//BONUS AND LADEBUG CODE
	if(count%666==0)
	{
		Bonus *bonus;
		bonus = new Bonus();
		pointers.push_back(bonus);
		view->scene->addItem(pointers[pointers.size()-1]);
	}
	if(count%356==0)
	{
		Ladebug *bug;
		bug = new Ladebug();
		pointers.push_back(bug);
		view->scene->addItem(pointers[pointers.size()-1]);
	}
	//RAM & HEAP CODE
	int checker = count%200;
	if(checker==0)
	{
		ram = new Ram();
		view->scene->addItem(ram);
		runningRam+=1;
	}
	if(runningRam)
	{
		int ramcheck = checker%14;
		if(ramcheck>0&&ramcheck<6)
		{
			ram->move(); runningRam++;
		}
		if(runningRam==50)
		{
			runningRam=0; delete ram;
		}
		if(ramcheck==0)
		{
			if(ram->getX()<=400&&ram->getX()>=50)
			{
			   Heap *heap;
			   heap = new Heap(ram->getX()+50);
			   pointers.push_back(heap);
			   view->scene->addItem(pointers[pointers.size()-1]);
			}
		}
	}
	//TREE CODE
	if(count%350==0)
	{
		Tree *rand;
		rand = new Tree();
		pointers.push_back(rand);
		view->scene->addItem(pointers[pointers.size()-1]);
	}
	if(count%400==0)
	{
		Tree *rand;
		rand = new Tree();
		pointers.push_back(rand);
		view->scene->addItem(pointers[pointers.size()-1]);
	}
	if(count%375==0)
	{
		Tree *rand;
		rand = new Tree();
		pointers.push_back(rand);
		view->scene->addItem(pointers[pointers.size()-1]);
	}
	//MOVE AND DELETE CODE FOR VECTOR
	for(unsigned int i=0; i<pointers.size(); i++)
	{
	   pointers[i]->move();
	   if(pointers[i]->deleteMe)
	   {
	   	delete pointers[i];
	   	pointers.erase(pointers.begin()+i);
	   }
	}
	//CHECKS COLLISIONS
	for(unsigned int i=0; i<pointers.size(); i++)
	{
	   if(protagonist->collidesWithItem(pointers[i], Qt::IntersectsItemShape))
	   {
	   	if(pointers[i]->isBad)
	   	{
	   		protagonist->lifeDown(); setLife();
	   		delete pointers[i];
	   		pointers.erase(pointers.begin()+i);
	   		if(!protagonist->getLife())
	   		{
	   			timer->stop(); inPlay=false;
	   			score->setText("GAME"); lives->setText("OVER");
	   			return;
	   		}
	   	}
	   	else if(!pointers[i]->isBad)//good items
	   	{
	   		if(pointers[i]->isBonus==true)
	   		{
	   			if(protagonist->getLife()==5)
	   			{
	   				intscore+=50; setScore();
	   			}
	   			else
	   			{
	   				protagonist->lifeUp(); setLife();
	   			}
	   			delete pointers[i];
	   			pointers.erase(pointers.begin()+i);
	   		}
	   		else if(pointers[i]->isBonus==false)
	   		{
	   			timer->stop(); clear(); timer->start();
	   		}
	   	}
	   }
	}
	count++; intscore++; setScore();
	//SPEEDS GAME UP
	if(count%1000==0)
	{
		if(speed>25)
		{
		speed -= 25; cout<<"SPEED IS NOW: "<<speed<<endl;
		timer->setInterval(speed);
		}
	}
}

void Main::makeUp()
{
	PointUp *up;
	up = new PointUp();
	pointers.push_back(up); 
	view->scene->addItem(pointers[pointers.size()-1]);
}

void Main::makeDown()
{
	PointDown *down;
	down = new PointDown();
	pointers.push_back(down);
	view->scene->addItem(pointers[pointers.size()-1]);
}

void Main::makeLeft()
{
	PointLeft *left;
	left = new PointLeft();
	pointers.push_back(left);
	view->scene->addItem(pointers[pointers.size()-1]);
}

void Main::makeRight()
{
	PointRight *right;
	right = new PointRight();
	pointers.push_back(right);
	view->scene->addItem(pointers[pointers.size()-1]);
}

void Main::clear()
{
   for(unsigned int i=0; i<3; i++){
	for(unsigned int i=0; i<pointers.size(); i++)
	{
		delete pointers[i];
		pointers.erase(pointers.begin()+i);
	}
   }
}

void Main::setScore()
{
	sscore = "Score: "; sscore.append(QString::number(intscore)); 
	score->setText(sscore);
}

void Main::setLife()
{
	slives = "Lives: "; slives.append(QString::number(protagonist->getLife()));
    	lives->setText(slives);
}

/**Destructor*/
Main::~Main()
{
	//FINISH THIS SHIT
	delete view;
	delete start;
	delete quit;
	delete score;
	delete timer;
	for(int i=0; i<SIZE; i++)
	{
	   delete board[i];
	}
}
