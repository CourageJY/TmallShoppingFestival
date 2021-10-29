#include "orderState.h"
#include "checkOrder.h"
void errorState::showOrderInformation(checkOrder* ck) //显示所有已取消订单的信息
{
    vector<Order> vec;
    vector<Order> orders=ck->getCustomer()->getOrders();
    string str="已支付的";
    if (ck->getOrderType()==3){
        for(auto od:orders){
            if(od.getState()==2){//获取对应状态的order
                vec.push_back(od);
            }
        }
        cout<<"您查看的"+str+"订单共"<<vec.size()<<"个，分别为:\n";
        int i=1;
        for(auto v:vec){
            cout<<i<<".";
            v.showOrder();
            i++;
        }
    }
    else{
        //ck->setState(new );
        ck->showInformation();
    }
}

void paidState::showOrderInformation(checkOrder* ck)  //显示所有已支付订单的信息
{
    vector<Order> vec;
    vector<Order> orders=ck->getCustomer()->getOrders();
    string str="已支付的";
    if (ck->getOrderType()==2){
        for(auto od:orders){
            if(od.getState()==1){//获取对应状态的order
                vec.push_back(od);
            }
        }
        cout<<"您查看的"+str+"订单共"<<vec.size()<<"个，分别为:\n";
        int i=1;
        for(auto v:vec){
            cout<<i<<".";
            v.showOrder();
            i++;
        }
    }
    else{
        ck->setState(new paidState);ck->showInformation();
    }
}
void unpaidState::showOrderInformation(checkOrder* ck)  //显示所有未支付订单的信息
{
    vector<Order> vec;
    vector<Order> orders=ck->getCustomer()->getOrders();
    string str="待支付的";
    if (ck->getOrderType()==1){
        for(auto od:orders){
            if(od.getState()==0){//获取对应状态的order
                vec.push_back(od);
            }
        }
        cout<<"您查看的"+str+"订单共"<<vec.size()<<"个，分别为:\n";
        int i=1;
        for(auto v:vec){
            cout<<i<<".";
            v.showOrder();
            i++;
        }
    }
    else{
        ck->setState(new paidState);ck->showInformation();
    }

}