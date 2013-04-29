#ifndef POINT_DOWN_H
#define POINT_DOWN_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"
/**
Class that creates a Point object that goes down
@author Rex Xu
*/

class PointDown: public Thing {

  public:
    /**Constructor*/
    PointDown ();
    /**Destructor*/
    ~PointDown() { delete pixMap; }
    /**Moves the Point object down*/
    void move();    
};

#endif //POINT_DOWN_H
