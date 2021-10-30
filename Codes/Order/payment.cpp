#include"payment.h"
void WechatPayment::payMethod(){
    cout<<"您已选择微信支付！";
    Sleep(1000);
}
void AliPayment::payMethod(){
    cout<<"您已选择支付宝支付！";
    Sleep(1000);
}
void UnionPayment::payMethod(){
    cout<<"您已选择银联支付！";
    Sleep(1000);
}
PaymentContext::PaymentContext(int method){
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