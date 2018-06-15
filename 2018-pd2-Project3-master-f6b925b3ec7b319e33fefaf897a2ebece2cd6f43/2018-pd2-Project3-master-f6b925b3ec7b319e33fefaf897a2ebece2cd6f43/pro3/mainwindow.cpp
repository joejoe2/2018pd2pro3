#include "mainwindow.h"
#include<surface.h>
MainWindow::MainWindow()
{
    list=new QMediaPlaylist();
    list->addMedia(QUrl("qrc:/src/op.mp3"));
    list->setPlaybackMode(QMediaPlaylist::Loop);
    media=new QMediaPlayer(this,QMediaPlayer::LowLatency);
    media->setPlaylist(list);
    media->setVolume(100);
    media->play();

    o1=new QLabel();o1->setPixmap(QPixmap(":/src/player.png"));
    o2=new QLabel();o2->setPixmap(QPixmap(":/src/player2.png"));
    tag=0;
    o1->setStyleSheet("border:5px solid black;background-color:white");
    o2->setStyleSheet("border:0px solid black;background-color:white");

    b1=new QPushButton("start!");
    c1=new QPushButton("caster");
    c2=new QPushButton("archer");
    connect(c1,SIGNAL(clicked(bool)),this,SLOT(choose()));
    connect(c2,SIGNAL(clicked(bool)),this,SLOT(choose()));

    QLabel*l1=new QLabel();
    QSettings* s=new QSettings();
    l1->setText("best score:"+QString::number(s->value("best").toInt()));
    connect(b1,SIGNAL(clicked(bool)),this,SLOT(start()));
    qv=new QVBoxLayout();
    qv->addWidget(l1,0,Qt::AlignHCenter);
    qv->addWidget(b1);
    qv->addWidget(o1,0,Qt::AlignHCenter);
    qv->addWidget(c1);
    qv->addWidget(o2,0,Qt::AlignHCenter);
    qv->addWidget(c2);
    setLayout(qv);
    setFixedSize(300,500);
}
void MainWindow::start(){
    media->stop();
    list->clear();
    delete media;
    delete list;
    surface*sur=new surface(tag);
    sur->show();
    close();
    destroy();
}
void MainWindow::choose(){
    if(sender()==c1){
        tag=0;
        o1->setStyleSheet("border:5px solid black;background-color:white");
        o2->setStyleSheet("border:0px solid black;background-color:white");
    }
    else{tag=1;
    o2->setStyleSheet("border:5px solid black;background-color:white");
    o1->setStyleSheet("border:0px solid black;background-color:white");
    }
}
