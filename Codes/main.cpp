#include <ctime>
#include <iostream>
#include <map>
#include <vector>

#include "tools.h"
#include "AfterSale//makeComment.h"
#include "AfterSale/AfterSale.h"
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
#include "Shop/phoneBuilder.h"
#include "Shop/shop.h"
#include "ShoppingCart/shoppingCart.h"
#include "User/user.h"
#include "Venue/venue.h"

using namespace std;

int main() {
    system("pause");
    //初始化各分会场及其店铺信息
    initial();
    //新建顾客
    vector<Customer*> customers;  //登录过的用户
    Customer* customer;
    AbstractCustomer* absc;

    //新建主会场
    MainVenue venue;
    //从主会场开始跳转
    ProxyPatternCustomer* proxyPatternCustomer =new ProxyCustomer("lkyProfile.jpg");

    //新建主会场的Page类
    Page* mainPage = new Page("主会场");
    while (1) {
        bool isTourist;
        string userName = welcome(isTourist);  //欢迎界面，返回用户名
        int registeredNum = customers.size();
        if (registeredNum >0&&!isTourist) {  //如果该用户是已经登陆过的用户，则直接登录，否则创建并保存。
            for (int i = 0; i < registeredNum; i++) {
                if (customers[i]->getName() == userName) {
                    customer = customers[i];
                    absc=customer;
                    break;
                }
                if (i == registeredNum - 1) {
                    customer = new Customer(userName, "123456789", "上海 嘉定",male, 5000);
                    customers.push_back(customer);
                    absc=customer;
                }
            }
        } 
        else {
            if(isTourist){
                absc=new NullCustomer();
                customer =new Customer("游客", "", "", male, 0);
            }
            else{
                customer =new Customer(userName, "123456789", "上海 嘉定", male, 5000);
                customers.push_back(customer);
                absc=customer;
            }
            
        }
        //备忘录
        customer->originpage->setPage("主会场");
        initPage(mainPage, customer, proxyPatternCustomer,absc);

        venue.showInformation(customer, proxyPatternCustomer, mainPage,absc);
        system("pause");
        if (chooseExit()) {  //是否选择退出
            break;
        }
    }
    return 0;
}
