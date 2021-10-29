#pragma once
#include<iostream>
#include"vector"
#include<string>
#include"../PersonalInformation/customer.h"
#include"../Shop/goods.h"
using namespace std;

//退货子操作一，获取用户基本信息
class UserInformation {
public:
    void getUserInformation(Customer* c);
};

//退货子操作二，输入商品名字，获取商品基本信息
class GoodsInformation {
public:
    void getGoodsInformation(Customer* c);
};

//退货子操作三，用户商品容器
class OutputInformation {
public:
    void getOutputInformation();
};

//外观售后类
class AfterSale {
public:
    AfterSale(UserInformation* s1,GoodsInformation* s2,OutputInformation* s3,Customer* c):
            subOperation1(s1),subOperation2(s2),subOperation3(s3),customer(c){}
    //退货接口方法
    void returned();
    Customer* getCustomer(){return customer;}

private:
    UserInformation *subOperation1;
    GoodsInformation *subOperation2;
    OutputInformation *subOperation3;
    Customer* customer;
};