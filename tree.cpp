#include "tree.h"

Tree::Tree( ) 
{
  pixMap = new QPixmap("./Images/rainbow-satan-tree.png");
  setPixmap( *pixMap );  //First Qt method that doesn’t take a pointer :->
  deleteMe=false;
  srand(time(NULL));
  int posx = rand()%8+2; int posy = rand()%7+3;
  x = posx*50;
  y = posy*50;
  setPos( x, y ); //how you set the position
}

void Tree::move()
{
   
}
