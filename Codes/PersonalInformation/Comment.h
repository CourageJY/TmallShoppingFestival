#pragma once
#include<string>
#include"../AfterSale/makeComment.h"
using namespace std;

//预声明
class Shop;
class Customer;

class Comment{
public:
    Comment(Shop* sp,Customer* cm):shop(sp),customer(cm){
        
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

    string priceComment();

    string logisticsComment();

    string serviceComment();

    //获得评论内容
    string getContent(){return content;}

    Customer* getCustomer() { return customer; }

private:
    Shop* shop;
    string content;//初始为空，需用成员函数写入
    Customer* customer;

};