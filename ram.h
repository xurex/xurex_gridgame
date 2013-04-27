#ifndef RAM_H
#define RAM_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"

class Ram: public Thing {

  public:
    Ram ();
    ~Ram() { delete pixMap; }
    
    void move();
    int getX();
    //virtual void move() = 0;  //virtual function. Class Thing is abstract. For a reason.
  private:  //Every thing has a origin and a velocity – maybe 0
    int x;
    int y;
    QPixmap *pixMap;  //Good idea. Explain later.
    
};

#endif //RAM_H
