#pragma once
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "../Shop/coupon.h"
#include "../Shop/goods.h"
#include "brand.h"
#include "commentList.h"
using namespace std;

//预声明
class Customer;
class Comment;

class Shop {
   public:
    Shop(string na, const string& bd)
        : name(std::move(na)) {  // shop里的品牌使用了享元模式构建
        BrandFactory& bf = BrandFactory::getInstance();
        brand = bf.getBrand(bd);
        ConcreteAggregate* _ca = new ConcreteAggregate();
        ca = _ca;
    };

    void addGoods(Goods goods, int stock);  //店铺添加商品
    void addCoupons(Coupon* coupon) { coupons.push_back(coupon); }  //添加优惠券
    void addComment(Customer* cu);  //添加店铺评论
    void setGoods(vector<string> names, vector<double> prices,
                  vector<int> months);              //统一设置商品属性
    string getName() { return this->name; };        //返回店铺名
    Brand* getBrand() { return this->brand; };      //返回店铺品牌
    map<Goods, int>& getGoods() { return goods; };  //返回店铺所有商品
    virtual bool getCoupons(Customer* cm) {
        return true;
    };  //顾客通过此方法可获得优惠券
    void receiveComment(Comment* com) {
        ca->add(com);
    };                                         // operate//店铺收到评价
    void showComments();                       //显示店铺评价
    void showCoupons(Customer* customer);      //显示店铺优惠券
    void showFilterGoods(Customer* customer);  //显示筛选商品
    void showGoods(Customer* customer);        //显示所有商品
    void showInformation(Customer* customer);  //输出关于店铺的一些信息

    void setIterator(ConcreteAggregate* cu) { this->ca = cu; }  //设置迭代器

    void pullOffGoods(Goods gd);  //下架商品，为实现Observer模式添加的功能

   private:
    Brand* brand;  //这里使用了指针，直接指向享元的内存池，减少内存消耗
    ConcreteAggregate* ca;  //关于该店铺商品评论的集合
    map<Goods, int> goods;  // map类型
    string name;
    vector<Coupon*> coupons;
    // vector<Comment*> comments;
};

/*******************
 * 编辑历史：
 * 添加下架商品方法pullOffGoods(Goods
gd)，当商品被下架时通知所有购物车中含有该商品的购物车，以实现观察者模式


********************/