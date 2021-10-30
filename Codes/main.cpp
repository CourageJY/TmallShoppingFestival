#include"Order/order.h"
#include"PersonalInformation/customer.h"
#include"AfterSale/AfterSale.h"
#include"Order/order.h"
#include"PersonalInformation/Comment.h"
#include"Shop/coupon.h"
#include"Shop/goods.h"
#include"Shop/shop.h"
#include"ShoppingCart/shoppingCart.h"
#include"PersonalInformation/SearchEngine.h"
#include"Venue/venue.h"
#include"Order/balance.h"
#include<iostream>
#include<ctime>
#include<map>

void testSingleton();
void testDecorator();

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

    Customer c("cnm", "134560", "14", male, 1222.4);

    Shop fruit_1("hhhhhhh", "Happy");
    fruit_1.addGoods(Goods("apple", 5, &fruit_1), 10);
    fruit_1.addGoods(Goods("banana", 25, &fruit_1), 10);

    Shop fruit_2("ssssss", "Sad");
    fruit_2.addGoods(Goods("pear", 10, &fruit_2), 10);
    fruit_2.addGoods(Goods("orange", 30, &fruit_2), 10);

    Shop fruit_3("bbbbbb", "Boring");
    fruit_3.addGoods(Goods("mango", 15, &fruit_3), 10);
    fruit_3.addGoods(Goods("grape", 35, &fruit_3), 10);


    FruitsVenue& fruitInstance = FruitsVenue::getInstance();
    fruitInstance.addShop(fruit_1);
    fruitInstance.showBasicInformation();


    FruitsVenue& fruitInstance1 = FruitsVenue::getInstance();
    fruitInstance1.addShop(fruit_3);
    fruitInstance1.showBasicInformation();

    MainVenue venue;
    SearchEngine s;
    s.searchGoods();
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