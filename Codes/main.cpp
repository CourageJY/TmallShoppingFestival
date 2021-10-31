#include <ctime>
#include <iostream>
#include <map>

#include "AfterSale/AfterSale.h"
#include "Order/balance.h"
#include "Order/order.h"
#include "PersonalInformation/Comment.h"
#include "PersonalInformation/SearchEngine.h"
#include "PersonalInformation/customer.h"
#include "Shop/brand.h"
#include "Shop/clothingGoodsFactory.h"
#include "Shop/coupon.h"
#include "Shop/goods.h"
#include "Shop/shop.h"
#include "ShoppingCart/shoppingCart.h"
#include "Venue/venue.h"

void testSingleton();
void testDecorator();
void testAbstractFactory();
void testFlyWeight();

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

    ////测试抽象工厂
    //    testAbstractFactory();
    //    ClothingVenue& clothingVenue=ClothingVenue::getInstance();
    //    clothingVenue.showBasicInformation();

    //    //测试享元模式
    //    testFlyWeight();

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

    cout << "不要有中文乱码呀！！1\n";

    system("pause");
    return 0;
}

void testSingleton() {  //测试单例模式的接口
    ClothingVenue& instance = ClothingVenue::getInstance();
}

//抽象工厂方法的测试接口，用于为服装商店添加商品
void testAbstractFactory() {  // coded by jy
    //新建安踏服装店
    Shop antaShop("安踏服装店", "安踏");
    //利用安踏工厂生产安踏商品
    ClothingGoodsFactory* antaFactory = new AntaFactory();
    Coats antaCoats = antaFactory->getCoats("安踏外套", 500, &antaShop);
    Pants antaPants = antaFactory->getPants("安踏休闲裤", 200, &antaShop);
    //加入商店
    antaShop.addGoods(antaCoats, 10);
    antaShop.addGoods(antaPants, 20);

    //新建阿迪服装店
    Shop adidasShop("阿迪达斯服装店", "阿迪达斯");
    //利用阿迪工厂生产安踏商品
    ClothingGoodsFactory* adidasFactory = new AdidasFactory();
    Coats adidasCoats = adidasFactory->getCoats("阿迪外套", 700, &antaShop);
    Pants adidasPants = adidasFactory->getPants("阿迪休闲裤", 300, &antaShop);
    //加入商店
    adidasShop.addGoods(antaCoats, 5);
    adidasShop.addGoods(antaPants, 10);

    //获取服装会差单例
    ClothingVenue& clothingVenue = ClothingVenue::getInstance();
    //在服装会场中添加商店
    clothingVenue.addShop(antaShop);
    clothingVenue.addShop(adidasShop);

    // test output
    //    antaShop.showInformation();
    //    adidasShop.showInformation();
    antaCoats.showInfo();
    adidasCoats.showInfo();
}

//测试工厂模式的接口
void testFactory(Customer* c) { c->payOrder(); }
//测试外观模式的接口
void testFacade(Customer* c) {
    AfterSale afterSale(c);
    afterSale.returned();
}
void testState(Customer* c) { c->check(); }

//测试享元模式的接口（coded by jy）
void testFlyWeight() {
    //测试共享属性
    Shop applePhone("苹果手机专卖店", "APPLE");
    Shop macShop("苹果电脑专卖店", "APPLE");
    Shop huiWeiShop("华为自营店", "HUAWEI");
    //测试非共享属性
    Address ad_1("中国", "上海");
    Address ad_2("美国", "纽约");
    macShop.getBrand()->showAddress(ad_1);
    // applePhone.getBrand()->showAddress(ad_2);
    // Brand* b=new SharedBrand;
    // b->showAddress(ad_1);
}