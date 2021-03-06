#include "main.h"
#include <iostream>
using namespace std;

Main::Main(QApplication *mainapp)  {
    //Sets data member app to QApp
    app = mainapp;
    //Sets game condition to not in play
    inPlay = false; paused = false; gameover=false;
    
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
    
    //Instructions
    instructions = new QPixmap("./Images/instructions.png");
    instructionpage = new QGraphicsPixmapItem();
    instructionpage->setPixmap(*instructions);
    view->scene->addItem(instructionpage);
    
    //Name
    name = new QLabel(this);
    name->setFrameStyle( QFrame::WinPanel | QFrame::Sunken );
    name->setAlignment( Qt::AlignCenter );
    name->setText("     Please Enter Name");
    
    nameIn = new QLineEdit;
    nameIn->setText("Please Enter Name");
    view->scene->addWidget(nameIn);
    nameIn->move(120,0);
    
    //Connects
    connect(start, SIGNAL(clicked()), this, SLOT(startGame()));
    connect(quit , SIGNAL(clicked()), this, SLOT(exitGame()));
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    
    //Sets focus for MainWindow
    setFocus();
    
    window = new QWidget;
    
    QHBoxLayout *startquit = new QHBoxLayout;
    startquit->addWidget(start);
    startquit->addWidget(quit);
    
    QHBoxLayout *display = new QHBoxLayout;
    display->addWidget(name);
    display->addWidget(score);
    display->addWidget(lives);
    
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(display);
    //layout->addWidget(nameIn);
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
	if(inPlay||gameover)
	{
		gameover=false;
		paused = false;
		protagonist->resBlink();
		QString thename;
	  	thename=nameIn->text();
	  	if(thename.size())
	  	{
	  	    name->setText(thename);
	  	}
		if(timer->isActive())
		{
			timer->stop();
		}
		clear();
		protagonist->lifeReset();
		count = 1; intscore = 0;  speed=101;
		timer->setInterval(speed);
		//Regenerates certain objects
		delete dictionary;
		dictionary = new Dictionary();
		delete coffee;
		coffee = new Coffee();
		view->scene->addItem(coffee);
		view->scene->addItem(dictionary);
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
		setFocus();
		return;
	}
	  inPlay = true; 
	  view->scene->removeItem(instructionpage);
	  if(nameIn->isModified())
	  	name->setText(nameIn->text());
	  else
		name->setText("Anonymous");
	  nameIn->close();
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
	  //Creates certain start characters
	  coffee = new Coffee();
	  dictionary = new Dictionary();
	  view->scene->addItem(coffee);
	  view->scene->addItem(dictionary);
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
	if(!inPlay||gameover)
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
			protagonist->show();
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
				speed-=10;
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
	//DICTIONARY CODE
	
		if(count%100>80)
		{
			if((count%100)%5==0)
			{
			   PointLeft *left;
			   left = new PointLeft(dictionary->getY(),"./Images/bucket.png");
			   pointers.push_back(left);
			   view->scene->addItem(pointers[pointers.size()-1]);
			}
		}
		else
		{
			dictionary->move(protagonist->getY());
		}
	//BONUS AND LADEBUG CODE
	if(count%33==0)
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
			   PointDown *heap; QString image("./Images/heap.png");
			   heap = new PointDown(ram->getX()+50, image);
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
	//COFFEE MOVE AND DELETE AND COLLISION SHIT
	coffee->move(protagonist->getX(), protagonist->getY());
	if(!protagonist->getBlink())
	{
	  if(protagonist->collidesWithItem(coffee))
	  {
	  	protagonist->setBlink();
		delete coffee;
		coffee = new Coffee();
		view->scene->addItem(coffee);
		if(speed>10)
		{
		speed -= 10;
		timer->setInterval(speed);
		}
	  }
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
	   	if(pointers[i]->isGood)
	   	{
	   		if(pointers[i]->isGood==1) //bonus coin
	   		{
	   			intscore+=100; setScore();
	   			delete pointers[i];
	   			pointers.erase(pointers.begin()+i);
	   		}
	   		else if(pointers[i]->isGood==2) //ladebug
	   		{
	   			timer->stop(); clear(); timer->start();
	   		}
	   	}
	   	else //bad collisions
	   	{
	   		if(!protagonist->getBlink()) //this allows for temp invincibility
	   		{	
	   			protagonist->setBlink();
	   			protagonist->lifeDown(); setLife();
	   			delete pointers[i];
	   			pointers.erase(pointers.begin()+i);	
	   		}
	   		if(!protagonist->getLife())
	   		{
	   			timer->stop(); gameover=true;
	   			lives->setText(" GAME OVER");
	   			highScore();
	   			return;
	   		}
	   	}
	   }
	}
	count++; intscore++; setScore();
	if(protagonist->getBlink()) //blinks the protagonist
	{
		if(!(protagonist->getBlink()%3))
			protagonist->hide();
		else
			protagonist->show();
		protagonist->decBlink();
	}
	//SPEEDS GAME UP AND CHANGES LEVEL
	if(count%1000==0)
	{
		if(speed>20)
		{
		speed -= 20;
		timer->setInterval(speed);
		}
		clear(); clear();
		intscore+=1000; setScore();
		if(count>3999)
			view->scene->setBackgroundBrush(Qt::black);
		else if(count>2999)
			view->scene->setBackgroundBrush(Qt::darkGray);
		else if(count>1999)
			view->scene->setBackgroundBrush(Qt::gray);
		else if (count>999)
			view->scene->setBackgroundBrush(Qt::lightGray);
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

void Main::highScore()
{
	string name_;
	int score_;
	unsigned int iterate = 0; //used to sync it because i'm too lazy to make struct pair
	vector<string> names;
	vector<int> scores;
	
	//LOADS CURRENT HIGH SCORES
	ifstream fin("./highscore.txt");
	if(fin.fail())
		return;
	fin>>name_; 
	while(!fin.eof())
	{
		fin>>score_;
		names.push_back(name_);
		scores.push_back(score_);
		fin>>name_;
	}
	fin.close();
	//FOUT NEW SCORE LIST
	ofstream fout("./highscore.txt");
	if(scores.empty())
	{
		fout<<((name->text()).toStdString())<<"\t"<<intscore<<endl;
	}
	else if(scores.size()<10)
	{
		std::vector<int>::iterator it;
		it = scores.begin();
		std::vector<string>::iterator itt;
		itt = names.begin();
		name_ = ((name->text()).toStdString());
		while(intscore<=*it&&iterate<scores.size())
		{
			it++; iterate++;
		}
		while(iterate)
		{
			itt++; iterate--;
		}
		scores.insert(it, intscore);
		names.insert(itt, name_);
		for(unsigned int i=0; i<scores.size(); i++)
		{
			fout<<names[i]<<"\t"<<scores[i]<<endl;
		}
	}
	else if(scores.size()==10)
	{
		if(intscore>scores[9])
		{
		   std::vector<int>::iterator it;
		   it=scores.begin();
		   std::vector<string>::iterator itt;
		   itt=names.begin();
		   name_ = ((name->text()).toStdString());
		   while(intscore<=*it&&iterate<scores.size())
		   {
			it++; iterate++;
		   }
		   while(iterate)
		   {
			itt++; iterate--;
		   }
		   scores.insert(it, intscore);
		   names.insert(itt, name_);
		   scores.pop_back(); //scores.erase(scores.begin()+10);
		   names.pop_back(); //names.erase(names.begin()+10);
		   for(unsigned int i=0; i<scores.size(); i++)
		   {
		   	fout<<names[i]<<"\t"<<scores[i]<<endl;
		   }
		}
	}
	fout.close();
}

/**Destructor*/
Main::~Main()
{
    //delete view; 
    //delete start; 
    //delete quit;  
    //delete score;
    //delete lives;
    //delete name;
    //delete nameIn;
    //delete nameLay;
    //delete timer; cout<<"after time ";
    //delete redekopp;
    delete instructions;
    delete instructionpage;
    //delete protagonist;
    //delete ram;
    if(inPlay)
    {
	for(int i=0; i<SIZE; i++)
	{
	   delete board[i];
	}
    	clear();
    }
}
