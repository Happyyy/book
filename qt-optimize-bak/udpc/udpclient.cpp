#include "udpclient.h"
#include <QMessageBox>
#include <QHostAddress>

udpclient::udpclient(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    //setWindowTitle(tr("UDP Client"));

    /*ReceiveTextEdit = new QTextEdit(this);
    CloseBtn = new QPushButton(tr("Close"),this);

    mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(ReceiveTextEdit);
    mainLayout->addWidget(CloseBtn);

    connect(CloseBtn,SIGNAL(clicked()),this,SLOT(CloseBtnClicked()));

    port =5555;

    udpSocket= new QUdpSocket(this);
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));

    bool result=tcpSocket->bind(port);
    if(!result)
    {
        QMessageBox::information(this,tr("error"),tr("udp socket create error!"));
        return;
    }*/
    TimerLabel = new QLabel(tr("data:"),this);
    TextLineEdit = new QLineEdit(this);
    StartBtn = new QPushButton(tr("enter"),this);

    //mainLayout = new QVBoxLayout(this);
    //mainLayout->addWidget(TimerLabel);
    //mainLayout->addWidget(TextLineEdit);
    //mainLayout->addWidget(StartBtn);

    connect(StartBtn,SIGNAL(clicked()),this,SLOT(StartBtnClicked()));

    port =9734;
    udpSocket = new QUdpSocket(this);
}

udpclient::~udpclient()
{

}
void udpclient::StartBtnClicked()
{

        //StartBtn->setText(tr("enter"));
    int v=4;
    int b=5;
    int m=7;
    int t=2;
    QString p1 = QString("%1").arg(v);
    QString p2= QString("%1").arg(b);
    QString p3 = QString("%1").arg(m);
    QString p4= QString("%1").arg(t);
        //QString msg = TextLineEdit->text();
    QString msg = "-v"+p1+"-t"+p2+"-b"+p3+"-m"+p4;
        int length=0;
        if(msg=="")
        {
           return;
        }
        if((length=udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::LocalHost,port))!=msg.length())
        {
            return;
        }
        TextLineEdit->clear();


}

/*void tcpclient::CloseBtnClicked()
{
    close();
}

void tcpclient::dataReceived()
{
    while(tcpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(tcpSocket->pendingDatagramSize());

        tcpSocket->readDatagram(datagram.data(),datagram.size());
        QString msg=datagram.data();
        ReceiveTextEdit->insertPlainText(msg);
    }
}
*/
