#pragma once
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "../Shop/coupon.h"
#include "../Shop/goods.h"
#include "brand.h"
using namespace std;

//预声明
class Customer;
class Comment;
class Shop {
public:

    Shop(string na, const string& bd) : name(std::move(na)) {//shop里的品牌使用了享元模式构建
        BrandFactory& bf=BrandFactory::getInstance();
        brand=bf.getBrand(bd);
    };

    //返回店铺名
    string& getName() { return this->name; };

    //返回店铺品牌
    Brand* getBrand() { return this->brand; };

    //输出关于店铺的一些信息
    void showInformation(Customer* customer);

    //顾客通过此方法可获得优惠券
    //函数为纯虚函数，将Shop类变为抽象类，以便实现模板模式
    virtual bool getCoupons(Customer* cm){return true;};

    vector<Comment*>& getComments() {return comments; };

    //店铺收到评价
    void receiverComment(Comment* com) { this->comments.push_back(com); };//operate

    //店铺添加商品
    void addGoods(Goods goods, int stock);

    //统一设置商品属性
    void setGoods(vector<string> names, vector<double> prices,
                  vector<int> months);

    //返回店铺所有商品
    map<Goods, int> getGoods() { return goods; };

    //显示所有商品
    void showGoods();

    //显示店铺评价
    void showComments();

    //下架商品，为实现Observer模式添加的功能
    void pullOffGoods(Goods gd);

   private:
    string name;
    Brand* brand;//这里使用了指针，直接指向享元的内存池，减少内存消耗
    map<Goods, int> goods;  // map类型
    vector<Coupon> coupons;
    vector<Comment*> comments;            //关于该店铺商品评论的集合

};

/*******************
 * 编辑历史：
 * 将获得优惠券的函数更改为纯虚函数，将shop变为抽象类，以便体现模板模式
 * 添加下架商品方法pullOffGoods(Goods gd)，当商品被下架时通知所有购物车中含有该商品的购物车，以实现观察者模式





********************/