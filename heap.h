#ifndef HEAP_H
#define HEAP_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"

class Heap: public Thing {

  public:
    Heap ();
    Heap (int nx);
    ~Heap() { delete pixMap; }
    
    void move();
    //virtual void move() = 0;  //virtual function. Class Thing is abstract. For a reason.
  private:  //Every thing has a origin and a velocity – maybe 0
    int x;
    int y;
    QPixmap *pixMap;  //Good idea. Explain later.
    
};

#endif //HEAP_H
