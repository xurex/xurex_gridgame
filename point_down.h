#ifndef POINT_DOWN_H
#define POINT_DOWN_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"

class PointDown: public Thing {

  public:
    PointDown ();
    ~PointDown() { delete pixMap; }
    
    void move();
    //virtual void move() = 0;  //virtual function. Class Thing is abstract. For a reason.
  private:  //Every thing has a origin and a velocity – maybe 0
    int x;
    int y;
    QPixmap *pixMap;  //Good idea. Explain later.
    
};

#endif //POINT_DOWN_H
