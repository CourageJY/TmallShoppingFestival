#include "page.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

//命令构造函数
Command::Command() {
    //cout << "命令创建成功,命令说明:" << descrip << endl;
}

//设置命令的参数
void Command::set(string d) {
    descrip = d;
}

//获取命令描述
string Command::getDescrip() {
    return descrip;
}

//页面构造函数
Page::Page(const char* d) {
    descrip.assign(d);
}

//执行命令
void Page::execute() {
    if(executeCmd >= 0 && executeCmd <= cmds.size()) {
        cmds[executeCmd]->execute();
    }
}

//执行第e条指令
bool Page::execute(int e) {
    executeCmd = e - 1;
    if(!e) {
        return false;
    }
    execute();
    return true;
}

//添加命令
void Page::addCmd(Command* cmd) {
    cmds.push_back(cmd);
}

//构造OriginPage
OriginPage::OriginPage() {
    care = new CareTaker;
}

CareTaker::CareTaker() {
    descrip = "/";
}

CareTaker::~CareTaker() {
    for(int i = 0;i <= mementos.size();i++) {
        delete mementos.top();
        mementos.pop();
    }
}

//设置页面
void OriginPage::setPage(string pageN) {
    page = pageN;
    savePage();
}

//读取页面
string OriginPage::getPage(string pageN) {
    return page;
}

//存储到备忘录
void OriginPage::savePage() {
    care->pushMeme(new Memento(page));
}

//构造函数
Memento::Memento(string pageN) {
    page = pageN;
}

//获取备忘录中存储的页面
string Memento::getPage() {
    return this->page;
}

//增添一条备忘录
void CareTaker::pushMeme(Memento* memento) {
    mementos.push(memento);
    descrip += "/" + memento->getPage();
}

//弹出一条备忘录
void CareTaker::popMeme() {
    mementos.pop();
    descrip = descrip.substr(0,descrip.find_last_of('/'));
}

//获取描述
string CareTaker::getDescrip() {
    return descrip;
}