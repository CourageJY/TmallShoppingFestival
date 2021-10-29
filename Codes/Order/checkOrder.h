#pragma once
#include "orderState.h"
#include "../PersonalInformation/customer.h"

//工作类checkOrder
class checkOrder{
private:
    orderState* current;
    int orderType;
    Customer* customer;
public:
    checkOrder(int o,Customer* c):orderType(o),customer(c),current(new unpaidState){}

    //设置当前状态对象，用于状态的转换
    void setState(orderState* o);

    //工作类对外接口，功能为展示订单信息
    void showInformation();
    int getOrderType(){return orderType;}
    Customer* getCustomer(){return customer;}
};
