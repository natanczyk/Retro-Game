#include <iostream>
#include "bipbop.h"
#include "block.h"
#include "paddle.h"
#include <QGraphicsPixmapItem>
#include "ball.h"
using namespace std;


Bipbop::Bipbop(QWidget *parent): QGraphicsView(parent)
{
//creating a window
    scene = new QGraphicsScene(0,0,640,480);
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);


//boundaries of the scene
    QPen mypen = QPen(Qt::black);
    QLineF TopLine(scene ->sceneRect().topLeft(), scene->sceneRect().topRight());
    QLineF LeftLine(scene ->sceneRect().topLeft(), scene->sceneRect().bottomLeft());
    QLineF RightLine(scene ->sceneRect().topRight(), scene->sceneRect().bottomRight());
    QLineF BottomLine(scene ->sceneRect().bottomLeft(), scene->sceneRect().bottomRight());
    scene->addLine(TopLine, mypen);
    scene->addLine(LeftLine, mypen);
    scene->addLine(RightLine, mypen);
    scene->addLine(BottomLine, mypen);

//ball movement

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer -> start(2);


// game background
    QGraphicsPixmapItem * pixItem = new QGraphicsPixmapItem(QPixmap(":/obrazki/dziwny.jpg"));
    scene -> addItem(pixItem);
    pixItem -> setPos(-300, -30);

//JUST BUILDING BLOCKS

    srand(time(NULL));
    for (int i=5; i<=600; i+=45){
        for (int j=5; j<=200; j+=45){
            int random = rand()%10;
            int random2= rand()%10;

            if (random>=5){
                Block* block = new Block();
                this->numOfBlocks+=1;
                (*block).Blocklife(random2);

                block->setPos(i,j);
                scene->addItem(block);
            }
        }
    }



//BUILDING A BALL

    Ball * ball = new Ball();
    ball->Speedx();
    ball->Speedy();
    scene->addItem(ball);


//BUILDING A PADDLE and mousetracking

    setMouseTracking(true);
    Paddle* paddle = new Paddle();
    paddle->setPos(270,420);
    scene->addItem(paddle);
    paddle->grabMouse();
}
















