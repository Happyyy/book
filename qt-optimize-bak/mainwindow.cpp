#include "mainwindow.h"

Main::Main(QWidget *parent)
{
    setWindowTitle("Main");

                                            //设置背景图片
                                            // QPixmap pixmap("/home/test/Downloads/fg.png");
                                            // QPalette palette;
                                            // palette.setBrush(this->backgroundRole(),QBrush(pixmap));
                                            // this->setPalette(palette);
                                            // this->setMask(pixmap.mask()); //可以将图片中透明部分显示为透明的
                                            // this->setAutoFillBackground(true);


    p = new QProcess(this);
    nextPage = new Nextpage(this);

//三组滑动条////////add :groove为槽的颜色，handle为按钮的颜色，add-page 及sub-page分别为按钮前后的颜色，如果groove与add-page、sub-page同在，那么groove的颜色会被覆盖掉。
    QFont bq;
    bq.setPointSize(20);//设置B，M，T，VOL字体大小

    bass = new QSlider(Qt::Vertical);
    bass->setStyleSheet("QSlider::groove:vertical{border:5px;height:250px;}"
                         "QSlider::sub-page:vertical{background:darkgray;}"
                         "QSlider::add-page:vertical{background:darkgray;}"
                         "QSlider::handle:vertical{background:black;height:30px;width:20px;border-radius:0px;margin:-3px 0px -3px 0px;}");
    bass->setMaximumWidth(70);
    s1= new QLabel(tr("B"));
    s1->setFont(bq);

    mid = new QSlider(Qt::Vertical);
    mid->setStyleSheet("QSlider::groove:vertical{border:5px;height:250px;}"
                       "QSlider::sub-page:vertical{background:darkgray;}"
                       "QSlider::add-page:vertical{background:darkgray;}"
                       "QSlider::handle:vertical{background:black;height:30px;width:60px;border-radius:0px;margin:-3px 0px -3px 0px;}");
    mid->setMaximumWidth(70);
    s2= new QLabel(tr("M"));
    s2->setFont(bq);

    treble = new QSlider(Qt::Vertical);
    treble->setStyleSheet("QSlider::groove:vertical{border:5px;height:250px;}"
                          "QSlider::sub-page:vertical{background:darkgray;}"
                          "QSlider::add-page:vertical{background:darkgray;}"
                          "QSlider::handle:vertical{background:black;height:30px;width:20px;border-radius:0px;margin:-3px 0px -3px 0px;}");

     treble->setMaximumWidth(70);
     s3= new QLabel(tr("T"));
     s3->setFont(bq);

     bass->setMaximum(9);//设置滑动条的最大值
     mid->setMaximum(9);
     treble->setMaximum(9);

 //音量滑动条
    slider = new QSlider(Qt::Horizontal);
    slider->setStyleSheet("QSlider::groove:horizontal{border:0px;width:600;}"
                             "QSlider::sub-page:horizontal{background:darkgray;}"
                             "QSlider::add-page:horizontal{background:darkgray;}"
                             "QSlider::handle:horizontal{background:black;height:20;width:30px;border-radius:0px;margin:-3px 0px -3px 0px;}");
    slider ->setMaximum(9);
    slider->setMaximumHeight(60);
    s4=new QLabel(tr("VOL"));
    s4->setFont(bq);

                                 // spinBox = new QSpinBox;
                                 // QPushButton *bt1 = new QPushButton("ex",this);
                                 // QPushButton *bt2 = new QPushButton("exe",this);
                                 // QPushButton *bt3 = new QPushButton("excu",this);
//next按钮
    QPushButton *next = new QPushButton("N",this);
    QFont zt;
    zt.setPointSize(20);//字体大小设置
    next->setFont(zt);
    next->setFixedSize(40,40);//设置按钮尺寸
                                                // next->setStyleSheet( "QPushButton{border:none;min-height: 40px;min-width: 40px;border-image:url(/home/test/Downloads/next.png);}");//设置按钮图标
                                                // next->setIconSize(QSize(1000, 1000));
                                                // QObject::connect(bt1, SIGNAL(clicked()), this, SLOT(openProcess1()));
                                                // QObject::connect(bt2, SIGNAL(clicked()), this, SLOT(openProcess2()));
                                                // QObject::connect(bt3, SIGNAL(clicked()), this, SLOT(openProcess3()));

//利用信号槽将nextpage页面的pop，Joz，Rock三个按钮来控制第一页的三个滑杆

     QObject::connect(nextPage->pop, SIGNAL(clicked()), this, SLOT(popaction()));
     QObject::connect(nextPage->Joz, SIGNAL(clicked()), this, SLOT(midaction()));
     QObject::connect(nextPage->Rock, SIGNAL(clicked()),this, SLOT(trebleaction()));

//用next按钮来控制进入第二界面

     QObject::connect(next, SIGNAL(clicked()), this, SLOT(nextpage()));
                                            // QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
                                            // spinBox->setValue(0);
                                            //spinBox->setMaximum(9);


//第一界面与第二界面音量相互连通
     QObject::connect(slider, SIGNAL(valueChanged(int)), nextPage->slider, SLOT(setValue(int)));
     QObject::connect(nextPage->slider, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));

