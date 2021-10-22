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
    void checkOrders();
    void showCoupons();
    bool payOrder();
    ~Customer(){}

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