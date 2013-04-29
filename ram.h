#ifndef RAM_H
#define RAM_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"
/**
Creates a ram object that will move across the top of the screen
@author Rex Xu*/
class Ram: public Thing {

  public:
    /**Constructor*/
    Ram ();
    /**Destructor*/
    ~Ram() { delete pixMap; }
    /**Moves the ram left across the scene*/
    void move();
    /**
    Returns x coordinate
    @return x*/
    int getX();
};

#endif //RAM_H
