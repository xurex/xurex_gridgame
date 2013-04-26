#ifndef THING_H
#define THING_H
#include <QGraphicsPixmapItem>
#include <iostream>
using namespace std;

class Thing: public QGraphicsPixmapItem {
public:
    Thing () { }
    virtual void move() = 0;  //virtual function. Class Thing is abstract. For a reason.
private:  //Every thing has a origin and a velocity – maybe 0
    int x;
    int y;
    QPixmap *pixMap;  //Good idea. Explain later.
};

#endif //THING_H
