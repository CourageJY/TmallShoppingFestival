#pragma once
#include<iostream>
#include<windows.h>
using namespace std;
//选择支付方式，结合简单工厂模式和策略模式
//抽象支付类
class Payment{
    public:
    virtual void payMethod()=0;
};
//微信支付类
class WechatPayment:public Payment{
    public:
    void payMethod();
};
//支付宝支付类
class AliPayment:public Payment{
    public:
    void payMethod();
};
//银联支付类
class UnionPayment:public Payment{
    public:
    void payMethod();
};
//
class PaymentContext{
    private:
    Payment* py;
    public:
    PaymentContext(int method);
    void outPutInformation(){
        py->payMethod();
    }
};