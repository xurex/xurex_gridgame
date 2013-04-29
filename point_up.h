#ifndef POINT_UP_H
#define POINT_UP_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"
/**
Class that creates a Point object that goes up
@author Rex Xu
*/
class PointUp: public Thing {

  public:
    /**Constructor*/
    PointUp ();
    /**Destructor*/
    ~PointUp() { delete pixMap; }
    /**Moves the PointUp object up the scene*/
    void move();
};

#endif //POINT_UP_H
