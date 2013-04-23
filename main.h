#ifndef MAIN_H
#define MAIN_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTimeLine>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QtGui/QApplication>

#define WINDOW_MAX_X 500
#define WINDOW_MAX_Y 500

class Main : public QWidget {
    Q_OBJECT
    
public:

    explicit Main(QApplication *);
    ~Main();

    void show();
    
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
    /**Timer used to run animations and game*/
    QTimer *timer;
    /**checks to see if the game is started*/
    bool inPlay;
    
public slots:
	
	void startGame();
	void exitGame();
	
};

#endif // MAIN_H
