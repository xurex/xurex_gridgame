#ifndef TREE_H
#define TREE_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"

class Tree: public Thing {

  public:
    Tree ();
    ~Tree() { delete pixMap; }
    
    void move();
    void setDelete();
    //virtual void move() = 0;  //virtual function. Class Thing is abstract. For a reason.
  private:  //Every thing has a origin and a velocity – maybe 0
    int x;
    int y;
    int deathCount;
    QPixmap *pixMap;  //Good idea. Explain later.
    
};

#endif //TREE_H
