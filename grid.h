#ifndef GRID_H
#define GRID_H
#include <QGraphicsRectItem>
#include <QBrush>

/**
  This class maintains the location and size of a QGraphicsRectItem.
  It is easier to do the arithmetic with this data, and then update the position
  separately, then to extract coordinates from the QRectF that is contained within
  the QGraphicsRectItem
  */
class Grid : public QGraphicsRectItem {
public:
    Grid(double nx, double ny, double w, double h);
    ~Grid();
};

#endif // GRID_H
