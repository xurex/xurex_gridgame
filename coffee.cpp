#include "coffee.h"

Coffee::Coffee( ) 
{
  pixMap = new QPixmap("./Images/coffee.png");
  setPixmap( *pixMap );  //First Qt method that doesn’t take a pointer :->
  deleteMe=false; isGood=0;
  x = 100;
  y = 100;
  setPos( x, y ); //how you set the position
}

void Coffee::move(int px, int py)
{

	if(py>y)
	{
		y += 5;
    		moveBy(0, 5);
	}
	else if(py<y)
	{
		y -= 5;
    		moveBy(0, -5);
	}
	else if(px>x)
	{
		x += 5;
		moveBy(5, 0);
	}
	else if(px<x)
	{
		x -= 5;
		moveBy(-5, 0);
	}
}
