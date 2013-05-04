#include "point_right.h"

PointRight::PointRight( ) 
{
  pixMap = new QPixmap("./Images/pointer_left.png");
  setPixmap( *pixMap );  //First Qt method that doesn’t take a pointer :->
  deleteMe=false; isGood=0;
  srand(time(NULL));
  int pos = rand()%8+2;
  x = 500;
  y = pos*50;
  setPos( x, y ); //how you set the position
}

void PointRight::move()
{
    	x -= 10;
    	if(x==20)
    		deleteMe=true;
    	moveBy(-10, 0);
}
