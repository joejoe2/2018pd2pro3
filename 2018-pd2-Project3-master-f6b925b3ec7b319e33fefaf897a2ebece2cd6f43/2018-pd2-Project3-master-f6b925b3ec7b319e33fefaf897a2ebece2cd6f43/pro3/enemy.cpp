#include "enemy.h"
#include<ctime>
#include<cstdlib>
#include <bullet.h>
#include<player.h>
enemy::enemy(QTimer*f)
{   srand(time(NULL));fr=f;
    v.push_back(QPointF(0,0));
    v.push_back(QPointF(64,0));
    v.push_back(QPointF(64,64));
    v.push_back(QPointF(0,64));
    path.addPolygon(QPolygonF(v));
    setPos(150,50);
    vx=3;vy=3;hp=1000;
    change=new QTimer();
    change->setInterval(1000);
    connect(change,SIGNAL(timeout()),this,SLOT(movestate()));
    connect(f,SIGNAL(timeout()),this,SLOT(move()));
    change->start();
}
QRectF enemy::boundingRect() const{
  return path.boundingRect();
}
QPainterPath enemy:: shape()const{
return path;
}
void enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
painter->drawPixmap(path.boundingRect(),QPixmap(":/src/enemy.png").scaled(64,64),path.boundingRect());
}
void enemy::movestate(){

    if(rand()%2==1){
        vx=vx;
    }
    else{vx=-vx;}
    if(rand()%2==1){
        vy=vy;
    }
    else{vy=-vy;}
    int m=rand()%5;
    if(m==0){
    for(int i=0;i<10;++i){
    bullet *b=new bullet(pa,fr,i-10,10);
    this->scene()->addItem(b);
    b->setPos(this->pos().x()+33,this->pos().y()+33);
    }}
    else if(m==2){
        for(int j=0;j<3;++j){
        for(int i=0;i<10;++i){
        bullet *b=new bullet(pa,fr,(i*2-10)*(j+1)/3,(10)*(j+1)/3);
        this->scene()->addItem(b);
        b->setPos(this->pos().x()+33,this->pos().y()+33);
        }
    }
    }

    else if(m==3){
    for(int i=0;i<10;++i){
    bullet *b=new bullet(pa,fr,i+5,10);
    this->scene()->addItem(b);
    b->setPos(this->pos().x()+33,this->pos().y()+33);
    }}

    else if(m==4){
        double dx,dy;
        for(int j=0;j<=10;++j){
        for(int i=0;i<10;++i){
     dx=10*cos(2*3.14/10*(i)+2*3.14/40.0*j)*(1.0-((i)/11.0))*(1.0-((i)/11.0)*((i)/11.0))+2;
     dy=10*sin(2*3.14/10*(i)+2*3.14/40.0*j)*(1.0-((i)/11.0))*(1.0-((i)/11.0)*((i)/11.0))+2;
        if(dx==0||abs(dx)<0.1){dx=2;}
        if(dy==0||abs(dy)<0.1){dy=-2;}

        bullet *b=new bullet(pa,fr,dx,dy);
        this->scene()->addItem(b);
        b->setPos(this->pos().x()+33,this->pos().y()+33);
        }
}
    }

}
void enemy::move(){

    if(this->pos().x()<=0){vx=abs(vx);}
    if(this->pos().x()>=240){vx=-abs(vx);}
    if(this->pos().y()<=0){vy=abs(vy);}
    if(this->pos().y()>=100){vy=-abs(vy);}

    moveBy(vx,vy);
}
void enemy:: settarget(player*p){
    pa=p;
}
void enemy::collide(){
 if(hp>0){--hp;}
}
