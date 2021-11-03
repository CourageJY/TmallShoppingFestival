#pragma once
#include<string>
#include <ctime>
#include"../AfterSale/makeComment.h"
using namespace std;

//预声明
class Shop;
class Customer;

class Comment{
public:
    //桥接模式的使用，对店铺进行评论
    Comment(Shop* sp,Customer* cm):shop(sp),customer(cm){
        _time=time(0);
        string s = "";
        s += priceComment();
        s += "\n";
        s += logisticsComment();
        s += "\n";
        s += serviceComment();
        this->writeContent(s);
    }

    //默认会覆盖之前的内容
    void writeContent(string str){content=str;}

    //评论价格
    string priceComment();

    //评论物流
    string logisticsComment();

    // 评论服务
    string serviceComment();

    //获得评论内容
    string getContent(){return content;}

    //获得做评论的顾客
    Customer* getCustomer() { return customer; }

    //获取评论时间
    time_t* getTime(){return &_time;}

private:
    Shop* shop;
    string content;//初始为空，需用成员函数写入
    Customer* customer;
    time_t _time;
};