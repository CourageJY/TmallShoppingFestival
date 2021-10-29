#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "order.h"

class checkOrder;
//抽象状态类
class orderState
{
public:
	virtual void showOrderInformation(checkOrder* ck)=0; //纯虚函数，显示订单信息
};
//已取消订单状态类
class errorState:public orderState {
public:
    void showOrderInformation(checkOrder *ck);
};
//已支付订单状态类
class paidState:public orderState
{
public:
	void showOrderInformation(checkOrder* ck);
};
//未支付订单状态类
class unpaidState:public orderState {
public:
    void showOrderInformation(checkOrder *ck);
};
