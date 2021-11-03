#include <ctime>
#include <iostream>
#include <map>

#include "AfterSale/AfterSale.h"
#include "AfterSale//makeComment.h"
#include "Filter/filter.h"
#include "Mediator/mediator.h"
#include "Order/balance.h"
#include "Order/checkOrder.h"
#include "Order/order.h"
#include "Order/orderState.h"
#include "Order/payment.h"
#include "Page/page.h"
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
void testFacade();
void testFlyWeight();
void testNullObject();
void testProxy();
void testFactory();
void testObserver();
void initial();
void testFilter();
void testState();

int main() {
    //设计模式接口测试
    //testSingleton();
    //testDecorator();
    //testAbstractFactory();
    //testFlyWeight();
    //testNullObject();
    //testProxy();
    //testFactory();
    //testFacade();
    //testFilter();
    //testObserver();
    //testState();
    //初始化各分会场及其店铺信息
    initial();

    //新建顾客
    Customer* customer = new Customer("lky", "13456789", "上海 嘉定", male, 2000);

    //新建主会场
    MainVenue venue;

    //从主会场开始跳转
    venue.showInformation(customer);

    system("pause");
    return 0;
}

void initial()
{
    //服装会场信息添加（这里用了抽象工厂模式创建）
    testAbstractFactory();

    //零食会场信息添加
    SnacksVenue& sv=SnacksVenue::getInstance();
    
    Shop* snack_1 = new Shop("同济零食店","三只松鼠");
    Shop* snack_2 = new Shop("自营零食店","良品铺子");

    snack_1->addGoods(Goods("肉松饼",5,snack_1),10);
    snack_1->addGoods(Goods("辣味金针菇",6.9,snack_1),5); 
    snack_1->addGoods(Goods("小泡芙",9,snack_1),20);


    snack_2->addGoods(Goods("提拉米苏",9.9,snack_2),9);
    snack_2->addGoods(Goods("维他奶",3.8,snack_2),10);
    snack_2->addGoods(Goods("小三明治",8,snack_2),10);

    //添加优惠券
    snack_1->addCoupons(new FullReduceCoupon(snack_1,50,5));
    snack_1->addCoupons(new DiscountCoupon(snack_1,0.97));

    snack_2->addCoupons(new FullReduceCoupon(snack_2,50,5));
    snack_2->addCoupons(new DiscountCoupon(snack_2,0.97));

    sv.addShop(snack_1);
    sv.addShop(snack_2);

    //电气会场信息添加
    ElectronicVenue& ev=ElectronicVenue::getInstance();
    
    Shop* elec_1=new Shop("华为手机店","华为");
    Shop* elec_2=new Shop("华为专卖店","华为");
    Shop* elec_3=new Shop("苹果手机专卖店","APPLE");
    Shop* elec_4=new Shop("苹果电脑专卖店","APPLE");

    //添加商品
    elec_1->addGoods(Goods("nova8",2500,elec_1),4);
    elec_1->addGoods(Goods("P40",4500,elec_2),3);

    elec_2->addGoods(Goods("MatePad",4000,elec_2),4);
    elec_2->addGoods(Goods("MateBook",7000,elec_2),3);

    elec_3->addGoods(Goods("iphone12",6000,elec_3),5);
    elec_3->addGoods(Goods("iphone13",7000,elec_3),4);
    elec_3->addGoods(Goods("iphone13 pro",8000,elec_3),3);

    elec_4->addGoods(Goods("ipad air4",6000,elec_4),4);
    elec_4->addGoods(Goods("ipad pro",7000,elec_4),3);
    
    //添加优惠券
    elec_1->addCoupons(new FullReduceCoupon(elec_1,5000,100));
    elec_1->addCoupons(new DiscountCoupon(elec_1,0.8));

    elec_2->addCoupons(new FullReduceCoupon(elec_2,5500,300));
    elec_2->addCoupons(new DiscountCoupon(elec_2,0.9));

    elec_3->addCoupons(new FullReduceCoupon(elec_3,6000,200));
    elec_3->addCoupons(new DiscountCoupon(elec_3,0.85));

    elec_4->addCoupons(new FullReduceCoupon(elec_4,7000,150));
    elec_4->addCoupons(new DiscountCoupon(elec_4,0.82));

    ev.addShop(elec_1);
    ev.addShop(elec_2);
    ev.addShop(elec_3);
    ev.addShop(elec_4);

    //水果会场信息添加
    FruitsVenue& fv=FruitsVenue::getInstance();

    Shop* fruit_1=new Shop("水果杂铺店", "同济专享");
    Shop* fruit_2=new Shop("西部特产水果店", "新疆经典");
    Shop* fruit_3=new Shop("农家自产水果店", "农家特产");

    fruit_1->addGoods(Goods("小苹果",4,fruit_1),20);
    fruit_1->addGoods(Goods("雪梨",3.5,fruit_2),15);
    fruit_1->addGoods(Goods("大香蕉",5,fruit_1),10);

    fruit_2->addGoods(Goods("葡萄",4,fruit_2),10);
    fruit_2->addGoods(Goods("大西瓜",20,fruit_3),10);
    fruit_2->addGoods(Goods("哈密瓜",25,fruit_2),10);

    fruit_3->addGoods(Goods("小桔子",2,fruit_3),50);
    fruit_3->addGoods(Goods("梁山柚",8,fruit_3),20);
    fruit_3->addGoods(Goods("小地瓜",6,fruit_3),25);

    //添加优惠券
    fruit_1->addCoupons(new FullReduceCoupon(fruit_1,50,5));
    fruit_1->addCoupons(new DiscountCoupon(fruit_1,0.97));

    fruit_2->addCoupons(new FullReduceCoupon(fruit_2,60,5));
    fruit_2->addCoupons(new DiscountCoupon(fruit_2,0.95));

    fruit_3->addCoupons(new FullReduceCoupon(fruit_3,40,5));
    fruit_3->addCoupons(new DiscountCoupon(fruit_3,0.9));

    fv.addShop(fruit_1);
    fv.addShop(fruit_2);
    fv.addShop(fruit_3);

    system("pause");
    
}

