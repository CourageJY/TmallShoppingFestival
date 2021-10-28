#pragma once
#include "orderState.h"
#include "../PersonalInformation/customer.h"
class checkOrder{
private:
    orderState* current;
    int orderType;
    Customer* customer;
public:
    checkOrder(int o,Customer* c):orderType(o),customer(c),current(NULL){}
    void setState(orderState* o);
    void showInformation();
    int getOrderType(){return orderType;}
    Customer* getCustomer(){return customer;}
};
