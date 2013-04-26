#ifndef POINT_RIGHT_H
#define POINT_RIGHT_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"

class PointRight: public Thing {

  public:
    PointRight ();
    ~PointRight() { delete pixMap; }
    
    void move();
    //virtual void move() = 0;  //virtual function. Class Thing is abstract. For a reason.
  private:  //Every thing has a origin and a velocity – maybe 0
    int x;
    int y;
    QPixmap *pixMap;  //Good idea. Explain later.
    
};

#endif //POINT_RIGHT_H