//测试单例模式的接口
void testSingleton() {
    ClothingVenue& instance = ClothingVenue::getInstance();
}

//测试装饰器模式
void testDecorator(){
    //顾客实体
    Customer customer("Admin","123456789","CN",male,2000.00);
    //绑定购物车
    ShoppingCart spct(&customer);

    //商店实体
    Shop fruit_1("hhhhhhh", "Happy");

    //新建打折优惠券
    DiscountCoupon cp1(&fruit_1,0.8);
    //cp1.getCustomer()=&customer;
    cp1.setCustomer(&customer);

    //新建减免优惠券
    FullReduceCoupon cp2(&fruit_1,10.00,1.00);
    //cp2.getCustomer()=&customer;
    cp2.setCustomer(&customer);

    //模拟订单原始金额
    double originSum;

    //输入原始金额
    cout<<"请输入模拟订单的原始金额（元）："<<endl;
    cin>>originSum;

    //打折后金额
    double discountSum = cp1.saleMethod(originSum);
    //减免后金额
    double fullReduceSum = cp2.saleMethod(originSum);

    //打印
    cout<<"模拟订单原始金额为："<<originSum<<" 元"<<endl;
    cout<<"使用打折优惠券后金额为："<<discountSum<<" 元"<<endl;
    cout<<"使用减免优惠券后金额为："<<fullReduceSum<<" 元"<<endl;
}

//抽象工厂方法的测试接口，用于为服装商店添加商品
void testAbstractFactory() {  // coded by jy
    //新建安踏服装店
    Shop* antaShop=new Shop("安踏服装店", "安踏");
    //利用安踏工厂生产安踏商品
    ClothingGoodsFactory* antaFactory = new AntaFactory();
    Coats antaCoats = antaFactory->getCoats("安踏外套", 500, antaShop);
    Pants antaPants = antaFactory->getPants("安踏休闲裤", 200, antaShop);
    //加入商店
    antaShop->addGoods(antaCoats, 10);
    antaShop->addGoods(antaPants, 20);

    //新建阿迪服装店
    Shop* adidasShop=new Shop("阿迪达斯服装店", "阿迪达斯");
    //利用阿迪工厂生产安踏商品
    ClothingGoodsFactory* adidasFactory = new AdidasFactory();
    Coats adidasCoats = adidasFactory->getCoats("阿迪外套", 700, adidasShop);
    Pants adidasPants = adidasFactory->getPants("阿迪休闲裤", 300, adidasShop);
    //加入商店
    adidasShop->addGoods(adidasCoats, 5);
    adidasShop->addGoods(adidasPants, 10);

    //获取服装会差单例
    ClothingVenue& clothingVenue = ClothingVenue::getInstance();

    //添加优惠券
    antaShop->addCoupons(new FullReduceCoupon(antaShop,600,50));
    antaShop->addCoupons(new FullReduceCoupon(antaShop,700,80));
    adidasShop->addCoupons(new FullReduceCoupon(adidasShop,800,50));
    adidasShop->addCoupons(new FullReduceCoupon(adidasShop,900,80));
    antaShop->addCoupons(new DiscountCoupon(antaShop,0.9));
    adidasShop->addCoupons(new DiscountCoupon(adidasShop,0.95));

    //在服装会场中添加商店
    clothingVenue.addShop(antaShop);
    clothingVenue.addShop(adidasShop);

    
    //test output
    //antaShop.showInformation();
    //adidasShop.showInformation();
    //antaCoats.showInfo();
    //adidasCoats.showInfo();
}


