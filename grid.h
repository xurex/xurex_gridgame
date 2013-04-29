#ifndef GRID_H
#define GRID_H
#include <QGraphicsRectItem>
#include <QBrush>

/**
  This class maintains the location and size of a QGraphicsRectItem.
  Used to form the 8x8 playing grid.
  @author Rex Xu
  */
class Grid : public QGraphicsRectItem {
public:
    /**
    Constructor
    @param nx X coordinate
    @param ny Y coordinate
    @param w Width of grid
    @param h Height of grid
    */
    Grid(double nx, double ny, double w, double h);
    /**
    Destructor*/
    ~Grid();
};

#endif // GRID_H
