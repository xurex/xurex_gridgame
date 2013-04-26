#include "point_up.h"

PointUp::PointUp( ) 
{
  pixMap = new QPixmap("./Images/pointer_up.png");
  setPixmap( *pixMap );  //First Qt method that doesn’t take a pointer :->
  srand(time(NULL));
  int pos = rand()%8+2;
  x = pos*50;
  y = 500;
  setPos( x, y ); //how you set the position
}

void PointUp::move()
{
    	y -= 10;
    	if(y==0)
    		delete this;
    	moveBy(0, -10);
}
