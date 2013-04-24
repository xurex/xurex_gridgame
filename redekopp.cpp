#include "redekopp.h"

Redekopp::Redekopp( QPixmap* p, int nx, int ny ) 
{
  pixMap = p; //Handy to store separate to get image width/height, etc.
  setPixmap( *p );  //First Qt method that doesn’t take a pointer :->
  x = nx;
  y = ny;
  setPos( x, y ); //how you set the position
}
