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
		return;
	else
	{
		moveBy(-50, 0); x-=50;
		//cout<<"left x: "<<x<<endl;
	}
}

void Redekopp::move_right()
{
	if(x==450)
		return;
	else
	{
		moveBy(50, 0); x+=50;
		//cout<<"right x: "<<x<<endl;
	}
}

void Redekopp::move_up()
{
	if(y==100)
		return;
	else
	{
		moveBy(0,-50); y-=50;
		//cout<<"up y: "<<y<<endl;
	}
}

void Redekopp::move_down()
{
	if(y==450)
		return;
	else
	{
		moveBy(0, 50); y+=50;
		//cout<<"down y: "<<y<<endl;
	}
}

int Redekopp::getX() {return x;}
int Redekopp::getY() {return y;}

