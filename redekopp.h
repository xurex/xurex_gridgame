#ifndef REDEKOPP_H
#define REDEKOPP_H

#include<iostream>
#include<QGraphicsPixmapItem>
#include<QPointF>
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
    int getX();
    int getY();
  private:  //Every thing has a origin and a velocity – maybe 0
    int x;
    int y;
    QPixmap *pixMap;  //Good idea. Explain later.
    
};

#endif //REDEKOPP_H
