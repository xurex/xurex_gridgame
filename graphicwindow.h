#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>

class GraphicWindow : public QGraphicsView
{
  public:
  	GraphicWindow(QWidget*);
	~GraphicWindow();
  public:
  	QGraphicsScene *scene;
  	
};

#endif //GRAPHICWINDOW_H
