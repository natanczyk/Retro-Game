#include "ball.h"
#include <QTimer>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include "bipbop.h"
#include "paddle.h"
#include "block.h"
#include <iostream>
using namespace std;








Ball::Ball(QGraphicsItem *parent)
{
    //ball's starting position
    setPos(mapToParent(startx,starty));
}

//checking ball life, if it is equal to 0 the game ends
void Ball::hp(){
    this->life-=1;
    if(this->life<=0){
        QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/obrazki/smutnydziwny.jpg"));
        scene() -> addItem(pixItem);
        pixItem -> setPos(-10, -100);
    }

//function in case of winning, however, it is working properly only if the grid is full of blocks
}
void Ball::winner(){
    Bipbop bipbopobject;
    if(numBrokenBlocks>=bipbopobject.numOfBlocks){
        QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/obrazki/gigachad.jpg"));
        scene() -> addItem(pixItem);
        pixItem -> setPos(-10, -100);
        this->a = false;
    }
}


//initializing rendering speed
qreal Ball::Speedx(){    
    double rad= angle*3.14159/180;
    this->speedx= ceil(speed* cos(rad)*100)/100;
    return speedx;
}

qreal Ball::Speedy(){
    double rad= angle*3.14159/180;
    this->speedy= ceil(speed* sin(rad)*100)/100;
    return speedy;
}


//initializing angles in case of paddle collision
void Ball::addAngle(double angle){
    if (this->angle + angle < 180){
        this->angle+=angle;
    }
}

void Ball::substractAngle(double angle){
    if (this->angle - angle >0){
        this->angle-=angle;
    }
}


QRectF Ball::boundingRect() const
{
    //ball is based on rectangle with a circle inside
    return QRect(0,0,20,20);

}


//this function is called in every ball update
void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec= boundingRect();
    QBrush Brush(Qt::white);
    painter->setBrush(Qt::blue);

    if (scene()->collidingItems(this).isEmpty()){
        //no collision

    }
    else{
        //collision
        bondcollision();
        paddlecollision();
        blockcollision();
    }
    painter -> drawEllipse(rec);
}


void Ball::bondcollision()
{
    QPointF coords = this->pos();
        if (coords.x()<=0 && speedx>0){
                this->speedx = -speedx;
        }
        if (coords.x()>=620 && speedx<0){
                this->speedx = -speedx;
        }
        if (coords.y()<=0 && speedy>0){
                this->speedy = -speedy;
        }
        if (coords.y()>=470 && speedy<0){
            //setting the ball life everytime it touches the bottom boundary
            hp();
            //ball returning to initial position
            this->angle=45;
            speedx=Speedx();
            speedy=Speedy();
            setPos(startx,starty);
        }

}




void Ball::paddlecollision(){
    QList cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i){
        Paddle* paddle = dynamic_cast<Paddle*>(cItems[i]);
        if (paddle){
            double ballx = pos().x();
            double bally = pos().y();
            double paddlex = paddle -> pos().x();
            double paddley = paddle -> pos().y();
            double paddleWidth=paddle -> Width();

            //angle differs when ball is coming from right or left so I have to control it (a or 180-a)
            if (speedy<0 && bally+20<=paddley ){
                if (ballx>=paddlex && ballx<=paddlex+(0.8*paddleWidth)){
                    this -> speedy = -1 * speedy;
                }

                else if (ballx+20>=paddlex && ballx<paddlex){
                    if (speedx<0 && angle<90){
                        this->angle=180-angle;
                    }

                    if (speedx>0 && angle>90){
                        this->angle=180-angle;
                    }

                    substractAngle(22.5);
                    Speedx();
                    Speedy();
                }

                else if (ballx>paddlex+(0.8*paddleWidth) && ballx<=paddlex+paddleWidth){
                    if (speedx>0 && angle>90){
                        this->angle=180-angle;
                    }

                    if (speedx<0 && angle<90){
                        this->angle=180-angle;
                    }

                    addAngle(22.5);
                    Speedx();
                    Speedy();
                }
                this->score+=10;
            }
            return;
        }
    }
}

void Ball::blockcollision(){
    QList cItems = collidingItems();
        for (size_t i = 0, n = cItems.size(); i < n; ++i){
            Block* block = dynamic_cast<Block*>(cItems[i]);

        if (block){
            //one additional pixel for bias
            double height = 40;
            double width = 40;
            double ballheight = 20;
            double ballwidth = 20;
            double ballx = pos().x();
            double bally = pos().y();
            double blockx = block->pos().x();
            double blocky = block->pos().y();
//            this is in case of winning but still doesn't work. I had to include this lines in every if statement below
//            if (block->getLife()==1){
//                this->numBrokenBlocks+=1;
//            }


            // I had to repeat code in every if statement because collision is checked for every pixel. If delete fuction was be written only once at the end, the blocks would be destroyed without ball bounce. (

            // collides from bottom
            if ((bally >= blocky+height-1) && speedy>0){
                speedy = -1 * speedy;

                if ((block->getLife())==1){
                    // counting deleted blocks to see if there is winning position
                    numBrokenBlocks++;
                    block->currBlockLife();

                    //deleting block
                    delete block;
                }

                else{
                    block->currBlockLife();
                    block->Blockcolor();
                }
            }

            // collides from top
            else if ((bally  <= blocky - ballheight+1) && speedy<0){
                speedy = -1 * speedy;
                if ((block->getLife())==1){
                    numBrokenBlocks+=1;
                    cout<<numBrokenBlocks<<endl;
                    block->currBlockLife();
                    delete block;
                }

                else{
                    block->currBlockLife();
                    block->Blockcolor();
                }
            }

            // collides from right
            else if ((ballx >= blockx + width-1) && speedx>0 ){
                speedx = -1 * speedx;

                if ((block->getLife())==1){
                    numBrokenBlocks+=1;
                    cout<<numBrokenBlocks<<endl;
                    block->currBlockLife();
                    delete block;
                }

                else{
                    block->currBlockLife();
                    block->Blockcolor();
                }
            }

            // collides from left
            else if ((ballx  <= blockx -  ballwidth+1) && speedx<0){
                speedx = -1 * speedx;

                if ((block->getLife())==1){
                    numBrokenBlocks+=1;
                    cout<<numBrokenBlocks<<endl;
                    block->currBlockLife();
                    delete block;
                }

                else{
                    block->currBlockLife();
                    block->Blockcolor();
                }
            }
        }
    }
//    Breaking all blocks gives a win
    winner();
}

//updating the ball
void Ball::advance(int phase)
{
    if(!phase){
        return;
    }

    //I wanted to implement winning but something goes wrong. If there was winning situation 'a' would turn false
    if (this->a=true){
        if(this->life>0){
             setPos(mapToParent(-speedx,-speedy));
        }
        else{
            return;
        }
    }

    else{
        return;
    }
}
