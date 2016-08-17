#include "mainwindow.h"
#include <QMessageBox>
#include <QHostAddress>

TcpClient::TcpClient(QWidget *parent,Qt::WindowFlags f)
    : QDialog(parent,f)
{
    setWindowTitle(tr("TCP Client"));

    /*ReceiveTextEdit = new QTextEdit(this);
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
    }*/
    TimerLabel = new QLabel(tr("data:"),this);
    TextLineEdit = new QLineEdit(this);
    StartBtn = new QPushButton(tr("enter"),this);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(TimerLabel);
    mainLayout->addWidget(TextLineEdit);
    mainLayout->addWidget(StartBtn);

    port =9734;
    tcpSocket = new QTcpSocket(this);
    QString ipAddress;

    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    tcpSocket->connectToHost(ipAddress,port);

    connect(StartBtn,SIGNAL(clicked()),this,SLOT(StartBtnClicked()));

}

TcpClient::~TcpClient()
{

}
void TcpClient::StartBtnClicked()
{

        StartBtn->setText(tr("enter"));

        QString msg = TextLineEdit->text();
        int length=0;
        if(msg=="")
        {
           return;
        }
        if((length=tcpSocket->write(msg.toLatin1(),msg.length()))!=msg.length())
        {
            return;
        }
        TextLineEdit->clear();


}

/*void UdpClient::CloseBtnClicked()
{
    close();
}

void UdpClient::dataReceived()
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
*/
