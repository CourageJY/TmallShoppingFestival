#pragma once
#include <vector>
#include <string>
#include <iostream>
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

//简单命令类，继承于Command类的模板类，即简单的命令“个别物”
template <class Receiver>
class SimpleCommand :public Command {
public:
    typedef void (Receiver::* Action)();

    SimpleCommand(Receiver* r, Action a) :
        _receiver(r), _action(a) { }

    virtual void execute();
private:
    Action _action;
    Receiver* _receiver;
};

//简单命令模板类的执行函数方法
template <class Receiver>
void SimpleCommand<Receiver>::execute() {
    (_receiver->*_action)();
}

//定义具体的请求类
class AddGoods {
public:
    void Action() {
        cout << "将商品加入购物车" << endl;
    }
};

//定义具体的请求类
class Back {
public:
    void Action() {
        cout << "返回上一级页面" << endl;
    }
};

//页面类，继承于命令类，因为用户可以通过指令完成“进入页面”这一动作，页面也是一个命令
//用户在一个页面中可以使用多个不同的指令,即页面是命令的一个“复合物”
class Page :public Command {
public:
    //本页面的命令列表
    vector<Command* > cmds;

    //没有上一页面时的构造函数
    Page(const char*, const char*);

    //显示页面内容
    void show();  

    //命令的执行过程函数
    virtual void execute();
private:
    //页面是否结束
    bool end;
};
