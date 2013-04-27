#include "tree.h"

Tree::Tree( ) 
{
  pixMap = new QPixmap("./Images/rainbow-satan-tree.png");
  setPixmap( *pixMap );  //First Qt method that doesn’t take a pointer :->
  deleteMe=false; isBad=true;
  srand(time(NULL));
  int posx = rand()%8+2; int posy = rand()%7+3;
  x = posx*50;
  y = posy*50;
  setPos( x, y ); //how you set the position
  deathCount=0;
}

void Tree::move()
{
   deathCount++;
   if(deathCount==100)
   	deleteMe=true;
}

void Tree::setDelete()
{
	deleteMe=true;
}
