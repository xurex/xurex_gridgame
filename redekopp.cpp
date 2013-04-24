#include "redekopp.h"

Redekopp::Redekopp( QPixmap* p, int nx, int ny ) 
{
  pixMap = p; //Handy to store separate to get image width/height, etc.
  setPixmap( *p );  //First Qt method that doesn’t take a pointer :->
  x = nx;
  y = ny;
  setPos( x, y ); //how you set the position
}

void Redekopp::move_left()
{
	if(x==100)
		setPos(450, y);
	else
		moveBy(-50, 0);
}

void Redekopp::move_right()
{
	if(x==450)
		setPos(100, y);
	else
		moveBy(50, 0);
}

void Redekopp::move_up()
{
	if(y==100)
		setPos(x, 450);
	else
		moveBy(0, -50);
}

void Redekopp::move_down()
{
	if(y==450)
		setPos(x, 100);
	else
		moveBy(0, 50);
}



