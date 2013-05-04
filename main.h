#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
#include <QTimer>
#include <QTimeLine>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>
#include <QKeyEvent>
#include <QWidget>
#include <QtGui/QApplication>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <QLineEdit>
#include <QFormLayout>
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
#include "ram.h"
#include "heap.h"

#define WINDOW_MAX_X 500
#define WINDOW_MAX_Y 500
#define DIM 8
#define SIZE 64

/**
   Class that inherits from QMainWindow. Used to implement game play.
   @author RexXu
*/

class Main : public QMainWindow {
    Q_OBJECT
    
  public:
    /**
    Constructor
    @param mainapp Pointer to QApp so that Main can exit
    */
    explicit Main(QApplication *);
    /**
    Destructor
    */
    ~Main();
    /**
    Creates a PointUp object
    */
    void makeUp();
    /**
    Creates a PointDown object
    */
    void makeDown();
    /**
    Creates a PointLeft object
    */
    void makeLeft();
    /**
    Creates a PointRight object
    */
    void makeRight();
    /**
    Clears the array of things. Deallocates memory.
    */
    void clear();
    /**
    Displays the current score to the QLabel score
    */
    void setScore();
    /**
    Displays the current lives to the QLabel life
    */
    void setLife();
    
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
    QLabel *score;
    /**QString used to set QLabel score*/
    QString sscore;
    /**QString used to set QLabel lives*/
    QString slives;
    /**Displays the number of lives*/
    QLabel *lives;
    /**Displays the name of player*/
    QLabel *name;
    /**Used to get input name*/
    QLineEdit *nameIn;
    /**Timer used to run animations and game*/
    QTimer *timer;
    /**Checks to see if the game is started*/
    bool inPlay;
    /**Checks to see if the game is paused*/
    bool paused;
    /**Checks to see if game is over*/
    bool gameover;
    /**Array of QGraphicsRectItem * to form grid*/
    Grid** board;
    /**Counter used throughout main*/
    unsigned int count;
    /**Image of protagonist*/
    QPixmap *redekopp;
    /**Instructions page pixmap*/
    QPixmap *instructions;
    /**Instructions page pixmapitem*/
    QGraphicsPixmapItem *instructionpage;
    /**Object of protagonist*/
    Redekopp *protagonist;
    /**Vector of Pointer things*/
    std::vector<Thing*> pointers;
    /**Pointer to the single ram that is used*/
    Ram *ram;
    /**Checks to see if the ram is running and tracks distance*/
    int runningRam;
    /**Sets time interval*/
    int speed;
    /**Sets the score*/
    int intscore;
    /**Widget used to setCentralWidget*/
    QWidget *window;
    
  protected:
  	/**
  	Handles key presses for WASD, P, C
  	Exits if the game is paused or over*/
  	void keyPressEvent( QKeyEvent *e );
    
  public slots:
	/**
	Starts the game by forming a grid, starting the timer, and created the character. Also used to restart the game. Sets all needed variables to zero or false.*/
	void startGame();
	/**
	Exits the game by using QApp **/
	void exitGame();
	/**
	Moves all the items in the array of things. Increases score. Handles collisions. Creates objects after predetermined periods of time.*/
	void handleTimer();
};

#endif // MAIN_H
