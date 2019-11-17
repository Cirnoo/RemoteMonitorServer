#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
enum MsgType
{
    POINT,
};

class MessageObject
{
public:
    QJsonObject ToJson() const
    {
       Prise();
       return obj;
    }
    virtual ~MessageObject()
    {

    }
protected:
    mutable QJsonObject obj;
private:
    virtual void Prise() const = 0;
};

class Point : public MessageObject
{
public:
    int x,y;
    Point(int x,int y):x(x),y(y)
    {

    }

    // MessageObject interface
private:
    void Prise() const
    {
        obj.insert("x",x);
        obj.insert("y",y);
    }
};

#endif // PROTOCOL_H
