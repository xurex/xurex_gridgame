#include "point_down.h"

PointDown::PointDown( )
{
  pixMap = new QPixmap("./Images/pointer_down.png");
  setPixmap( *pixMap );  //First Qt method that doesn’t take a pointer :->
  deleteMe=false; isGood=0;
  srand(time(NULL));
  int pos = rand()%8+2;
  x = pos*50;
  y = 50;
  setPos( x, y ); //how you set the position
}

void PointDown::move()
{
    	y += 10;
    	if(y==500)
    		deleteMe=true;
    	moveBy(0, 10);
}
