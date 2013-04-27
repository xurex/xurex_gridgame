#include "bonus.h"

Bonus::Bonus( ) 
{
  pixMap = new QPixmap("./Images/redekopp.png");
  setPixmap( *pixMap );  //First Qt method that doesn’t take a pointer :->
  deleteMe=false; isBad=false; isBonus=true;
  srand(time(NULL));
  int pos = rand()%8+2;
  side = rand()%4+1;
  switch(side)
  {
     case 1://left
     	x = 50;
  	y = pos*50;	break;
     case 2://right
     	x = 500;
  	y = pos*50;	break;
     case 3://up
        x = pos*50;
  	y = 500;	break;
     case 4://down
  	x = pos*50;
  	y = 50;		break;
     default:
        cout<<"nothing selected in ladebug"<<endl; break;
  }
  setPos( x, y ); //how you set the position
}

void Bonus::move()
{
   switch(side)
   {
    	case 1://left
    		x += 10;
    		if(x==500)
    			deleteMe=true;
    		moveBy(10, 0);	break;
    	case 2://right
    		x -= 10;
    		if(x==0)
    			deleteMe=true;
    		moveBy(-10, 0);	break;
    	case 3://up
    		y -= 10;
    		if(y==0)
    			deleteMe=true;
    		moveBy(0, -10);	break;
    	case 4://down
    		y += 10;
    		if(y==500)
    			deleteMe=true;
    		moveBy(0, 10);	break;
    	default:
    		cout<<"nothing selected in ladebug move"<<endl; break;
   }
}
