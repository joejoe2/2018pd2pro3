#ifndef MYVIEW_H
#define MYVIEW_H
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsItem>
#include<player.h>
#include<enemy.h>
#include<QTimer>
#include<bullet.h>
#include<QPainter>
#include<QPaintEvent>
#include<QPixmap>
class myview:public QGraphicsView
{
    Q_OBJECT
public:
    myview(QTimer*f,int opt);
    QGraphicsScene *scene;
    QTimer*frame;
    player*p;
    enemy*e;
    void drawBackground(QPainter*painter,const QRectF &rect);
};

#endif // MYVIEW_H
