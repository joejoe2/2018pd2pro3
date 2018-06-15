#ifndef BULLET_H
#define BULLET_H
#include<QGraphicsItem>
#include<QPainter>
#include<QPaintEvent>
#include<QPixmap>
#include<QTimer>
#include<player.h>
#include<enemy.h>
class bullet:public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    bullet(player* t,QTimer *f,int x,int y);
    bullet(enemy* t,QTimer *f);
    player*targetp;
    enemy*targete;
    QVector<QPointF>v;
    QPainterPath path;
    QPixmap *pixmap;
    QRectF boundingRect() const;
    QPainterPath shape()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int vx,vy;
    QTimer *change;
    int flag;
public slots:
    void move();
};

#endif // BULLET_H
