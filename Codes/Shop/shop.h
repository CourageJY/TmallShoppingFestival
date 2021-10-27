#pragma once
#include<map>
#include<vector>
#include<string>
#include"../Shop/coupon.h"
#include"../Shop/goods.h"
using namespace std;

//预声明
class Customer;
class Comment;

class Shop{
public:
    Shop(string na,string bd):name(na),brand(bd){}

    //返回店铺名
    string getName() { return this->name; }

    //返回店铺品牌
    string getBrand() { return this->brand; }

    //输出关于店铺的一些信息
    void showInformation();

    //顾客通过此方法可获得优惠券
    bool getCoupons(Customer* cm);

    vector<Comment*>& getComments(){return comments;}

    //店铺收到评价
    void receiverComment(Comment* com) { this->comments.push_back(com); }

    //店铺添加商品
    void addGoods(Goods goods, int stock);

    //统一设置商品属性
    void setGoods(vector<string> names, vector<double> prices, vector<time_t> times);

    //返回店铺所有商品
    map<Goods, int> getGoods() { return goods; }

    //显示所有商品
    void showGoods();

    //显示店铺评价
    void showComments();

private:
    string name;
    string brand;
    map<Goods,int> goods;//map类型
    vector<Coupon> coupons;
    vector<Comment*> comments;//关于该店铺商品评论的集合

};