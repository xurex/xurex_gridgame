#include "point_left.h"

PointLeft::PointLeft( ) 
{
  pixMap = new QPixmap("./Images/pointer_right.png");
  setPixmap( *pixMap );  //First Qt method that doesn’t take a pointer :->
  srand(time(NULL));
  int pos = rand()%8+2;
  x = 50;
  y = pos*50;
  setPos( x, y ); //how you set the position
}

void PointLeft::move()
{
    	x += 10;
    	if(x==500)
    		delete this;
    	moveBy(10, 0);
}
