#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QTimeLine>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QtGui/QApplication>
#include <QKeyEvent>
#include <cctype>
#include "grid.h"
#include "redekopp.h"

#define WINDOW_MAX_X 500
#define WINDOW_MAX_Y 500
#define DIM 8
#define SIZE 64

class Main : public QWidget {
    Q_OBJECT
    
  public:

    explicit Main(QApplication *);
    ~Main();

    void show();
    
  protected:

    void keyPressEvent( QKeyEvent *e );
    
  private:

    /**Pointer to QApp needed to quit game*/
    QApplication *app;
    /**GraphicsScene of the application*/
    QGraphicsScene *scene;
    /**GraphicsView of the applicatoin*/
    QGraphicsView *view;
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
    /**Array of QGraphicsRectItem * to form grid*/
    Grid** board;
    /**Counter used throughout main*/
    int count;
    /**Image of protagonist*/
    QPixmap *redekopp;
    /**Object of protagonist*/
    Redekopp *protagonist;
    
  public slots:
	
	void startGame();
	void exitGame();
	
};

#endif // MAIN_H
