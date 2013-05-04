#ifndef THING_H
#define THING_H
#include <QGraphicsPixmapItem>
#include <iostream>
#include <vector>
using namespace std;

/**
	Thing class that is the parent of all objects
	Inherits for QGraphicsPixmapItem
	@author Rex Xu
*/
class Thing: public QGraphicsPixmapItem {
public:
    /**
    Constructor (empty) */
    Thing () { }
    /**
    Virtual move function*/
    virtual void move() = 0;
    /**
    Checks to see if needs to be deleted (off of grid)*/
    bool deleteMe;
    /**
    Checks to see if the thing is bad for the player
    Also tells program which good object collides (1: bonus, 2:bug, etc.)*/
    int isGood;
protected:  //Every thing has a origin and a velocity – maybe 0
    /**
    X coordinate in scene*/
    int x;
    /**
    Y coordinate in scene*/
    int y;
    /**
    Holds the image of the thing*/
    QPixmap *pixMap;
};

#endif //THING_H
