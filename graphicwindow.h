#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>

/**
This class encapsulates the scene and view in one class
@author Rex Xu
*/
class GraphicWindow : public QGraphicsView
{
  public:
  	/**
  	Constructor
  	@param x The parent of the GraphicWindow*/
  	GraphicWindow(QWidget*);
  	/**Destructor*/
	~GraphicWindow();
  public:
  	/**
  	The required GraphicsScene used in Qt*/
  	QGraphicsScene *scene;
  	
};

#endif //GRAPHICWINDOW_H
