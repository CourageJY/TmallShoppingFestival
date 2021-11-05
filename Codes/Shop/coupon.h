#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include "../Order/balance.h"
using namespace std;

enum CouponState {
    unused, used, overdue
};//未使用、已使用、过期的优惠券

//预声明
class Customer;

//预声明
class Shop;

class Coupon {
public:
    //构造函数默认优惠券使用时间是一个月（30天） 2592000秒
    Coupon(Shop *s) : customer(nullptr), shop(s), couponState(unused) {
        time_t lt = time(nullptr);
        outDate = lt + 2592000;
    }

    //使用折扣以后的售价，参数x为原价，返回折后价格
    virtual double saleMethod(double x) =0;//纯虚函数
    
    //显示优惠券的基本信息
    virtual void showInformation()=0;
    
    virtual void changeStateToUsed() { couponState = used; }

    void checkOverdue();

    //得到顾客指针
    Customer*& getCustomer() { return customer; }

    //设置顾客
    void setCustomer(Customer* cu){
        customer=cu;
    }

    Shop*& getShop() { return shop; }

    CouponState getCouponState() { return couponState; }

    void setCouponState(CouponState cs) { couponState = cs; }

    time_t getOutDate() const { return outDate; }

    virtual Coupon *clone(){};
protected:
    Customer *customer;
    Shop *shop;
    CouponState couponState;
    time_t outDate;

};

//折扣类型的优惠
class DiscountCoupon : public Coupon {
public:
    DiscountCoupon(Shop *s, double ds) : Coupon(s), discount(ds) {}

    //返回使用折扣类型使商品打折后的价格
    double saleMethod(double x) override;

    //显示基本信息
    void showInformation() override;

    void changeStateToUsed() override;

    double getDiscount() const { return discount; }

    Coupon *clone();    //实现原型模式的克隆

private:
    double discount;
};

//满减类型的优惠
class FullReduceCoupon : public Coupon {
public:
    FullReduceCoupon(Shop *s, double std, double rt) : Coupon(s), standard(std), reduction(rt) {}

    //返回使用满减类型使商品减价后的价格
    double saleMethod(double x) override;

    //显示基本信息
    void showInformation() override;

    void changeStateToUsed() override;

    double getStandard() const { return standard; }

    double getReduction() const { return reduction; }

    Coupon *clone();  //实现原型模式的克隆

private:
    double standard;
    double reduction;
};