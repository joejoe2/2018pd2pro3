#include "player.h"
#include <bullet.h>
player::player(QTimer*f,int option)
{
    if(option==0){vol=5;hp=50;
    map=new QPixmap(":/src/player.png");
    }
    if(option==1){vol=8;hp=30;
    map=new QPixmap(":/src/player2.png");
    }

    change=f;
    stop=new QTimer();
    QTimer*backup=new QTimer();
    backup->setInterval(f->interval());
    stop->setInterval(3000);
    v.push_back(QPointF(0,0));
    v.push_back(QPointF(32,0));
    v.push_back(QPointF(32,32));
    v.push_back(QPointF(0,32));
    path.addPolygon(QPolygonF(v));
    setPos(150,465);
    vx=0;vy=0;
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    skill=3;
    isshot=false;isskill=false;
    connect(backup,SIGNAL(timeout()),this,SLOT(act()));
    backup->start();
}
QRectF player::boundingRect() const{
  return path.boundingRect();
}
QPainterPath player:: shape()const{
return path;
}
void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->drawPixmap(path.boundingRect(),*map,path.boundingRect());
}
void player::keyPressEvent(QKeyEvent *event){


if(event->key()==Qt::Key_W)
{vy=-vol;}
else if(event->key()==Qt::Key_D)
{vx=vol;}
else if(event->key()==Qt::Key_S)
{vy=vol;}
else if(event->key()==Qt::Key_A)
{vx=-vol;}

if(event->key()==Qt::Key_Space){
    isshot=true;
}
if(event->key()==Qt::Key_M&&!isskill&&skill>0){
    connect(stop,SIGNAL(timeout()),this,SLOT(hold()));

    stop->start();
    isskill=true;
    --skill;
    change->stop();
}
}
void player::hold(){
  stop->stop();
  disconnect(stop,SIGNAL(timeout()),this,SLOT(hold()));
  isskill=false;
  change->start();
}
void player::keyReleaseEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_W)
    {vy=0;}
    else if(event->key()==Qt::Key_D)
    {vx=0;}
    else if(event->key()==Qt::Key_S)
    {vy=0;}
    else if(event->key()==Qt::Key_A)
    {vx=0;}
    if(event->key()==Qt::Key_Space){
        isshot=false;
    }
}
void player::act(){
    if(this->pos().x()<=0&&vx<=0){vx=0;}
    if(this->pos().x()>=270&&vx>=0){vx=0;}
    if(this->pos().y()<=0&&vy<=0){vy=0;}
    if(this->pos().y()>=470&&vy>=0){vy=0;}
    moveBy(vx,vy);
    if(isshot){
        bullet *b=new bullet(en,change);
        this->scene()->addItem(b);
        b->setPos(pos().x()+15,pos().y());
    }
}
void player::settarget(enemy*e){
    en=e;
}
void player::collide(){
    if(hp>0){--hp;}
}
