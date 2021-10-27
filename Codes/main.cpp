#include"Order/order.h"
#include"PersonalInformation/customer.h"
#include"AfterSale/AfterSale.h"
#include"Order/order.h"
#include"PersonalInformation/Comment.h"
#include"Shop/coupon.h"
#include"Shop/goods.h"
#include"Shop/shop.h"
#include"ShoppingCart/shoppingCart.h"
#include"Venue/venue.h"
#include"Order/balance.h"
#include<iostream>
#include<ctime>
#include<map>

void testSingleton();


int main() {
    //以下注释为将时间增加一个月的代码，供参考，2592000是30天对应的秒
//    time_t time1 = time(0);
//
//    time_t time2 = time1 + 2592000;
//
//    char *dt1 = ctime(&time1);
//    cout << dt1 << '\n';
//    char *dt2 = ctime(&time2);
//    cout << dt2 << '\n';

/*
    map<string, int> m;
    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {

    }
*/

//用于测试单例模式的接口
//    testSingleton();
    return 0;
}

void testDecorator() {//测试装饰器模式
    //此处调用订单对象提供接口返回原始金额，现假设为10.00元
    double sum = 10.00;

    //用获取的原始金额初始化内容对象
    Balance *origin = new ConcreteBalance(sum);
    cout << origin->cost() << endl;

    Balance *decorated = NULL;//装饰后的对象

    //一层包装，八折
    decorated = new ConcreteDecorator(origin);
    cout << decorated->cost() << endl;

    //二层包装，六四折
    decorated = new ConcreteDecorator(decorated);
    cout << decorated->cost() << endl;

    delete decorated;

    system("pause");
}

void testSingleton() {//测试单例模式的接口
    ClothingVenue &instance = ClothingVenue::getInstance();
}