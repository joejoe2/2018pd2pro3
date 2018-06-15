#ifndef PLAYER_H
#define PLAYER_H
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QPainter>
#include<QPaintEvent>
#include<QPixmap>
#include<QTimer>
//#include <bullet.h>
#include<enemy.h>
class player:public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    player(QTimer*f,int option);

    QVector<QPointF>v;
    QPainterPath path;
    QPixmap pixmap;
    QRectF boundingRect() const;
    QPainterPath shape()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    int vx,vy,vol;
    QPixmap *map;
    enemy* en;
    void settarget(enemy*e);
    QTimer *change,*stop;
    bool isshot;
    int hp;
    void collide();
    int skill;
    bool isskill;
public slots:
    void act();
    void hold();
};

#endif // PLAYER_H
