#include "bullet.h"

bullet::bullet(player*t,QTimer *f,int x,int y)
{   targetp=t;vx=x;
    change=f;vy=y;
    pixmap=new QPixmap(":/src/bullet2.png");
    connect(f,SIGNAL(timeout()),this,SLOT(move()));
    v.push_back(QPointF(0,0));
    v.push_back(QPointF(10,0));
    v.push_back(QPointF(10,10));
    v.push_back(QPointF(0,10));
    path.addPolygon(QPolygonF(v));
    flag=1;
}
bullet::bullet(enemy*t,QTimer *f)
{   targete=t;
    change=f;
    pixmap=new QPixmap(":/src/bullet.png");
    connect(f,SIGNAL(timeout()),this,SLOT(move()));
    v.push_back(QPointF(0,0));
    v.push_back(QPointF(10,0));
    v.push_back(QPointF(10,10));
    v.push_back(QPointF(0,10));
    path.addPolygon(QPolygonF(v));
    vx=0;
    vy=-8;
    flag=0;
}
QRectF bullet::boundingRect() const{
  return path.boundingRect();
}
QPainterPath bullet:: shape()const{
return path;
}
void bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
painter->drawPixmap(path.boundingRect(),(*pixmap).scaled(11,11),path.boundingRect());
}
void bullet::move(){
    if(pos().y()<=0||pos().y()>=500||pos().x()>=300||pos().x()<=0){
        this->scene()->removeItem(this);
        delete this;return;
    }
    else if(flag==1){
    if(this->collidesWithItem(targetp)){
        targetp->collide();
        this->scene()->removeItem(this);
        delete this;return;
    }
    }
    else if(flag==0){
    if(this->collidesWithItem(targete)){
        targete->collide();
        this->scene()->removeItem(this);
        delete this;return;
    }
    }
    moveBy(vx,vy);
}
