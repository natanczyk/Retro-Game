#include "block.h"
#include <QBrush>
#include "bipbop.h"



Block::Block(QGraphicsItem *parent) :QGraphicsRectItem(parent)
{
    setRect(0,0,40,40);
}


// life and colour of a block
void Block::Blocklife(int random){

    if (random >= 0 && random <= 3){
        this->life = 1;

    }
    else if (random<=7){
        this->life = 2;

    }
    else {
        this->life = 3;

    }
    //giving color after life initialization
    Blockcolor();




}


void Block::Blockcolor(){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    if (this->life==1){
        brush.setColor(Qt::green);


    }
    else if (this->life==2){
        brush.setColor(Qt::yellow);

    }
    else {
        brush.setColor(Qt::red);


    }
    setBrush(brush);


}




