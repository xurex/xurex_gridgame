#ifndef POINT_LEFT_H
#define POINT_LEFT_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"

class PointLeft: public Thing {

  public:
    PointLeft ();
    ~PointLeft() { delete pixMap; }
    
    void move();
    //virtual void move() = 0;  //virtual function. Class Thing is abstract. For a reason.
  private:  //Every thing has a origin and a velocity – maybe 0
    int x;
    int y;
    QPixmap *pixMap;  //Good idea. Explain later.
    
};

#endif //POINT_LEFT_H
