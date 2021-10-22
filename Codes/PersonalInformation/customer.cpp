#include"../PersonalInformation/customer.h"

void Customer::viewBasicInformation(){
    cout<<"以下是您的基本信息：\n";
    cout<<"姓名："<<name<<'\n';
    cout<<"电话号码："<<tel<<'\n';
    cout<<"居住地址："<<addr<<'\n';
    cout<<"性别"<<(gender==male?"男":"女")<<'\n';
    cout<<"您剩余的金额为："<<money<<'\n';
}

void Customer::checkOrders(){
    cout<<"请输入您想查看的订单类型（1/2/3）：1为待支付，2为已支付，3为支付失败\n";
    int x;
    cin>>x;
    vector<Order> vec;
    if(x<1||x>3){
        cout<<"抱歉，您的输入不符合要求\n";
        return;
    }
    else{
        for(auto od:orders){
            if(od.getState()==(x-1)){//获取对应状态的order
                vec.push_back(od);
            }
        }
    }
    string str;
    if(x==1)str="待支付";
    else if(x==2)str="已支付";
    else str="支付失败";
    cout<<"您查看的"+str+"订单共"<<vec.size()<<"个，分别为:\n";
    int i=1;
    for(auto v:vec){
        cout<<i<<'\n';
        v.showOrder();
        i++;
    }
}

void Customer::showCoupons(){

}

bool Customer::payOrder(){
    vector<Order*>vec;
    for(auto od:orders){
        if(od.getState()==unpaid){
            vec.push_back(&od);
        }
    }
    cout<<"当前您未支付的订单共"<<vec.size()<<"个，分别为：\n";
    int i=1;
    for(auto v:vec){
        cout<<i<<'\n';
        v->showOrder();
        i++;
    }
    cout<<"请选择您想要操作的订单id(1~"<<vec.size()<<")\n";
    int x;
    cin>>x;
    if(x<1||x>vec.size()){
        cout<<"您输入的订单不存在！\n";
        return false;
    }
    else{
        if( money>=vec[x-1]->getSum()&&vec[x-1]->pay()){
            money-=vec[x-1]->getSum();
            return true;
        }
        else{
            cout<<"支付失败！金额不足或订单处于待支付状态！\n";
            return false;
        }
    }
}