#ifndef PADDLE_H
#define PADDLE_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QTimer>

class Paddle: public QGraphicsRectItem
{


private:
    int height;
    int width;


public:

    Paddle(QGraphicsItem * parent=NULL);

    //necessary for mouse tracking
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

    int Height(int height = 20){
        this -> height = height;
        return height;
    }
    int Width(int width=120){
        this -> width = width;
        return width;
    }




};

#endif // PADDLE_H
