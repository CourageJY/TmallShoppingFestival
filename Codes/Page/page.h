#pragma once
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
    void set(string, string);
    //获取命令提示符
    string getPrompt();
    //获取命令描述
    string getDescrip();
protected:
    //命令的提示符
    string prompt;      
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

//页面备忘录类
class Memento {
public:
    //构造函数
    Memento(Page*);

    //获取备忘录中存储的页面
    Page* getPage();
private:
    //备忘录存储的页面
    Page* page;
};

//维护类
class CareTaker {
public:
    //加一条备忘录
    void addMeme(Memento);
    
    //获取第i条备忘录
    Memento getMeme(int);
private:
    //备忘录列表
    vector<Memento> mementos;
};

//页面备忘录创建类
class OriginPage {
public:
    //设置页面
    void setPage(Page*);

    //读取页面
    Page* getPage(Page*);

    //存储到备忘录
    Memento* savePage();

    //从备忘录获取页面
    void getPageMemento(Memento);
private:
    //页面
    Page* page;
};

