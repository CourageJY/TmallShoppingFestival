#pragma once
#include<string>
using namespace std;

class Goods;//预声明

class AfterSale{
public:
    AfterSale(Goods* gd):goods(gd){}

    //cout一些内容，暂无业务逻辑
    void repair();

    //cout一些内容
    void exchange();

    Goods* getRelatedGoods(){return goods;}

private:
    Goods* goods;

};