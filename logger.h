#ifndef OUTPUTER_H
#define OUTPUTER_H
#include<QString>
#include<QHash>
#include<functional>
#include<unordered_map>
using std::function;
using std::unordered_map;
class QTextBrowser;
class Logger
{
public:
    static void Regist(const int key,const function<void(QString)> );
    static void UnRegist(const int key);
    static void Info(const QString & str);
private:
    Logger();
    static unordered_map<int,function<void(QString)>> listener;

};
#endif // OUTPUTER_H
