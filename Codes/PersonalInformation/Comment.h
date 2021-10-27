#pragma once
#include<string>
#include"../AfterSale/makeComment.h"
using namespace std;

//预声明
class Goods;
class Customer;

class Comment{
public:
    Comment(Goods* gd,Customer* cm):goods(gd),customer(cm){}

    //默认会覆盖之前的内容
    void writeContent(string str){content=str;}

    string priceComment();

    string logisticsComment();

    string serviceComment();

    //获得评论内容
    string getContent(){return content;}

    Customer* getCustomer() { return customer; }

private:
    Goods* goods;
    string content;//初始为空，需用成员函数写入
    Customer* customer;

};