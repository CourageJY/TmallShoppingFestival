#pragma once
#include<map>
#include<string>
#include"../Shop/goods.h"
using namespace std;

//预声明
class Customer;

class ShoppingCart{
public:
    ShoppingCart(Customer* c){
        this->customer = c;
    }
    void addGoods(Goods gd);
    bool removeGoods(Goods gd);
    bool getGoods(string name,Goods& gd);

    //输入为一个Goods的数组指针
    //若商品售罄则返回false
    bool generateOrder(map<Goods,int> gds);
    map<Goods,int>& getGoodsMap(){return goods;}

    //Observer同步更新
    void update(Goods*);

private:
    map<Goods,int> goods;//为一个map的key-value映射表，初始为空
    Customer *customer;
};