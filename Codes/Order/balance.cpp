#include "balance.h"

double ConcreteBalance::cost(){
    //需要与订单类对接
    return this->sum;
}

void Decorator::setComponent(Balance* blc){
    this->cpnt=blc;
}

double Decorator::cost(){
    return cpnt->cost();
}

double ConcreteDecoratorA::cost(){
    return discount(Decorator::cost()); 
}

double ConcreteDecoratorA::discount(double db){
    //减免
    return ((db < stdd) ? db : db - rdct);
}

double ConcreteDecoratorB::cost(){
    return discount(Decorator::cost());
}

double ConcreteDecoratorB::discount(double db){
    //打折
    return db*dsct;
}