#include "paddle.h"
#include <QBrush>



Paddle::Paddle(QGraphicsItem *parent) :QGraphicsRectItem(parent)
{
        setRect(0,0,120,20);
        QBrush brush;
        //solidpattern make blocks more 'solid' and 'consistent' in shape
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::black);
        setBrush(brush);
}


void Paddle::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
        // follow mouse's x pos
        double mouseX = mapToScene(event->pos()).x();
        setPos(mouseX,420);
}






