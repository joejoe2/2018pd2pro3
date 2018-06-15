#ifndef ENEMY_H
#define ENEMY_H
#include<QGraphicsItem>
#include<QPainter>
#include<QPaintEvent>
#include<QPixmap>
#include<QTimer>
class player;
class enemy:public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    enemy(QTimer*f);
    QVector<QPointF>v;
    QPainterPath path;
    QPixmap pixmap;
    QRectF boundingRect() const;
    QPainterPath shape()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int vx,vy;
    QTimer *change,*fr;
    void settarget(player*p);
    player *pa;
    int hp;
    void collide();
public slots:
    void movestate();
    void move();
};

#endif // ENEMY_H
