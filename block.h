#ifndef BLOCK_H
#define BLOCK_H
#include <QGraphicsRectItem>
#include <QBrush>
#include "bipbop.h"

class Block: public QGraphicsRectItem{

private:
    int life;
    int x;
    int y;
    friend class Ball;

public:

    Block(QGraphicsItem* parent=NULL);


    // to know when to delete a block
    int getLife(){
        return this->life;
    }
    // lowering block life
    void currBlockLife(){
        this->life-=1;
    }

    //initializing block life at the beginning
    void Blocklife(int random);
    void Blockcolor();


};
#endif // BLOCK_H
