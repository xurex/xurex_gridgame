#include "dictionary.h"

Dictionary::Dictionary( ) 
{
  pixMap = new QPixmap("./Images/dictionary.png");
  setPixmap( *pixMap );  //First Qt method that doesn’t take a pointer :->
  deleteMe=false; isGood=0;
  x = 50;
  y = 100;
  setPos( x, y ); //how you set the position
}

void Dictionary::move(int loc)
{
	if(loc>y)
	{
		y += 10;
    		moveBy(0, 10);
	}
	else if(loc<y)
	{
		y -= 10;
    		moveBy(0, -10);
	}
}
