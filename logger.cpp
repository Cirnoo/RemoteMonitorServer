#include "logger.h"
#include <QMainWindow>
#include <QTextBrowser>

unordered_map<int, function<void(QString)>> Logger::listener;
void Logger::Regist(const int key,const function<void(QString)> foo)
{
    if(listener.find(key)==listener.end())
    {
        listener.insert(make_pair(key,foo));
    }
}

void Logger::UnRegist(const int key)
{
    if(listener.find(key)!=listener.end())
    {
        listener.erase(key);
    }
}

Logger::Logger()
{

}


void Logger::Info(const QString & str)
{
    for(auto & foo : listener)
    {
        foo.second(str);
    }
}
