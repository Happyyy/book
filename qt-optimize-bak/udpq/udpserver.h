#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QUdpSocket>

class UdpServer : public QDialog
{
    Q_OBJECT

public:
    UdpServer(QWidget *parent = 0,Qt::WindowFlags f=0);
    ~UdpServer();
public slots:
    void CloseBtnClicked();
    void dataReceived();
private:
    QTextEdit *ReceiveTextEdit;
    QPushButton *CloseBtn;
    QVBoxLayout *mainLayout;
    int port;
    QUdpSocket *udpSocket;

};

#endif // UDPSERVER_H
