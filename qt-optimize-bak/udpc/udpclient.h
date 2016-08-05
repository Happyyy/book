#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef tcpclient_H
#define tcpclient_H

//#include <QDialog>
//#include <QVBoxLayout>
//#include <QTextEdit>
//#include <QPushButton>
//#include <QUdpSocket>

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QUdpSocket>
#include <QTimer>

class udpclient: public QDialog
{
    Q_OBJECT

public:
    udpclient(QWidget *parent = 0,Qt::WindowFlags f=0);
    ~udpclient();
public slots:
    //void CloseBtnClicked();
    //void dataReceived();
    void StartBtnClicked();
private:
    //QTextEdit *ReceiveTextEdit;
    //QPushButton *CloseBtn;
    //QVBoxLayout *mainLayout;
    //int port;
    //QudpSocket*tcpSocket;
    QLabel *TimerLabel;
    QLineEdit *TextLineEdit;
    QPushButton *StartBtn;
    QVBoxLayout *mainLayout;
    int port;
    bool isStarted;
    QUdpSocket *udpSocket;
};

#endif // tcpclient_H

#endif // MAINWINDOW_H


