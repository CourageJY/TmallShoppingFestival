#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<ctime>

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
    Coupon(Customer *c, Shop *s) : customer(c), shop(s), couponState(unused) {
        time_t lt = time(nullptr);
        outDate = lt + 2592000;
    }

    //使用折扣以后的售价，参数x为原价，返回折后价格
    virtual double saleMethod(double x) { return 0; }

    virtual void changeStateToUsed() { couponState = used; }

    void checkOverdue();

    Customer *getCustomer() { return customer; }

    Shop *getShop() { return shop; }

    CouponState getCouponState() { return couponState; }

    CouponState setCouponState(CouponState cs) { couponState = cs; }

    time_t getOutDate() const { return outDate; }

protected:
    Customer *customer;
    Shop *shop;
    CouponState couponState;
    time_t outDate;

};

//折扣类型的优惠
class DiscountCoupon : public Coupon {
public:
    DiscountCoupon(Customer *c, Shop *s, double ds) : Coupon(c, s), discount(ds) {}

    //返回使用折扣类型使商品打折后的价格
    double saleMethod(double x) override;

    void changeStateToUsed() override;

    double getDiscount() const { return discount; }

private:
    double discount;
};

//满减类型的优惠
class FullReduceCoupon : public Coupon {
public:
    FullReduceCoupon(Customer *c, Shop *s, double std, double rt) : Coupon(c, s), standard(std), reduction(rt) {}

    //返回使用满减类型使商品减价后的价格
    double saleMethod(double x) override;

    void changeStateToUsed() override;

    double getStandard() const { return standard; }

    double getReduction() const { return reduction; }

private:
    double standard;
    double reduction;
};