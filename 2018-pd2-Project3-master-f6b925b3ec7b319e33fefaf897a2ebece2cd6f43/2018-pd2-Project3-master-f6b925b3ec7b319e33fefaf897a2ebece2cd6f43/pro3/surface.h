#ifndef SURFACE_H
#define SURFACE_H
#include <QWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<myview.h>
#include<QLabel>
#include<QTimer>
#include<QPushButton>
#include<mainwindow.h>
#include<QSettings>
#include<QMediaPlayer>
#include<QMediaPlaylist>
class surface:public QWidget
{
    Q_OBJECT
public:
    surface(int messege);
    QHBoxLayout*qh;
    QVBoxLayout*qv;
    myview*view;
    QTimer*frame;
    QLabel*l1,*l2,*l3,*l4,*l5;
    QPushButton*b1;
    int php,ehp,count,sc,timeslice;
    QGraphicsView*win;
    QGraphicsScene*result;
    QSettings *setting;
    QMediaPlayer *media;
    QMediaPlaylist*list;
public slots:
   void info();
   void back();
};

#endif // SURFACE_H
