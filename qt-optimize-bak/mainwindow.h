
#ifndef MAIN_H
#define MAIN_H

#include <QtGui>
#include <QWidget>

//***************************************************************************************************

class QHBoxLayout;
class QSlider;
class QSpinBox;
class QVBoxLayout;
class QGridLayout;
class Main;
class QLabel;
//****************************************************************************************************


//****************************************************************************************************

class Nextpage: public QDialog
{
    Q_OBJECT

public:
    Nextpage(QWidget *parent = 0);
    ~Nextpage();

    //QSpinBox *spinBox;
    QSlider *slider;
    QPushButton *pop;
    QPushButton *Joz;
    QPushButton *Rock;
    QFont P;
    QFont J;
    QFont R;
    QFont sl;
    QLabel *s5;
private slots:

    void action();

private:

    QGridLayout *toplayout;
    QGridLayout *midlayout;
    QHBoxLayout *botlayout;
    QVBoxLayout *layout;

};


//*********************************************************************************************************

class Main : public QWidget
{
    Q_OBJECT

public:
    Main(QWidget *parent = 0);
    ~Main();
     QPalette *palette;
     QSlider *slider;
     QSlider *bass;
     QSlider *mid;
     QSlider *treble;
     QSpinBox *spinBox;
     QFont zt;
     QFont bq;
     QLabel *s1;
     QLabel *s2;
     QLabel *s3;
     QLabel *s4;

private slots:

    void openProcess1();

    void nextpage();
    void readResult(int exitCode);
    void popaction();
    void midaction();
    void trebleaction();
private:

    QProcess *p;
    QGridLayout *toplayout;
    QHBoxLayout *botlayout;

    QBoxLayout *boxlayout;

    QVBoxLayout *layout1;
    QVBoxLayout *layout2;
    QVBoxLayout *layout3;

    Nextpage *nextPage;

    int v;
    int b;
    int m;
    int t;

};

#endif // MAIN_H
