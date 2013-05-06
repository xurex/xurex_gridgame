#ifndef POINT_LEFT_H
#define POINT_LEFT_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"
/**
Class that creates a Point object that goes left
@author Rex Xu
*/
class PointLeft: public Thing {

  public:
    /**Constructor*/
    PointLeft ();
    /**
    Constructor
    @param ny The starting y coordinate of point object
    @param image The location of the image to be loaded
    */
    PointLeft (int, QString);
    /**Destructor*/
    ~PointLeft() { delete pixMap; }
    /**Moves Point object left*/
    void move();
    
};

#endif //POINT_LEFT_H
