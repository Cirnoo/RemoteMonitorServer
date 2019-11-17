#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QSet>
#include "protocol.h"
class Server : public QObject
{
    Q_OBJECT
    const static quint16 PROT = 10086;
public:
    Server();
    virtual ~Server();
    void Start();
    QTcpServer server;
    QTcpSocket socket;
    void Send(QTcpSocket * socket, MsgType type, const MessageObject & obj);
private:
    QSet<QTcpSocket*> set;
public slots:
    void AcceptConnection();
};

#endif // SERVER_H
