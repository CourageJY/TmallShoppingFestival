#pragma once
#include<ctime>
#include<string>
#include<vector>
#include"../PersonalInformation/Comment.h"
using namespace std;

#define month 2592000 //30天共有的秒数

//预声明
class Shop;
class ShoppingCart;

class Goods{//商品
public:
    Goods(string na, double pr, Shop* sh) :name(na), price(pr), outDate(time(0) + 12 * month),
        shop(sh), comment(Comment(this, nullptr)) {}

    //商品下架（即对象析构）时，通知所有Observers
    ~Goods(){notify();}

    string getName()const{return name;}

    double getPrice()const{return price;}

    string getOutDate()const{
        char s[32];
        strftime(s, sizeof(s), "%Y-%m-%d", localtime(&outDate));
        return string(s);
    }

    Comment& getComment(){return comment;}

    Shop* getShop()const { return shop; }

    void setGoods(string na, double pr, int mons);

    //定义一种大小规则，为map服务
    bool operator<(const Goods& gd)const{
        return name<gd.name;
    }

    //添加Observer
    void attach(ShoppingCart*);
    
    //删除Observer
    void detach(ShoppingCart*);

    //Observer模式的通知函数，注意：在shoppingCart.h中实现
    void notify();

private:
    string name;
    double price;
    time_t outDate;//过期时间,默认为创建商品后的一年时间
    Shop* shop;
    Comment comment;//每个商品对应着有一条评论
    vector<ShoppingCart*> m_observer;//Observers列表
};