#include "server.h"
#include "logger.h"

Server::Server()
{

}

Server::~Server()
{
    for(auto i:set)
    {
        try
        {
            i->close();
        } catch (...)
        {
            Logger::Info("断开连接出错");
        }
    }
}

void Server::Start()
{
    server.listen(QHostAddress::Any,PROT);
    connect(&server, SIGNAL(newConnection()),
            this, SLOT(AcceptConnection()));

}

void Server::Send(QTcpSocket * socket, MsgType type,const MessageObject & obj)
{
    QJsonObject pkg;
    pkg.insert("code",type);
    pkg.insert("data",obj.ToJson());
    auto data = QJsonDocument(pkg).toJson();
//    socket->write(data,data.size());
    Logger::Info(data.data());
}

void Server::AcceptConnection()
{
    auto newSocket = server.nextPendingConnection();
    if(set.find(newSocket)!=set.end())
    {
        Logger::Info("已经存在的连接");
        return;
    }
    set.insert(newSocket);
    Logger::Info(QString("新的连接,ip:%1 port:%2").arg(newSocket->peerAddress().toString()).arg(newSocket->peerPort()));

}
