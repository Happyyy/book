#ifndef CLIENT_H
#define CLIENT_H
#include <QDialog>

#include <qlocalsocket.h>

class QDialogButtonBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QLocalSocket;

class Client : public QDialog
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);

private slots:
    void requestNewFortune();
    void readFortune();
    void displayError(QLocalSocket::LocalSocketError socketError);
    void enableGetFortuneButton();

private:
    QLabel *hostLabel;
    QLineEdit *hostLineEdit;
    QLabel *statusLabel;
    QPushButton *getFortuneButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;

    QLocalSocket *socket;
    QString currentFortune;
    quint16 blockSize;
};

#endif
