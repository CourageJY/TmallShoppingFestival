#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "order.h"

class checkOrder;
class orderState
{
public:
	virtual void showOrderInformation(checkOrder* ck)=0;
};

class errorState:public orderState {
public:
    void showOrderInformation(checkOrder *ck);
};

class paidState:public orderState
{
public:
	void showOrderInformation(checkOrder* ck);
};

class unpaidState:public orderState {
public:
    void showOrderInformation(checkOrder *ck);
};
