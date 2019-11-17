#include "messge.h"


Messge::Messge()
{

}

void Messge::Send(QTcpSocket * socket, MsgType type, const QJsonObject & obj)
{
    QJsonObject pkg;
    pkg.insert("code",type);
    pkg.insert("data",obj);
    auto data = QJsonDocument(pkg).toBinaryData();
    socket->write(data,data.size());
}
