#include "graphicwindow.h"

GraphicWindow::GraphicWindow(QWidget* x) : QGraphicsView(x)
{
    //This sets the size of the window and gives it a title.
    this->setFixedSize( 525, 525 );
    this->setWindowTitle( "Comp Sci Craze" );
    
    scene=new QGraphicsScene();
    setScene(scene);
}

GraphicWindow::~GraphicWindow() {delete scene;}

