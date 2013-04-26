#ifndef LADEBUG_H
#define LADEBUG_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"

class Ladebug: public Thing {

  public:
    Ladebug ();
    ~Ladebug() { delete pixMap; }
    
    void move();
    //virtual void move() = 0;  //virtual function. Class Thing is abstract. For a reason.
  private:  //Every thing has a origin and a velocity – maybe 0
    int x;
    int y;
    int side; //left, right, up, down (1-4)
    QPixmap *pixMap;  //Good idea. Explain later.
    
};

#endif //LADEBUG_H
