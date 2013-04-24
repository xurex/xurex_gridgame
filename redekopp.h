#ifndef REDEKOPP_H
#define REDEKOPP_H

#include<iostream>
#include<QGraphicsPixmapItem>
using namespace std;

class Redekopp: public QGraphicsPixmapItem {

  public:
    Redekopp (QPixmap *pm, int nx, int ny);
    ~Redekopp() {delete this;}
    //virtual void move() = 0;  //virtual function. Class Thing is abstract. For a reason.
    void move_left();
    void move_right();
    void move_up();
    void move_down();
  private:  //Every thing has a origin and a velocity – maybe 0
    int x;
    int y;
    int vX;
    int vY;
    QPixmap *pixMap;  //Good idea. Explain later.
    
};

#endif //REDEKOPP_H
