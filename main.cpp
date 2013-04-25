#include "main.h"
#include <iostream>
using namespace std;

Main::Main(QApplication *mainapp)  {
    //Sets data member app to QApp
    app = mainapp;
    //Sets game condition to not in play
    inPlay = false;
    
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
	else{
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
        }
        setFocus();
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
			protagonist->move_left();	break;
		case Qt::Key_D://Qt::Key_Right :
			protagonist->move_right();	break;
		case Qt::Key_W://Qt::Key_Up :
			protagonist->move_up();		break;
		case Qt::Key_S://Qt::Key_Down:
			protagonist->move_down();	break;
	}
}


/**Destructor*/
Main::~Main()
{
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
