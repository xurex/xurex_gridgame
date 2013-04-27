#include "ram.h"

Ram::Ram( ) 
{
  pixMap = new QPixmap("./Images/ram.png");
  setPixmap( *pixMap );  //First Qt method that doesn’t take a pointer :->
  deleteMe=false;
  x = 500;
  y = 50;
  setPos( x, y ); //how you set the position
}

void Ram::move()
{
    	x -= 10;
    	if(x==20)
    	{
    		deleteMe=true; //unnecessary, but good form
    	}
    	moveBy(-10, 0);
}

int Ram::getX()
{
	return x;
}
