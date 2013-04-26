#include "main.h"
#include <iostream>
using namespace std;

Main::Main(QApplication *mainapp)  {
    //Sets data member app to QApp
    app = mainapp;
    //Sets game condition to not in play
    inPlay = false; paused = false;
    
    count = 0;
    
    //Creates GraphicWindow
    view = new GraphicWindow(this);
    
    //Push Buttons
    start = new QPushButton("&Start", this);
    quit  = new QPushButton("&Quit", this);
    
    //Message
    message  = new QLabel(this);
    message->setFrameStyle( QFrame::WinPanel | QFrame::Sunken );
    message->setAlignment( Qt::AlignCenter );
    message->setText("Welcome to Comp Sci Craze");
    
    //Timer
    timer = new QTimer(this);
    timer->setInterval(100);
    
    //Background
    background = new QPixmap("./Images/compsci.jpg");
    view->scene->setBackgroundBrush(background->scaled
    (WINDOW_MAX_X,WINDOW_MAX_Y,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    
    //Connects
    connect(start, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(quit , SIGNAL(clicked()), this, SLOT(exitGame()));
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    
    //Protagonist
    redekopp = new QPixmap("./Images/redekopp.png");
    protagonist = new Redekopp(redekopp, 100, 100);
    
    //Sets focus for MainWindow
    setFocus();
    
    QWidget *window = new QWidget;
    
    QHBoxLayout *startquit = new QHBoxLayout;
    startquit->addWidget(start);
    startquit->addWidget(quit);
    
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(message);
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
		return;

	  inPlay = true;
	  message->setText("Game started...good luck");
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
	  
	  PointUp *up = new PointUp();
	  PointDown *down = new PointDown();
	  PointLeft *left = new PointLeft();
	  PointRight *right = new PointRight();
	  pointers.push_back(up);
	  view->scene->addItem(pointers[pointers.size()-1]);
	  pointers.push_back(down);
	  view->scene->addItem(pointers[pointers.size()-1]);
	  pointers.push_back(left);
	  view->scene->addItem(pointers[pointers.size()-1]);
	  pointers.push_back(right);
	  view->scene->addItem(pointers[pointers.size()-1]);

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
	}
}

void Main::handleTimer()
{
	if(count%10==0)
	{
		srand(time(NULL));
		int dir = rand()%4+1;
		if(dir==1)
		{
		     PointUp *up;
		     up = new PointUp();
		     pointers.push_back(up); 
		     view->scene->addItem(pointers[pointers.size()-1]);
		}
		else if(dir==2)
		{
		     PointDown *down;
		     down = new PointDown();
		     pointers.push_back(down);
		     view->scene->addItem(pointers[pointers.size()-1]);
		}
		else if(dir==3)
		{
		     PointLeft *left;
		     left = new PointLeft();
		     pointers.push_back(left);
		     view->scene->addItem(pointers[pointers.size()-1]);
		}
		else if(dir==4)
		{
		     PointRight *right;
		     right = new PointRight();
		     pointers.push_back(right);
		     view->scene->addItem(pointers[pointers.size()-1]);
		}
	}
	if(count%301==0)
	{
		Ladebug *bug;
		bug = new Ladebug();
		pointers.push_back(bug);
		view->scene->addItem(pointers[pointers.size()-1]);
	}
	for(unsigned int i=0; i<pointers.size(); i++)
	{pointers[i]->move();}
	
	count++;
}

/**Destructor*/
Main::~Main()
{
	//FINISH THIS SHIT
	delete view;
	delete start;
	delete quit;
	delete message;
	delete timer;
	for(int i=0; i<SIZE; i++)
	{
	   delete board[i];
	}
}
