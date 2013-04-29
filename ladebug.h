#ifndef LADEBUG_H
#define LADEBUG_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"

/**
Class that holds the ladebug. Randomly sends the ladebug across the screen
@author Rex Xu
*/

class Ladebug: public Thing {

  public:
    Ladebug ();
    ~Ladebug() { delete pixMap; }
    /** Uses side to determine which direction to move*/
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
    /**Tracks which side the object entered from*/
    int side; //left, right, up, down (1-4)

    
};

#endif //LADEBUG_H
