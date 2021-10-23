#include "coupon.h"
#include "../PersonalInformation/customer.h"
#include "../Shop/shop.h"

void Coupon::checkOverdue() {
    time_t now = time(0);
    if (now > getOutDate()) setCouponState(overdue);
    cout << "很遗憾，您本张优惠券过期了" << '\n';
}


double DiscountCoupon::saleMethod(double x) {
    return (x * discount);
}

void DiscountCoupon::changeStateToUsed() {
    setCouponState(used);
    cout << "您成功使用了本张折扣优惠券" << '\n';
    cout << "本优惠券打的折扣是 " << getDiscount() << "折" << '\n';
    cout << "期待您的下次使用" << '\n';
}


double FullReduceCoupon::saleMethod(double x) {
    double result = (x < standard) ? x : x - reduction;
    return result;
}

void FullReduceCoupon::changeStateToUsed() {
    setCouponState(used);
    cout << "您成功使用了本张满减优惠券" << '\n';
    cout << "本优惠券为满" << getStandard() << "减" << getReduction() << "！\n";
    cout << "期待您的下次使用" << '\n';
}