#include"order.h"
#include"../PersonalInformation/customer.h"
#include"../Shop/goods.h"

bool Order::pay(){
    if(orderState!=unpaid){
        cout<<"error! 此订单不为待支付状态\n";
        return false;
    }
    cout<<"OK! 您已成功支付了该订单\n";
    orderState=paid;
    return true;
}

void Order::showOrder(){
    string str;
    if(orderState==unpaid)str="待支付";
    else if(orderState==paid)str="已支付";
    else str="已取消";
    cout<<"订单拥有者:"<<customer->getName()<<'\n';
    cout<<"状态："<<str<<'\n';
    cout<<"该订单的商品为：\n";
    for(auto gd:goods){
        cout<<gd.getName()<<' ';
    }
    cout<<'\n';
}

void Order::addGoods(Goods gd){
    goods.push_back(gd);
    sum+=gd.getPrice();
}