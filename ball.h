#ifndef BALL_H
#define BALL_H
#include <QGraphicsItem>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include "bipbop.h"


class Ball : public QGraphicsItem
{



private:
    double angle=45;
    qreal speed=1;
    qreal speedx;
    qreal speedy=1;
    //basically ball life tells us about game life
    int life =3;
    int startx = 290;
    int starty = 400;
    int numBrokenBlocks=0;
    int score=0;
    bool a= true;




public:
    Ball(QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //initializing ball render speed
    qreal Speedx();
    qreal Speedy();

    //just in case of winning, however, it doesn't work
    void winner();



    //initializing bounce angle
    void addAngle(double angle);
    void substractAngle(double angle);

    //initializing collisions
    void bondcollision();
    void paddlecollision();
    void blockcollision();

    //lifes you have in the game
    void hp();


//function responsible for ball update
protected:
    void advance(int phase);




};

#endif // BALL_H
