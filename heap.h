#ifndef HEAP_H
#define HEAP_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"
/**
This class creates an object similar to PointDown but is created based on X coordinate
@author Rex Xu
*/
class Heap: public Thing {

  public:
    /**Constructor*/
    Heap ();
    /**
    Constructor
    @param nx The x coordinate that heap falls from*/
    Heap (int nx);
    /**Destructor*/
    ~Heap() { delete pixMap; }
    /**Moves the heap down the scene*/
    void move();
    private:
  /**
    X coordinate in scene*/
    int x;
    /**
    Y coordinate in scene*/
    int y;
    /**
    Holds the image of the thing*/
    QPixmap *pixMap;
    
};

#endif //HEAP_H
