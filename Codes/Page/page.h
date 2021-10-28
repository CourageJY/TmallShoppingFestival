#pragma once
#include <vector>
#include <string>
using namespace std;

//命令类，所有用户使用的指令都继承于命令类
class Command {
public:
    //命令的提示符
    string prompt;  
    
    //命令的描述
    string descrip; 

    //命令的执行过程函数
    virtual void execute() = 0; 
protected:
    Command();
};

//页面类，继承于命令类，因为用户可以通过指令完成“进入页面”这一动作，页面也是一个命令
//用户在一个页面中可以使用多个不同的指令,即页面是命令的一个“复合物”
class Page :public Command {
public:
    //没有上一页面时的构造函数
    Page(const char*, const char*);

    //有上一页面时的构造函数
    Page(Page*, const char*, const char*);

    //显示页面内容
    void show();  

    //命令的执行过程函数
    virtual void execute();
private:
    //指向上一个页面的指针
    Page* prePage;  

    //本页面的命令列表
    vector<Command* > cmds; 
};
