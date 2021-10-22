#pragma once
#include<string>
#include"../Shop/goods.h"
//#include"../PersonalInformation/customer.h"
using namespace std;

enum OrderState {unpaid,paid,error};//待支付、已支付、失败的订单

class Customer;//预申明，防止相互包含

class Order{
public:
    Order(Goods* g,Customer* c):goods(g),customer(c),orderState(unpaid){}
    OrderState getState(){return orderState;}

private:
    Goods* goods;
    Customer* customer;
    OrderState orderState;//订单状态,初始化为待支付
    time_t date;//订单的最新时间(?)

};