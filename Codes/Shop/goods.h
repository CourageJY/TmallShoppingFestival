#pragma once
#include<ctime>
#include<string>
#include"../PersonalInformation/Comment.h"
using namespace std;

#define month 2592000 //30天共有的秒数

//预声明
class Shop;

class Goods{//商品
public:
    Goods(string na, double pr, Shop* sh) :name(na), price(pr), outDate(time(0) + 12 * month),
        shop(sh), comment(Comment(this, nullptr)) {}

    string getName()const{return name;}

    double getPrice()const{return price;}

    time_t getOutDate()const{return outDate;}

    Comment& getComment(){return comment;}

    Shop* getShop()const { return shop; }

    void setGoods(string na, double pr, time_t time);

    //定义一种大小规则，为map服务
    bool operator<(const Goods& gd)const{
        return name<gd.name;
    }

private:
    string name;
    double price;
    time_t outDate;//过期时间,默认为创建商品后的一年时间
    Shop* shop;
    Comment comment;//每个商品对应着有一条评论

};