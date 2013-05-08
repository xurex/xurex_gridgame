#ifndef COFFEE_H
#define COFFEE_H

#include"thing.h"
/**
Class that creates a Coffee object that tracks protagonist within grids. Collision speeds up game.
@author Rex Xu
*/

class Coffee: public Thing {

  public:
    /**Constructor*/
    Coffee ();
    /**Destructor*/
    ~Coffee() { delete pixMap; }
    /**
    Moves the Coffee object toward the protagonist
    @param px The x location of protagonist
    @param py The y location of protagonist
    */
    void move(int, int);
    /**
    Necessary move function to satisfy Thing
    */
    void move() { }   
};

#endif //DICTIONARY_H