//四个滑动条中任何一个值改变将启动程序
     QObject::connect(slider, SIGNAL(valueChanged(int)), this, SLOT(openProcess1()));
     QObject::connect(bass, SIGNAL(valueChanged(int)), this, SLOT(openProcess1()));
     QObject::connect(mid, SIGNAL(valueChanged(int)), this, SLOT(openProcess1()));
     QObject::connect(treble, SIGNAL(valueChanged(int)), this, SLOT(openProcess1()));

//*************布局************************
     toplayout = new QGridLayout;
     layout1 = new QVBoxLayout;

     layout1->addWidget(bass);
     layout1->addWidget(s1);
     toplayout->addLayout(layout1,2,2,6,3);

     layout2 = new QVBoxLayout;
     layout2->addWidget(mid);
     layout2->addWidget(s2);
     toplayout->addLayout(layout2,2,5,6,3);

     layout3 = new QVBoxLayout;
     layout3->addWidget(treble);
     layout3->addWidget(s3);
     toplayout->addLayout(layout3,2,8,6,3);

     toplayout->addWidget(next,7,9,2,1);

                              // toplayout->addWidget(slider,4,1,2,8);
                              // toplayout->addWidget(s1,3,2,1,3);
                              // toplayout->addWidget(s2,3,5,1,3);
                              // toplayout->addWidget(s3,3,8,1,3);
                              // toplayout->addWidget(s4,4,1,2,1);
     botlayout = new QHBoxLayout;
     botlayout->addWidget(s4);
     botlayout->addWidget(slider);
     toplayout->addLayout(botlayout,9,1,2,9);

                             // layout = new QVBoxLayout;
                             // layout->addStretch(1);
                             // layout->addLayout(toplayout);
                             // layout->addStretch(1);
                             // layout->addLayout(botlayout);
                             // layout->addStretch(1);

     this->setLayout(toplayout);

}

Main::~Main()
{
}


void Main::openProcess1()
 {

     v=slider->value();
     b=bass->value();
     m=mid->value();
     t=treble->value();
     QString p1 = QString("%1").arg(v);
     QString p2= QString("%1").arg(b);
     QString p3 = QString("%1").arg(m);
     QString p4= QString("%1").arg(t);


     //p->start("/demo/qt_val_test",QStringList()<<"-v"<<p1<<"-b"<<p2<<"-m"<<p3<<"-t"<<p4);//调用程序并传值
     p->start("/demo/stune",QStringList()<<"-v"<<p1<<"-b"<<p2<<"-m"<<p3<<"-t"<<p4);//调用程序并传值

    connect(p, SIGNAL(finished(int)), this, SLOT(readResult(int)));
 }


void Main::readResult(int exitCode)
{
    if(exitCode == 0)
    {
       QTextCodec* gbkCodec = QTextCodec::codecForName("GBK");
       QString result = gbkCodec->toUnicode(p->readAll());
       //QMessageBox::information(this, "test", result);
     }
}

void Main::popaction()//三个设置默认的值
{

    disconnect(bass, SIGNAL(valueChanged(int)), 0, 0);
    disconnect(mid, SIGNAL(valueChanged(int)), 0, 0);
    bass->setValue(4);
    mid ->setValue(5);
    treble->setValue(6);



}
void Main::midaction()//三个按钮设置默认的值
{
    disconnect(bass, SIGNAL(valueChanged(int)), 0, 0);
    disconnect(mid, SIGNAL(valueChanged(int)), 0, 0);
    bass->setValue(2);
    mid->setValue(4);
    treble->setValue(7);

}
void Main::trebleaction()//三个按钮设置默认的值
{
    disconnect(bass, SIGNAL(valueChanged(int)), 0, 0);
    disconnect(mid, SIGNAL(valueChanged(int)), 0, 0);
    bass->setValue(7);
    mid->setValue(4);
    treble->setValue(6);

}
void Main::nextpage()
{
    this->close();
    nextPage->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);//去标题栏
    nextPage->showMaximized();//窗口最大化
    nextPage->exec();
    this->show();
}

