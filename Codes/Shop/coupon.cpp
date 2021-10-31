#include "coupon.h"
#include "../PersonalInformation/customer.h"
#include "../Shop/shop.h"

void Coupon::checkOverdue() {
    time_t now = time(0);
    if (now > getOutDate()) setCouponState(overdue);
    cout << "很遗憾，您本张优惠券过期了" << '\n';
}


double DiscountCoupon::saleMethod(double x) {
    //使用装饰器模式，对原始金额进行打折，返回打折后的金额
    Balance* origin = new ConcreteBalance(x);
    Balance* decorated = new ConcreteDecoratorB(origin,this->discount);
    return (decorated->cost());
}

void DiscountCoupon::changeStateToUsed() {
    setCouponState(used);
    cout << "您成功使用了本张折扣优惠券" << '\n';
    cout << "本优惠券打的折扣是 " << getDiscount() << "折" << '\n';
    cout << "期待您的下次使用" << '\n';
}

DiscountCoupon* DiscountCoupon::clone(){
    DiscountCoupon *clone = new DiscountCoupon(customer, shop, discount);
    return clone;
}

double FullReduceCoupon::saleMethod(double x) {
    //使用装饰器模式，对原始金额进行减免，返回减免后的金额
    Balance* origin = new ConcreteBalance(x);
    Balance* decorated = new ConcreteDecoratorA(origin,this->standard,this->reduction);
    return (decorated->cost());
}

void FullReduceCoupon::changeStateToUsed() {
    setCouponState(used);
    cout << "您成功使用了本张满减优惠券" << '\n';
    cout << "本优惠券为满" << getStandard() << "减" << getReduction() << "！\n";
    cout << "期待您的下次使用" << '\n';
}

FullReduceCoupon* FullReduceCoupon::clone(){
    FullReduceCoupon *clone = new FullReduceCoupon(customer, shop, standard, reduction);
    return clone;
}