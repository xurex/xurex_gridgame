#ifndef TREE_H
#define TREE_H

#include<stdlib.h>
#include<time.h>
#include"thing.h"
/**
Creates a stationary tree at a random location
@author Rex Xu*/
class Tree: public Thing {

  public:
    /**Constructor*/
    Tree ();
    /**Destructor*/
    ~Tree() { delete pixMap; }
    /**Increments deathcount*/
    void move();
    //virtual void move() = 0;  //virtual function. Class Thing is abstract. For a reason.
 private:
    /**When deathcount is 100, tree is deleted. Incremented by move*/
    int deathCount; 
};

#endif //TREE_H
