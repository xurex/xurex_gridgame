#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QTimeLine>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QKeyEvent>
#include <QWidget>
#include <QtGui/QApplication>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "grid.h"
#include "thing.h"
#include "redekopp.h"
#include "graphicwindow.h"
#include "point_up.h"
#include "point_down.h"
#include "point_left.h"
#include "point_right.h"
#include "ladebug.h"
#include "bonus.h"
#include "tree.h"

#define WINDOW_MAX_X 500
#define WINDOW_MAX_Y 500
#define DIM 8
#define SIZE 64

class Main : public QMainWindow {
    Q_OBJECT
    
  public:

    explicit Main(QApplication *);
    ~Main();

    //void show();
    
  private:

    /**Pointer to QApp needed to quit game*/
    QApplication *app;
    /**GraphicWindow consists of scene and view*/
    GraphicWindow *view;
    /**PushButton that starts the game*/
    QPushButton *start;
    /**PushButton that exits application*/
    QPushButton *quit;
    /**displays messages to user*/
    QLabel *message;
    /**Timer used to run animations and game*/
    QTimer *timer;
    /**Background of scene*/
    QPixmap *background;
    /**checks to see if the game is started*/
    bool inPlay;
    /**checks to see if the game is paused*/
    bool paused;
    /**Array of QGraphicsRectItem * to form grid*/
    Grid** board;
    /**Counter used throughout main*/
    unsigned int count;
    /**Image of protagonist*/
    QPixmap *redekopp;
    /**Object of protagonist*/
    Redekopp *protagonist;
    /**Vector of Pointer things*/
    std::vector<Thing*> pointers;
    /**Stores index of tree in vector*/
    int tree;
    
  protected:
  	void keyPressEvent( QKeyEvent *e );
    
  public slots:
	
	void startGame();
	void exitGame();
	void handleTimer();
};

#endif // MAIN_H
