#include "balance.h"

double ConcreteBalance::cost(){
    //测试用，后面需要与订单类对接
    return this->sum;
}

void Decorator::setComponent(Balance* blc){
    this->cpnt=blc;
}

double Decorator::cost(){
    return cpnt->cost();
}

double ConcreteDecorator::cost(){
    return discount(Decorator::cost());
}

double ConcreteDecorator::discount(double db){
    //具体装饰器类根据系统优惠券种类编写，这里假设打八折以演示
    return db*0.8;
}