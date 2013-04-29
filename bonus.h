#ifndef BONUS_H
#define BONUS_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"
/**
Class that moves similar to Ladebug and creates and object that enters randomly
@author Rex Xu*/
class Bonus: public Thing {

  public:
    /**Constructor*/
    Bonus ();
    /**Destructor*/
    ~Bonus() { delete pixMap; }
    /**Moves the object in a direction depending on side*/
    void move(); 
  private:

    /**Tracks which side the object entered from*/
    int side; //left, right, up, down (1-4)
};

#endif //BONUS_H
