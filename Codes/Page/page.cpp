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

//设置页面
void OriginPage::setPage(Page* pageN) {
    this->page = pageN;
}

//读取页面
Page* OriginPage::getPage(Page* pageN) {
    return page;
}

//存储到备忘录
Memento* OriginPage::savePage() {
    return new Memento(page);
}

//从备忘录获取页面
void OriginPage::getPageMemento(Memento memento) {
    this->page = memento.getPage();
}

//构造函数
Memento::Memento(Page* pageN) {
    this->page = pageN;
}

//获取备忘录中存储的页面
Page* Memento::getPage() {
    return this->page;
}

//加一条备忘录
void CareTaker::addMeme(Memento memento) {
    mementos.push_back(memento);
}

//获取第i条备忘录
Memento CareTaker::getMeme(int i) {
    return mementos[i];
}