#include <ctime>
#include <iostream>
#include <map>

#include "AfterSale/AfterSale.h"
#include"AfterSale//makeComment.h"
#include"Criteria//criteria.h"
#include"Mediator/mediator.h"
#include "Order/balance.h"
#include"Order/checkOrder.h"
#include "Order/order.h"
#include"Order/orderState.h"
#include"Order/payment.h"
#include"Page/page.h"
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
#include "User/user.h"

void testSingleton();
void testDecorator();
void testAbstractFactory();
void testFlyWeight();
void testNullObject();
void testProxy();

int main() {
//设计模式接口测试
//    testSingleton();
//    testDecorator();
//    testAbstractFactory();
//    testFlyWeight();
//    testNullObject();
//    testProxy();

    cout<<"中文\n";

/*
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


    system("pause");

*/
    return 0;
}

//测试单例模式的接口
void testSingleton() {
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

//测试简单工厂模式和策略模式的接口
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
    Shop applePhone("store of apple phone", "APPLE");
    Shop macShop("store of mac", "APPLE");
    Shop huiWeiShop("HuaWei's store", "HUAWEI");
    //测试非共享属性
    Address ad_1("China", "ShangHai");
    Address ad_2("America", "NewYork");
    dynamic_cast<SharedBrand*>(macShop.getBrand())->showAddress(ad_1);
    //applePhone.getBrand()->showAddress(ad_2);
    //Brand* b=new SharedBrand;
    //b->showAddress(ad_1);
}

//测试空对象模式（coded by jy）
void testNullObject(){
    //实体
    Customer customer("CourageJ","123","China",male,1000);
    customer.viewBasicInformation();
    //空对象
    NullCustomer tourist;
    tourist.viewBasicInformation();

    //AbstractCustomer* cm=new Customer("CourageJ","123","china",male,1000);
    //dynamic_cast<Customer*>(cm)->viewBasicInformation();//动态类型转换
};

//测试代理模式的接口（coded by Lky）
void testProxy(){
    Customer customer("NoMirror","456","China",male,2000);
    ProxyPatternCustomer *proxyPatternCustomer = new ProxyCustomer("testProfile.jpg");
    proxyPatternCustomer->giveRealCustomer(&customer);
    // The profile will be loaded from disk
    proxyPatternCustomer->viewBasicInformation();
    cout << "\n";
    cout << "The profile has initialized ,does not need to be loaded from disk" << endl;
    proxyPatternCustomer->viewBasicInformation();
}

//欢迎登录界面
void welcome(){
    string userName;   //输入的用户名
    cout<<"欢迎来到天猫购物节！"<<endl;
    cout<<"请先登录，输入用户名：";
    cin>>userName;
    while(!(setUsers()->interpret(userName))){  //如果输入的用户名不合法，则重新输入
        cout<<"用户名错误，请重新输入：";
        cin>>userName;
    }
    cout<<"登录成功！"<<endl;
}
