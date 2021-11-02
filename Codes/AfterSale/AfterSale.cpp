#include "AfterSale.h"
#include<windows.h>
void UserInformation::getUserInformation(Customer* c){
    cout<<"您的姓名为:"<<c->getName()<<endl;
    cout<<"您的电话为:"<<c->getTel()<<endl;
    cout<<"您的地址为:"<<c->getAddress()<<endl;
}
void GoodsInformation::getGoodsInformation(Customer* c){
    string goodsName;
    cout<<"请输入您要退货的商品的名字:";
    cin>>goodsName;
    vector<Order>::iterator x;
    vector<Goods>::iterator y;
    for (x=c->getOrders().begin();x!=c->getOrders().end();x++){
        if (x->getState()==paid){
            for (y=x->getGoods().begin();y!=x->getGoods().end();y++){
                if (y->getName()==goodsName){
                    cout<<"当前商品基本信息如下:"<<endl;
                    cout<<"名称:"<<y->getName()<<endl;
                    cout<<"价格:"<<y->getPrice()<<endl;
                    cout<<"所属商店:"<<y->getShop()<<endl;
                }
            }
        }
    }
}
void OutputInformation::getOutputInformation() {
    cout<<"请稍等，您的退货请求正在处理中..."<<endl;
    Sleep(2000);
    cout<<"退货成功!"<<endl;
}
void AfterSale::returned()
{
    subOperation1->getUserInformation(customer);
    subOperation2->getGoodsInformation(customer);
    subOperation3->getOutputInformation();
}