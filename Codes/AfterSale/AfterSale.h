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
    void getGoodsInformation(Customer* c,double& price);
};

//退货子操作三，退货信息展示
class OutputInformation {
public:
    void getOutputInformation();
};

//外观售后类
class AfterSale {
public:
    AfterSale(Customer* c):
            subOperation1(new UserInformation),subOperation2(new GoodsInformation),subOperation3(new OutputInformation),
            customer(c){}
    //退货接口方法
    void returned();
    Customer* getCustomer(){return customer;}

private:
    UserInformation *subOperation1;
    GoodsInformation *subOperation2;
    OutputInformation *subOperation3;
    Customer* customer;
};