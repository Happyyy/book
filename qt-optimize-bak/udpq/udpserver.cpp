#include "udpserver.h"
#include <QHostAddress>
#include <QMessageBox>

UdpServer::UdpServer(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle(tr("UDP server"));

    ReceiveTextEdit = new QTextEdit(this);
    CloseBtn = new QPushButton(tr("Close"),this);

    mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(ReceiveTextEdit);
    mainLayout->addWidget(CloseBtn);

    connect(CloseBtn,SIGNAL(clicked()),this,SLOT(CloseBtnClicked()));

    port =5555;

    udpSocket = new QUdpSocket(this);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));

    bool result=udpSocket->bind(port);
    if(!result)
    {
        QMessageBox::information(this,tr("error"),tr("udp socket create error!"));
        return;
    }

}

UdpServer::~UdpServer()
{

}

/*void UdpServer::StartBtnClicked()
{

        StartBtn->setText(tr("enter"));

        QString msg = TextLineEdit->text();
        int length=0;
        if(msg=="")
        {
           return;
        }
        if((length=udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port))!=msg.length())
        {
            return;
        }
        TextLineEdit->clear();


}*/
void UdpServer::CloseBtnClicked()
{
    close();
}

void UdpServer::dataReceived()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());

        udpSocket->readDatagram(datagram.data(),datagram.size());
        QString msg=datagram.data();
        ReceiveTextEdit->insertPlainText(msg);
    }
}


