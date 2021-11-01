#include "page.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

//命令构造函数
Command::Command() {
    cout << "命令{" << prompt << "}创建成功,命令说明:" << descrip << endl;
}

//页面构造函数
Page::Page(const char* p, const char* d) {
    end = false;
    prompt.assign(p);
    descrip.assign(d);
}

//进入页面
void Page::execute() {
    string cmd;
    //等待用户输入命令
    while (!end) {
        //清屏
        system("cls");
        //显示页面
        show();

        cout << "请输入命令:" << endl;
        cin >> cmd;
        //找到匹配命令执行
        for (int i = 0; i < cmds.size(); i++) {
            if (cmds[i]->getPrompt() == cmd) {
                cmds[i]->execute();
                if (cmds[i]->getPrompt() == string("back")) {
                    end = true;
                }
            }
        }
    }
}

//显示页面内容
void Page::show() {
    //打印命令列表等内容
    cout << "这里是{" << descrip << "}页面" << endl;

    //打印命令列表
    cout << "命令列表" << endl;
    for (int i = 0; i < cmds.size(); i++) {
        cout << i + 1 << "." << cmds[i]->getPrompt() << " : " << cmds[i]->getDescrip() << endl;
    }
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

//这是一个测试函数，可以放到main.cpp中进行测试
void testPage() {
    //定义页面类
    Page* home = new Page("home", "主会场");
    Page* search = new Page("search", "搜索商品");
    //定义简单命令
    AddGoods addRcvr;
    Command* addCmd = new SimpleCommand<AddGoods>(&addRcvr, &AddGoods::Action);
    Back backRcvr;
    Command* backCmd = new SimpleCommand<Back>(&backRcvr, &Back::Action);

    //初始化命令
    addCmd->set("addGoods", "将商品加入购物车");
    backCmd->set("back", "返回上一级页面");
    //初始化页面的命令列表
    home->cmds.push_back(search);
    home->cmds.push_back(addCmd);
    search->cmds.push_back(addCmd);
    search->cmds.push_back(backCmd);

    //进入主页面
    home->execute();
}