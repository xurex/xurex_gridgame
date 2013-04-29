#include "heap.h"

Heap::Heap( )
{
  pixMap = new QPixmap("./Images/heap.png");
  setPixmap( *pixMap );  //First Qt method that doesn’t take a pointer :->
  deleteMe=false; isBad=true;
  srand(time(NULL));
  int pos = rand()%8+2;
  x = pos*50;
  y = 50;
  setPos( x, y ); //how you set the position
}

Heap::Heap(int nx)
{
  pixMap = new QPixmap("./Images/heap.png");
  setPixmap( *pixMap );  //First Qt method that doesn’t take a pointer :->
  deleteMe=false; isBad=true;
  x = nx;
  y = 50;
  setPos( x, y ); //how you set the position
}

void Heap::move()
{
    	y += 10;
    	if(y==500)
    		deleteMe=true;
    	moveBy(0, 10);
}
