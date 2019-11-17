#ifndef MESSGE_H
#define MESSGE_H
#include <protocol.h>
#include <QObject>
#include <QTcpSocket>
class Messge
{
public:
    Messge();
    void Send(QTcpSocket * socket, MsgType type, const QJsonObject & obj);
};

#endif // MESSGE_H
