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

    //输出关于店铺的一些信息
    void showInformation();

    //顾客通过此方法可获得优惠券
    bool getCoupons(Customer* cm);

    vector<Comment*>& getComments(){return comments;}

private:
    string name;
    string brand;
    map<Goods,int> goods;//map类型
    vector<Coupon> coupons;
    vector<Comment*> comments;//关于该店铺商品评论的集合

};