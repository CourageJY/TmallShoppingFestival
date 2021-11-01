#pragma once
#include <iostream>
using namespace std;

/*Decorator模式*/

class Balance{//结算基类
protected:
    Balance(double db):sum(db){
        //cout<<"构造结算基类。"<<endl;
    }

    double sum;
public:
    virtual ~Balance(){
        //cout<<"析构结算基类。"<<endl;
    }

    virtual double cost() = 0;
};

class ConcreteBalance : public Balance{//具体结算类
public:
    ConcreteBalance(double db):Balance(db){
        //cout<<"构造具体结算类。"<<endl;
    }

    ~ConcreteBalance(){
        //cout<<"析构具体结算类。"<<endl;
    }

    double cost();
};

class Decorator : public Balance{//装饰基类
protected:
    Balance* cpnt;

public:
    Decorator(Balance* blc):cpnt(blc),Balance(0.00){
        //cout<<"构造装饰器基类。"<<endl;
    }

    virtual ~Decorator(){
        delete this->cpnt;
        this->cpnt = NULL;
        //cout<<"析构装饰器基类。"<<endl;
    }

    void setComponent(Balance* blc);

    virtual double cost();
};

class ConcreteDecoratorA : public Decorator{//具体装饰类A,采用减免政策
public:
    ConcreteDecoratorA(Balance* blc,double st,double rd):Decorator(blc),stdd(st),rdct(rd){
        //cout<<"构造具体装饰器A类。"<<endl;
    }
    
    ~ConcreteDecoratorA(){
        //cout<<"析构具体装饰器A类。"<<endl;
    }

    double cost();
private:
    double stdd;
    double rdct;
    double discount(double db);//addedBehavior
};

class ConcreteDecoratorB : public Decorator{//具体装饰类B，采用打折政策
public:
    ConcreteDecoratorB(Balance* blc,double dc):Decorator(blc),dsct(dc){
        //cout<<"构造具体装饰器B类。"<<endl;
    }
    
    ~ConcreteDecoratorB(){
        //cout<<"析构具体装饰器B类。"<<endl;
    }

    double cost();
private:
    double dsct;
    double discount(double db);//addedBehavior
};