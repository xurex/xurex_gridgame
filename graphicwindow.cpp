#include "graphicwindow.h"

GraphicWindow::GraphicWindow(QWidget* x) : QGraphicsView(x)
{
    //This sets the size of the window and gives it a title.
    this->setFixedSize( 650, 560 );
    this->setWindowTitle( "Comp Sci Craze" );
    
    scene=new QGraphicsScene();
    setScene(scene);
    
}

GraphicWindow::~GraphicWindow() {delete scene;}

