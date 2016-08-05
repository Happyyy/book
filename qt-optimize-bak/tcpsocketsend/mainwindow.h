#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef UDPCLIENT_H
#define UDPCLIENT_H

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
#include <QTcpSocket>
#include <QTimer>

class TcpClient : public QDialog
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = 0,Qt::WindowFlags f=0);
    ~TcpClient();
public slots:
    //void CloseBtnClicked();
    //void dataReceived();
    void StartBtnClicked();
private:
    //QTextEdit *ReceiveTextEdit;
    //QPushButton *CloseBtn;
    //QVBoxLayout *mainLayout;
    //int port;
    //QTcpSocket *udpSocket;
    QLabel *TimerLabel;
    QLineEdit *TextLineEdit;
    QPushButton *StartBtn;
    QVBoxLayout *mainLayout;
    int port;
    bool isStarted;
    QTcpSocket *tcpSocket;
};

#endif // UDPCLIENT_H

#endif // MAINWINDOW_H


