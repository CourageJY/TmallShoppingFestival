#pragma once
#include<iostream>
#include<windows.h>
//选择支付方式，结合简单工厂模式和策略模式
//抽象支付类
class Payment{
    public:
    virtual void payMethod()=0;
};
//微信支付类
class WechatPayment:public Payment{
    public:
    void payMethod(){
        cout<<"您已选择微信支付！";
        Sleep(1000);
    }
};
//支付宝支付类
class AliPayment:public Payment{
    public:
    void payMethod(){
        cout<<"您已选择支付宝支付！";
        Sleep(1000);
    }
};
//银联支付类
class UnionPayment:public Payment{
    public:
    void payMethod(){
        cout<<"您已选择银联支付！";
        Sleep(1000);
    }
};
//
class PaymentContext{
    private:
    Payment* py;
    public:
    PaymentContext(int method){
        switch (method)
        {
        case 1:
            py=new WechatPayment;
            break;
        case 2:
            py=new AliPayment;
            break;
        case 3:
            py=new UnionPayment;
            break;
        default:
            py=nullptr;
            break;
        }
    }
    void outPutInformation(){
        py->payMethod();
    }
};