#include "myview.h"

myview::myview(QTimer*f,int opt)
{

 frame=f;
 scene=new QGraphicsScene();
 scene->setSceneRect(0,0,300,500);

 p=new player(f,opt);
 scene->addItem(p);
 e=new enemy(f);
 scene->addItem(e);
 p->setFocus();
 p->settarget(e);
 e->settarget(p);
 setScene(scene);
 setFixedSize(305,505);
 show();

}
void myview::drawBackground(QPainter *painter, const QRectF &rect){
painter->drawPixmap(0,0,305,505,QPixmap(":/src/stage.jpg"),160,0,320,480);
}
