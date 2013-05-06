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
    /**
    Constructor
    @param nx Starting x coordinate of Thing
    @param image The location of image to be loaded
    */
    PointDown (int, QString);
    /**Destructor*/
    ~PointDown() { delete pixMap; }
    /**Moves the Point object down*/
    void move();    
};

#endif //POINT_DOWN_H
