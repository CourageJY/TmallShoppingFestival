#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"../Order/order.h"
#include"../Shop/coupon.h"
#include"../ShoppingCart/shoppingCart.h"
using namespace std;

enum Gender {male,female};//性别的枚举变量

class Customer{//顾客（买家）的基本类
public:
    Customer(string nm,string tel,string ar,Gender g,
             double me,ShoppingCart s):name(nm),tel(tel),addr(ar),
             gender(g),money(me),shoppingCart(s){
                 cout<<"You create a new customer successfully!\n";
             }
    void viewBasicInformation();
    //查看对应状态的orders
    void checkOrders();
    void showCoupons();
    //从当前未支付订单中取出一个进行支付
    //若金额不足则返回false
    bool payOrder();
    string getName(){return name;}
    double& getMoney(){return money;}
    ShoppingCart& getShoppingCart(){return shoppingCart;}
    vector<Order>& getOrders(){return orders;}
    vector<Coupon>& getCoupons(){return coupons;}

private:
    string name;
    string tel;
    string addr;
    Gender gender;
    double money;
    ShoppingCart shoppingCart;
    vector<Order> orders;//初始为空
    vector<Coupon> coupons;//初始为空

};