#pragma once
#include<string>
using namespace std;

//预声明
class Goods;
class Customer;

class Comment{
public:
    Comment(Goods* gd,Customer* cm):goods(gd),customer(cm){}

    //默认会覆盖之前的内容
    void writeContent(string str){content=str;}

    //获得评论内容
    string getContent(){return content;}

private:
    Goods* goods;
    string content;//初始为空，需用成员函数写入
    Customer* customer;

};