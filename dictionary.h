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
};

#endif //DICTIONARY_H
