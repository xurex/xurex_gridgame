#ifndef POINT_RIGHT_H
#define POINT_RIGHT_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"
/**
Class that creates a Point object that goes Right
@author Rex Xu
*/
class PointRight: public Thing {

  public:
    /**Constructor*/
    PointRight ();
    /**Destructor*/
    ~PointRight() { delete pixMap; }
    /**Moves the Point object right*/
    void move();
    
};

#endif //POINT_RIGHT_H
