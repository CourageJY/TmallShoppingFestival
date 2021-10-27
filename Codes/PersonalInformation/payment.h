#pragma once
#include<iostream>
#include<windows.h>
//选择支付方式，结合简单工厂模式和策略模式
//抽象支付类
class payment{
    public:
    virtual void paymethod()=0;
};
//微信支付类
class Wechatpayment:public payment{
    public:
    void paymethod(){
        cout<<"您已选择微信支付！";
        Sleep(1000);
    }
};
//支付宝支付类
class Alipaypayment:public payment{
    public:
    void paymethod(){
        cout<<"您已选择支付宝支付！";
        Sleep(1000);
    }
};
//银联支付类
class Unionpayment:public payment{
    public:
    void paymethod(){
        cout<<"您已选择银联支付！";
        Sleep(1000);
    }
};
//
class paymentContext{
    private:
    payment* py;
    public:
    paymentContext(int method){
        switch (method)
        {
        case 1:
            py=new Wechatpayment;
            break;
        case 2:
            py=new Alipaypayment;
        case 3:
            py=new Unionpayment;
        default:
            break;
        }
    }
    void outputinformation(){
        py->paymethod();
    }
};