#include "surface.h"
surface::surface(int messege)
{
    list=new QMediaPlaylist();
    list->addMedia(QUrl("qrc:/src/battle.mp3"));
    list->setPlaybackMode(QMediaPlaylist::Loop);
    media=new QMediaPlayer(this,QMediaPlayer::LowLatency);
    media->setPlaylist(list);
    media->setVolume(100);
    media->play();


 frame=new QTimer();
 frame->setInterval(40);
 view=new myview(frame,messege);
 qh=new QHBoxLayout();
 qv=new QVBoxLayout();
 l1=new QLabel();
 l2=new QLabel();
 l3=new QLabel();
 l4=new QLabel();
 l5=new QLabel();
 b1=new QPushButton("back");
 qh->addWidget(view);
 qv->addWidget(l5);
 qv->addWidget(l3);
 qv->addWidget(l2);
 qv->addWidget(l1);
 qv->addWidget(l4);
 qv->addWidget(b1);
 qh->addLayout(qv);
 setLayout(qh);
 connect(frame,SIGNAL(timeout()),this,SLOT(info()));
 connect(b1,SIGNAL(clicked(bool)),this,SLOT(back()));
 ehp=1000;php=50;
 frame->start();
 setFixedSize(500,550);
 win=new QGraphicsView();
 result=new QGraphicsScene();
 count=0;sc=0;timeslice=0;
 l3->setText("score:"+QString::number(sc));
 setting=new QSettings();
 l5->setText("best score:"+QString::number(setting->value("best").toInt()));
 l4->setText("extra skill:3/3");
}
void surface::info(){
    int dif=abs(ehp-view->e->hp);
    php=view->p->hp;
    ehp=view->e->hp;
    l1->setText("your hp:"+QString::number(php));
    l2->setText("enemy hp:"+QString::number(ehp));
    ++count;
    l4->setText("extra skill:"+QString::number(view->p->skill)+"/3");

    if(php==0){
        media->stop();
        list->clear();
       result->addText("you lose...");
       win->setScene(result);
       win->setFixedSize(305,505);
       qh->replaceWidget(view,win);
       frame->stop();
       if(sc>setting->value("best").toInt()){
       setting->setValue("best",sc);
       setting->sync();
       l5->setText("best score:"+QString::number(sc));
       }
    }
    if(ehp==0){
       media->stop();
       list->clear();
       list=new QMediaPlaylist();
       list->addMedia(QUrl("qrc:/src/win.mp3"));
       media=new QMediaPlayer(this,QMediaPlayer::LowLatency);
       media->setPlaylist(list);
       media->setVolume(100);
       media->play();
       result->addText("you win!!!");
       sc+=50000;
       win->setScene(result);
       win->setFixedSize(305,505);
       qh->replaceWidget(view,win);
       frame->stop();
       if(sc>setting->value("best").toInt()){
       setting->setValue("best",sc);
       setting->sync();
       l5->setText("best score:"+QString::number(sc));
       }
    }
    if(count>=75&&timeslice<=50){
        count=0;
        ++timeslice;
    }
    sc=sc+(dif)*((float)((1000-ehp)/60+1))*(float)(51-timeslice)/5;
l3->setText("score:"+QString::number(sc));
}
void surface::back(){
    media->stop();
    list->clear();
    delete media;
    delete list;
    MainWindow*w=new MainWindow();
    w->show();
    close();
    destroy();
}
