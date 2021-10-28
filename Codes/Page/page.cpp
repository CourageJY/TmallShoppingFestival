#include "page.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//命令构造函数
Command::Command() {
    cout << "命令{" << prompt << "}创建成功,命令说明:" << descrip << endl;
}

//页面构造函数
Page::Page(const char* p, const char* d) {
    prePage = NULL;
    prompt.assign(p);
    descrip.assign(d);
}

//页面构造函数
Page::Page(Page* pre, const char* p, const char* d) {
    prePage = pre;
    prompt.assign(p);
    descrip.assign(d);
}

//进入页面
void Page::execute() {
    //显示页面
    show();
}

//显示页面内容
void Page::show() {
    //打印命令列表等内容
    cout << "这里是{" << descrip <<"}页面" << endl;
}

//一个测试函数，创建一个主页面实例并执行
void testPage() {    
    Page Home("home", "主会场");
    Home.execute();
}