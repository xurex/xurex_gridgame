#include "redekopp.h"

Redekopp::Redekopp( QPixmap* p, int nx, int ny ) 
{
  pixMap = p; //Handy to store separate to get image width/height, etc.
  setPixmap( *p );  //First Qt method that doesn’t take a pointer :->
  life = 5;
  x = nx;
  y = ny;
  setPos( x, y ); //how you set the position
}

void Redekopp::lifeDown()
{
	--life;
	cout<<"lives: "<<life<<endl;
}	

void Redekopp::lifeUp()
{
	++life;
	cout<<"lives: "<<life<<endl;
}

int Redekopp::getLife()
{
	return life;
}

void Redekopp::move()
{
	//just overwriting void
	return;
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

void Redekopp::lifeReset()
{
	life=5; x=250; y=250; setPos(x,y);
}

int Redekopp::getX() {return x;}
int Redekopp::getY() {return y;}

