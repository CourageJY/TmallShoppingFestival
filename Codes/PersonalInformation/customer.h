#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"../ShoppingCart/shoppingCart.h"
#include"../Order/order.h"
#include"../Shop/coupon.h"
#include"../Mediator/mediator.h"
using namespace std;

enum Gender {male,female};//性别的枚举变量
enum LoginState{entity,tourist};//登录状态：实体 or 游客

class AbstractCustomer{
public:
    AbstractCustomer()=default;

    //判断登录的状态是否为游客（空对象模式）
    bool isNull(){
        return state==tourist;
    }

    //显示基本信息
    virtual void viewBasicInformation()=0;

protected:
    LoginState state;
};

class NullCustomer:public AbstractCustomer{
public:
    NullCustomer(){
        state=tourist;
    }

    void viewBasicInformation() override{
        cout<<"You are logining as a tourist, "
              "you only have permission to visit.\n";
    }
};

class Customer:public AbstractCustomer{//顾客（买家）的基本类
public:
    Customer(string nm,string tel,string ar,Gender g,
             double me):name(nm),tel(tel),addr(ar),
             gender(g),money(me){
                 this->state=entity;//为实体顾客
                 cout<<"You create a new customer successfully!\n";
                 shoppingCart = new ShoppingCart(this);
             }

    void viewBasicInformation() override;

    //查看对应状态的orders
    void check();
    //
    void showCoupons();
    //从当前未支付订单中取出一个进行支付
    //若金额不足则返回false
    bool payOrder();
    
    //用户调用中介者类来发送评价，不需要调用店铺
    void writeCommment(Mediator med, Comment com) { med.sendComment(&com); }

    string getName(){return name;}
    string getTel(){return tel;}
    string getAddress(){return addr;}
    double& getMoney(){return money;}

    ShoppingCart* getShoppingCart(){return shoppingCart;}

    vector<Order>& getOrders(){return orders;}

    vector<Coupon>& getCoupons(){return coupons;}

private:
    string name;
    string tel;
    string addr;
    Gender gender;
    double money;
    ShoppingCart* shoppingCart;
    vector<Order> orders;//初始为空
    vector<Coupon> coupons;//初始为空

};