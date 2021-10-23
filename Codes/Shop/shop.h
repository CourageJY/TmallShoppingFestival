#pragma once
#include<map>
#include"coupon.h"
class Shop{
public:
    void showinformation();
    bool getCoupons(Customer* cm);
private:
    string name;
    string brand;
    map<Goods,int> goods;
    Coupon coupons;
};