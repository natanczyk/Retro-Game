#ifndef AIPADDLE_H
#define AIPADDLE_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "ball.h"

//PADDLE FOLLOWING BALL MOVEMENT (NOT WORKING)
//attempts to make AI using brute force

class Aipaddle: public QGraphicsRectItem
{


private:
    int height;
    int width;
    double speedx;
    friend class Ball;


public:

    Aipaddle(QGraphicsItem *parent=nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);



    int Height(int height = 20){
        this -> height = height;
        return height;
    }
    int Width(int width=120){
        this -> width = width;
        return width;
    }

protected:
    void advance(int phase);



};

#endif // AIPADDLE_H

