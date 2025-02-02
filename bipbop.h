#ifndef BIPBOP_H
#define BIPBOP_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <Qtcore>
#include <QtGui>
#include <QTimer>
#include "ball.h"




class Bipbop : public QGraphicsView
{
private:
    //timer will be used to update the ball every n miliseconds
    QTimer *timer;
    int numOfBlocks=0;
    friend class Ball;

public:

    Bipbop(QWidget *parent = nullptr);
    QGraphicsScene* scene;



};
#endif // BIPBOP_H
