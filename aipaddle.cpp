#include "aipaddle.h"
#include <QBrush>
#include "ball.h"

//PADDLE FOLLOWING BALL MOVEMENT (NOT WORKING)
Aipaddle::Aipaddle(QGraphicsItem *parent) :QGraphicsRectItem(parent)
{

//        setPos(mapToParent(270,420));
    setRect(0,0,120,20);



}
QRectF Aipaddle::boundingRect() const
{


        return QRect(0,0,120,20);

}
void Aipaddle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QRectF rec= boundingRect();
        QBrush Brush(Qt::white);
        painter->setBrush(Qt::black);
        painter -> drawRect(rec);
}



//I was trying to set speedx = ball->speedx in ball class

void Aipaddle::advance(int phase)
{


        if(!phase){
            return;

        }
        else{
//            Ball ball;


            setPos(mapToParent(speedx,0));
         }


}
