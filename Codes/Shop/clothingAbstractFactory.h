//实现抽象工厂模式的主要头文件（coded by jy）
#pragma once
#include"goods.h"
using namespace std;

/*
**以下是产品族类的设计
*/

//该类设计只是让逻辑更加完整，未添加额外属性
class ClothingGoods:public Goods{
public:
    ClothingGoods(string na, double pr, Shop* sh):Goods(na,pr,sh){}

    void showInfo();

};

//外套
class Coats:public ClothingGoods{
public:
    Coats(string na, double pr, Shop* sh):ClothingGoods(na,pr,sh){}

    virtual void showInfo(){};

};

//裤子
class Pants:public ClothingGoods{
public:
    Pants(string na, double pr, Shop* sh):ClothingGoods(na,pr,sh){}

    virtual void showInfo(){};

};

//安踏工厂的裤子
class AntaPants:public Pants{
public:
    AntaPants(string na, double pr, Shop* sh):Pants(na,pr,sh){}

    virtual void showInfo(){
        cout<<"这是一条安踏的裤子\n";
    };

};

//阿迪达斯工厂的裤子
class AdidasPants:public Pants{
public:
    AdidasPants(string na, double pr, Shop* sh):Pants(na,pr,sh){
    };

    virtual void showInfo(){
        cout<<"这是一条阿迪达斯的裤子\n";
    };

};

//安踏工厂的外套
class AntaCoats:public Coats{
public:
    AntaCoats(string na, double pr, Shop* sh):Coats(na,pr,sh){}

    void showInfo(){
        cout<<"这是一件安踏的外套\n";
    };

};

//阿迪达斯工厂的外套
class AdidasCoats:public Coats{
public:
    AdidasCoats(string na, double pr, Shop* sh):Coats(na,pr,sh){}

    void showInfo(){
        cout<<"这是一件阿迪达斯的外套\n";
    };

};

/*
**以下是工厂类的设计
*/

//服装产品生产的抽象工厂
class ClothingGoodsFactory{
public:
    virtual Pants getPants(string na, double pr, Shop* sh)=0;//生产裤子

    virtual Coats getCoats(string na, double pr, Shop* sh)=0;//生产外套

};

//安踏产品的生产工厂
class AntaFactory:public ClothingGoodsFactory{
public:
    virtual Pants getPants(string na, double pr, Shop* sh){
        return *(new AntaPants(na,pr,sh));//测试
    }

    virtual Coats getCoats(string na, double pr, Shop* sh){
        return *(new AntaCoats(na,pr,sh));
    }

};

//阿迪达斯产品的生产工厂
class AdidasFactory:public ClothingGoodsFactory{
public:
    virtual Pants getPants(string na, double pr, Shop* sh){
        // AdidasPants ap(na,pr,sh);
        // return ap;
        return *(new AdidasPants(na,pr,sh));//测试
    }

    virtual Coats getCoats(string na, double pr, Shop* sh){
        return *(new AdidasCoats(na,pr,sh));
    }

};