//测试简单工厂模式和策略模式的接口
void testFactory() {
    Customer *customer=new Customer("Admin","123456789","CN",male,2000.00);
    Shop fruit_1("hhhhhhh", "Happy");
    Goods g1("apple", 5, &fruit_1);
    Goods g2("apple", 5, &fruit_1);
    fruit_1.addGoods(g1,10);
    fruit_1.addGoods(g2,10);
    ShoppingCart* s=customer->getShoppingCart();
    s->addGoods(g1,2);s->addGoods(g2,2);
    s->showAllGoods();
    s->generateOrder(s->getGoodsMap());
    customer->payOrder();
    customer->viewBasicInformation();
}

//测试外观模式的接口
void testFacade() {
    Customer* customer=new Customer("Admin","123456789","CN",male,2000.00);
    Shop fruit_1("hhhhhhh", "Happy");
    Goods g1("apple", 5, &fruit_1);
    Goods g2("apple", 5, &fruit_1);
    fruit_1.addGoods(g1,10);
    fruit_1.addGoods(g2,10);
    ShoppingCart* s=customer->getShoppingCart();
    s->addGoods(g1,2);s->addGoods(g2,2);
    s->showAllGoods();
    s->generateOrder(s->getGoodsMap());
    customer->payOrder();
    customer->viewBasicInformation();
    AfterSale afterSale(customer);
    afterSale.returned();
}
void testState() { Customer* customer=new Customer("Admin","123456789","CN",male,2000.00);
    Shop fruit_1("hhhhhhh", "Happy");
    Goods g1("apple", 5, &fruit_1);
    Goods g2("apple", 5, &fruit_1);
    fruit_1.addGoods(g1,10);
    fruit_1.addGoods(g2,10);
    ShoppingCart* s=customer->getShoppingCart();
    s->addGoods(g1,2);s->addGoods(g2,2);
    s->showAllGoods();
    s->generateOrder(s->getGoodsMap());
    customer->payOrder();
    customer->viewBasicInformation();
    customer->check(); }

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

//测试过滤器模式的接口（coded by ry）
void testFilter(){
    PriceFilter p(0,20);
    FruitsVenue& fruitInstance = FruitsVenue::getInstance();
    p.filterGoods(fruitInstance.getGoods());
}

//测试观察者模式
void testObserver(){
    Customer usera("UserA","123","China",male,2000);
    Customer userb("UserB","456","China",female,3000);
    Customer userc("UserC","789","China",male,4000);
    Shop fruit_1("hhhhhhh", "Happy");
    cout<<"生产商品实体apple。"<<endl;
    Goods apple = Goods("apple", 5 , &fruit_1);
    cout<<"向商店fruit_1添加商品apple。"<<endl;
    fruit_1.addGoods(apple, 10);

    ShoppingCart* spa = usera.getShoppingCart();
    ShoppingCart* spb = userb.getShoppingCart();
    ShoppingCart* spc = userc.getShoppingCart();

    cout<<"向用户userA的购物车添加商品apple。"<<endl;
    spa->addGoods(apple,5);
    cout<<"向用户userB的购物车添加商品apple。"<<endl;
    spb->addGoods(apple,2);
    cout<<"向用户userC的购物车添加商品apple。"<<endl;
    spc->addGoods(apple,1);
    fruit_1.showGoods(&usera);
    cout<<"UserA ";
    spa->showAllGoods();
    cout<<"UserB ";
    spb->showAllGoods();
    cout<<"UserC ";
    spc->showAllGoods();

    fruit_1.pullOffGoods(apple);
    fruit_1.showGoods(&usera);
    cout<<"UserA ";
    spa->showAllGoods();
    cout<<"UserB ";
    spb->showAllGoods();
    cout<<"UserC ";
    spc->showAllGoods();
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
