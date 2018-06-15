#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include<QPushButton>
#include<QVBoxLayout>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QLabel>
class MainWindow :public QWidget
{
    Q_OBJECT
public:
     MainWindow();
     QPushButton*b1,*c1,*c2;
     QMediaPlayer *media;
     QMediaPlaylist*list;
     QVBoxLayout*qv;
     QLabel*o1,*o2;
     int tag;
public slots:
     void start();
     void choose();
};
#endif // MAINWINDOW_H
