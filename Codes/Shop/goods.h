#pragma once
#include<string>
using namespace std;

class Goods{//商品
public:

    string getName()const{return name;}

    double getPrice()const{return price;}

    //定义一种排序规则，为map服务
    bool operator<(const Goods& gd)const{
        return name<gd.name;
    }

private:
    string name;
    double price;

};