//**************************Nextpage**********************************************************************************************************


Nextpage::Nextpage(QWidget *parent):QDialog(parent)
{
                                         //设置背景图片

                                         // QPixmap pixmap("/home/test/Downloads/fg.png");
                                         // QPalette palette;
                                         // palette.setBrush(this->backgroundRole(),QBrush(pixmap));
                                         // this->setPalette(palette);
                                         // this->setMask(pixmap.mask()); //可以将图片中透明部分显示为透明的
                                         // this->setAutoFillBackground(true);

//返回按钮
      QPushButton *back = new QPushButton("B",this);
      back->setFixedSize(40,40);//设置按钮大小

     //字号设置
     QFont zt;
     zt.setPointSize(20);
     back->setFont(zt);

                                          //back->setStyleSheet("QPushButton{border:none;min-height: 30px;min-width: 0.5px;border-image:url(/home/test/Downloads/back.png);}");
                                          // back->setGeometry(100,100,100,100);
                                          // back->setCheckable(TRUE);
                                          // back->setChecked(TRUE);
      QObject::connect(back, SIGNAL(clicked()), this, SLOT(action()));

      setWindowTitle("Nextpage");

      pop = new QPushButton("P",this);
      pop->setFixedSize(100,100);
     //字号设置
      QFont P;
      P.setPointSize(40);
      pop->setFont(P);
                                          // pop->setStyleSheet( "QPushButton{border:none;min-height: 30px;min-width: 0.5px;border-image:url(/home/test/Downloads/pop.png);}");

      Joz = new QPushButton("J",this);
      Joz->setFixedSize(100,100);
     //字号设置
      QFont J;
      J.setPointSize(40);
     Joz->setFont(J);
                                           // Joz->setStyleSheet( "QPushButton{border:none;min-height: 30px;min-width: 0.5px;border-image:url(/home/test/Downloads/joz.png);}");

      Rock = new QPushButton("R",this);
      Rock->setFixedSize(100,100);
      //字号设置
      QFont R;
      R.setPointSize(40);
     Rock->setFont(R);
                                             // Rock->setStyleSheet( "QPushButton{border:none;min-height: 30px;min-width: 0.5px;border-image:url(/home/test/Downloads/rock.png);}");

//音量控制
      slider = new QSlider(Qt::Horizontal);
      slider->setStyleSheet("QSlider::groove:horizontal{border:0px;width:600;}"
                            "QSlider::sub-page:horizontal{background:darkgray;}"
                            "QSlider::add-page:horizontal{background:darkgray;}"
                            "QSlider::handle:horizontal{background:black;height:20;width:30px;border-radius:0px;margin:-3px 0px -3px 0px;}");
       slider->setMaximumHeight(60);
       
       QFont sl;
       sl.setPointSize(20);
       s5=new QLabel(tr("VOL"));
       s5->setFont(sl);
                                            // spinBox = new QSpinBox;
                                            // QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
                                            //QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
      slider->setMaximum(9);//设置最大值
                                            // spinBox->setMaximum(9);//设置最大值


//布局
                                  // botlayout = new QHBoxLayout;
                                  // botlayout->addWidget(spinBox);
                                  // botlayout->addWidget(slider);
      toplayout =new QGridLayout;

      toplayout->addWidget(pop,3,2,3,3);
      toplayout->addWidget(Joz,3,5,3,3);
      toplayout->addWidget(Rock,3,8,3,3);

      toplayout->addWidget(back,5,9,1,1);
     
      botlayout = new QHBoxLayout;
      botlayout->addWidget(s5);
      botlayout->addWidget(slider);
      toplayout->addLayout(botlayout,6,1,2,9);
                                  
                                   // toplayout->addWidget(slider,6,1,2,9);
                                   // layout = new QVBoxLayout;
                                   // layout->addStretch();
                                   // layout->addLayout(toplayout);
                                   // layout->addStretch();
                                   // layout->addLayout(botlayout);
                                   // layout->addStretch();
      this->setLayout(toplayout);

}

Nextpage::~Nextpage()
{
}

void Nextpage::action()
{
    this->close();

}

