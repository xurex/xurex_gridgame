#ifndef REDEKOPP_H
#define REDEKOPP_H

#include "thing.h"

class Redekopp: public Thing {

  public:
    Redekopp (QPixmap *pm, int nx, int ny);
    ~Redekopp() { }
    void move();
    void move(int);
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    void lifeDown();
    int getX();
    int getY();
  private:  //Every thing has a origin and a velocity – maybe 0
    int x;
    int y;
    int life;
    QPixmap *pixMap;  //Good idea. Explain later.
    
};

#endif //REDEKOPP_H
