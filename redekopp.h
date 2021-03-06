#ifndef REDEKOPP_H
#define REDEKOPP_H

#include "thing.h"

/**
The protagonist class. Has four moves functions for each direction. Tracks lives.
@author Rex Xu
*/
class Redekopp: public Thing {

  public:
    /** 
    Constructor
    @param pm Pointer to pixmap
    @param nx Sets x coordinate of Redekopp
    @param ny Sets y coordinate of Redekopp
    @return NULL
    */
    Redekopp (QPixmap *pm, int nx, int ny);
    /** Destructor*/
    ~Redekopp() { }
    /** Empty function required because of inheritance*/
    void move();
    /** Moves Redekopp right a grid*/
    void move_left();
    /** Moves Redekopp right a grid*/
    void move_right();
    /** Moves Redekopp up a grid*/
    void move_up();
    /** Moves Redekopp down a grid*/
    void move_down();
    /**
    Decrements life*/
    void lifeDown();
    /**
    Increments life*/
    void lifeUp();
    /**
    Sets the number of lives back to five*/
    void lifeReset();
    /**
    @return life The number of lives left*/
    int getLife();
    /**
    Used to locate Redekopp object
    @return x*/
    int getX();
    /**
    Used to locate Redekopp object
    @return y*/
    int getY();
    /**
    Used to set blink to five*/
    void setBlink() {blink=30;}
    /**
    Used to decrement blink*/
    void decBlink() {blink--;}
    /**
    Used to get blink, checks to see if invincible
    @return blink*/
    int getBlink() {return blink;}
    /**
    Resets blink to zero for restart game*/
    void resBlink() {blink=0;}
 private:
    /**
    Tracks the number of lives left*/
    int life;        
    /**
    Used to create temporary invincibility after collision*/
    int blink;
};

#endif //REDEKOPP_H
