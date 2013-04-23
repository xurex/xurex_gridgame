#include "main.h"
#include <iostream>
using namespace std;

Main::Main(QApplication *mainapp)  {
    //Sets data member app to QApp
    app = mainapp;
    //Sets game condition to not in play
    inPlay = false;
    
    //We need a scene and a view to do graphics in QT
    scene = new QGraphicsScene();
    view = new QGraphicsView( scene );

    //This sets the size of the window and gives it a title.
    view->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y );
    view->setWindowTitle( "Comp Sci Craze" );
    
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
    
    //Connects
    connect(start, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(quit , SIGNAL(clicked()), this, SLOT(exitGame()));
    
}

void Main::show() {
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
}

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
	  	  scene->addItem(board[count]); count++;
	  	}
	  	x=100;
	  	y+=wh;
	  }
        }
}

void Main::exitGame()
{
	app->exit();
}

/**Destructor*/
Main::~Main()
{
	delete scene;
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
