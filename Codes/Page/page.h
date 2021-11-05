#pragma once
#include <stack>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//命令类，所有用户使用的指令都继承于命令类
class Command {
public:
    //命令的执行过程函数
    virtual void execute() = 0; 
    //设置命令的参数
    void set(string);
    //获取命令描述
    string getDescrip();
protected:    
    //命令的描述
    string descrip; 
    Command();
};

//简单命令类，继承于Command类的模板类，即简单的命令“个别物”
template <class Receiver>
class SimpleCommand :public Command {
public:
    typedef void (Receiver::* Action)();

    SimpleCommand(Receiver* r, Action a) :
        receiver(r), action(a) { }

    virtual void execute();
private:
    Action action;
    Receiver* receiver;
};

//简单命令模板类的执行函数方法
template <class Receiver>
void SimpleCommand<Receiver>::execute() {
    (receiver->*action)();
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
    //构造函数
    Page(const char*); 

    //添加命令
    void addCmd(Command*);
    void clearCmd(){
        cmds.clear();
    };//清空命令

    //命令的执行过程函数
    virtual void execute();
    virtual bool execute(int);
private:
    //本页面的命令列表
    vector<Command* > cmds;
    int executeCmd;
};

//页面备忘录类
class Memento {
public:
    //构造函数
    Memento(string);

    //获取备忘录中存储的页面
    string getPage();
private:
    //备忘录存储的页面
    string page;
};

//维护类
class CareTaker {
public:
    CareTaker();
    ~CareTaker();
    //增添一条备忘录
    void pushMeme(Memento*);    
    //弹出备忘录
    void popMeme();
    //获取描述
    string getDescrip();
private:
    //描述
    string descrip;
    //备忘录列表
    stack<Memento*> mementos;
};

//页面备忘录创建类
class OriginPage {
public:
    OriginPage();
    //设置页面
    void setPage(string);
    //读取页面
    string getPage(string);
    //存储到备忘录
    void savePage();
    CareTaker* care;
private:
    //页面
    string page;
};

