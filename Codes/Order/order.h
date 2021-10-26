#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"../Shop/goods.h"
using namespace std;

enum OrderState {unpaid,paid,error};//待支付、已支付、已取消的订单

//预声明
class Customer;
class Coupon;

class Order{
public:
    Order(Customer* c):customer(c),orderState(unpaid){}

    //输出有关订单支付的信息，若订单状态为待支付则返回true
    bool pay();

    //输出有关订单的信息
    void showOrder();

    //添加商品
    void addGoods(Goods gd);

    OrderState getState(){return orderState;}

    vector<Goods>& getGoods(){return goods;}

    Customer* getCustomer(){return customer;}

    time_t& getDate(){return date;}

    Coupon* getCoupon(){return coupon;}

    double getSum(){return sum;}

private:
    vector<Goods> goods;//该订单包含的商品列表，初始为空
    Customer* customer;
    OrderState orderState;//订单状态,初始化为待支付
    time_t date;//订单的最新时间
    Coupon* coupon;//与此订单关联的优惠券
    double sum;//该订单的总金额

};