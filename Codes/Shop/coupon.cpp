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

    //保存结果，释放空间
    double result = decorated->cost();
    delete decorated;

    return result;
}

void DiscountCoupon::changeStateToUsed() {
    setCouponState(used);
    cout << "您成功使用了本张折扣优惠券" << '\n';
    cout << "本优惠券打的折扣是 " << getDiscount() << "折" << '\n';
    cout << "期待您的下次使用" << '\n';
}

Coupon* DiscountCoupon::clone(){ 
    DiscountCoupon *clone = new DiscountCoupon(shop, discount);
    return clone;
}

void DiscountCoupon::showInformation(){
    cout<<"本张为折扣优惠券\n";
    cout<<"折扣量为： "<<discount<<'\n';
    cout<<"所属店铺是："<<this->getShop()->getName()<<'\n';
    char* dt = ctime(&outDate);
    cout<<"该优惠券的过期时间为："<<dt<<"\n\n";
}

double FullReduceCoupon::saleMethod(double x) {
    //使用装饰器模式，对原始金额进行减免，返回减免后的金额
    Balance* origin = new ConcreteBalance(x);
    Balance* decorated = new ConcreteDecoratorA(origin,this->standard,this->reduction);

    //保存结果，释放空间
    double result = decorated->cost();
    delete decorated;

    return result;
}

void FullReduceCoupon::changeStateToUsed() {
    setCouponState(used);
    cout << "您成功使用了本张满减优惠券" << '\n';
    cout << "本优惠券为满" << getStandard() << "减" << getReduction() << "！\n";
    cout << "期待您的下次使用" << '\n';
}

Coupon* FullReduceCoupon::clone(){
    FullReduceCoupon *clone = new FullReduceCoupon(shop, standard, reduction);
    return clone;
}

void FullReduceCoupon::showInformation(){
    cout<<"本张为满减优惠券\n";
    cout<<"消费超过"<<standard<<"元时，"<<"可以减去"<<reduction<<"元\n";
    cout<<"所属店铺为："<<this->getShop()->getName()<<'\n';
    char* dt = ctime(&outDate);
    cout<<"该优惠券的过期时间为："<<dt<<"\n\n";
}