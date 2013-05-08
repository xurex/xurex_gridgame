#ifndef DICTIONARY_H
#define DICTIONARY_H

#include"thing.h"
/**
Class that creates a Dictionary object that moves up and down along the left border. Tracks the protagonist.
@author Rex Xu
*/

class Dictionary: public Thing {

  public:
    /**Constructor*/
    Dictionary ();
    /**Destructor*/
    ~Dictionary() { delete pixMap; }
    /**
    Moves the Dictionary object up or down
    @param loc The y location of protagonist
    */
    void move(int);
    /**
    Necessary move function to satisfy Thing
    */
    void move() { }
    /**
    Used to locate Dictionary object and to create Buckets
    @return y*/
    int getY() {return y;}    
};

#endif //DICTIONARY_H
