#include "AfterSale.h"
#include<windows.h>
void UserInformation::getUserInformation(Customer* c){
    cout<<"您的姓名为:"<<c->getName()<<endl;
    cout<<"您的电话为:"<<c->getTel()<<endl;
    cout<<"您的地址为:"<<c->getAddress()<<endl;
}
void GoodsInformation::getGoodsInformation(Customer* c,double& price) {
    string goodsName;
    cout << "请输入您要退货的商品的名字:";
    cin >> goodsName;
    bool result = false;
    vector<Order>::iterator x;
    vector<Goods>::iterator y;
    for (x = c->getOrders().begin(); x != c->getOrders().end(); x++) {
        if (x->getState() == paid) {
            while (1) {
                for (y = x->getGoods().begin(); y != x->getGoods().end(); y++) {
                    if (y->getName() == goodsName) {
                        cout << "当前商品基本信息如下:" << endl;
                        cout << "名称:" << y->getName() << endl;
                        cout << "价格:" << y->getPrice() << endl;
                        cout << "所属商店:" << y->getShop() << endl;
                        result = true;
                        price=y->getPrice();
                        map<Goods, int>& currentMap = y->getShop()->getGoods();
                        map<Goods, int>::iterator it;
                        for (it = currentMap.begin(); it != currentMap.end(); it++) {
                            if (it->first.getName() == goodsName) {
                                it->second++;
                            }
                        }
                    }
                }
                if (result == false) {
                    cout << "没有找到您要退货的商品，请重新输入您要退货的商品的名字:";
                    cin >> goodsName;
                }
                else break;
            }
        }
    }
}
void OutputInformation::getOutputInformation() {
    cout<<"请稍等，您的退货请求正在处理中..."<<endl;
    Sleep(1000);
    cout<<"退货成功!"<<endl;
}
void AfterSale::returned()
{
    double price;
    subOperation1->getUserInformation(customer);
    subOperation2->getGoodsInformation(customer,price);
    subOperation3->getOutputInformation();
    customer->returnMoney(price);
}