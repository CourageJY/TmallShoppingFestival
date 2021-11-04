#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "../Shop/shop.h"
#include "../Page/page.h"

using namespace std;

class ProxyPatternCustomer;
class ProxyCustomer;
class ClothingVenue;
class SnacksVenue;
class ElectronicVenue;
class FruitsVenue;
class Customer;
//定义访问者的接口
// class ParallelVenueVisitor {
//   public:
//    virtual void visit(ClothingVenue *clothingVenue);
//    virtual void visit(SnacksVenue *snackVenue);
//    virtual void visit(ElectronicVenue *electronicVenue);
//    virtual void visit(FruitsVenue *fruitsVenue);
// };

class Visitor {
    virtual void visitMain(){};

   private:
};

class MainVenue {
   public:
    MainVenue(){};
    virtual void showBasicInformation(Customer* customer);
    void showInformation(Customer* customer,
                         ProxyPatternCustomer* proxyPatternCustomer,
                         Page* page);
    void addShop(Shop* shop) { this->shops.push_back(shop); }
    vector<Shop*>& getShops() { return shops; }
    vector<MainVenue>& getVenues() { return venues; }
    map<Goods, int> getGoods();             //获取会场所有店铺的商品
    map<Goods, int> getGoods(string name);  //获取会场指定店铺的商品
    void setGoods(string name, vector<string> names, vector<double> prices,
                  vector<int> months);  //设置指定店铺的所有商品属性
    void setName(string name) { this->name = name; }

    //责任链模式
    void listfind(string name, int t);
    void setNext(MainVenue* next) { this->next = next; }
    MainVenue* getNext() { return this->next; }

   protected:
    vector<MainVenue> venues;
    vector<Shop*> shops;
    MainVenue* next;
    string name;
    //实现访问者模式，四大分会场都通过accept函数访问主会场，但执行不同的操作
    virtual void accept(Visitor* visitor){};
};

//各个分会场只会存在一个且不会被继承 设计为单例模式
class ClothingVenue : public MainVenue, Visitor {
   public:
    void showBasicInformation(Customer* customer) override;
    static ClothingVenue& getInstance() {
        static ClothingVenue instance;
        return instance;
    }
    void accept(Visitor visitor) {
        cout << "It's ClothingVenue visiting MainVenue";
    }

   private:
    ClothingVenue() {
        cout << "constructor called!" << endl;
    }  //单例模式要将构造函数私有
};

class SnacksVenue : public MainVenue, Visitor {
   public:
    void showBasicInformation(Customer* customer) override;
    static SnacksVenue& getInstance() {
        static SnacksVenue instance;
        return instance;
    }

    void accept(Visitor visitor) {
        cout << "It's SnacksVenue visiting MainVenue";
    }

   private:
    SnacksVenue() = default;
};

class ElectronicVenue : public MainVenue, Visitor {
   public:
    void showBasicInformation(Customer* customer) override;
    static ElectronicVenue& getInstance() {
        static ElectronicVenue instance;
        return instance;
    }

    void accept(Visitor visitor) {
        cout << "It's Electronic visiting MainVenue";
    }

   private:
    ElectronicVenue() = default;
};

class FruitsVenue : public MainVenue, Visitor {
   public:
    void showBasicInformation(Customer* customer) override;
    static FruitsVenue& getInstance() {
        static FruitsVenue instance;
        return instance;
    }

    void accept(Visitor visitor) {
        cout << "It's FruitsVenue visiting MainVenue";
    }

   private:
    FruitsVenue() = default;
};

//零食会场命令
class SnacksCmd {
private:
    Customer* customer;
public:
    SnacksCmd(Customer* cr) {
        customer = cr;
    }
    void Action() {
        SnacksVenue::getInstance().showBasicInformation(customer);
    }
};

//组合模式
//服装会场命令
class ClothingCmd {
private:
    Customer* customer;
public:
    ClothingCmd(Customer* cr) {
        customer = cr;
    }
    void Action() {
        ClothingVenue::getInstance().showBasicInformation(customer);
    }
};

//电子会场命令
class ElectronicCmd {
private:
    Customer* customer;
public:
    ElectronicCmd(Customer* cr) {
        customer = cr;
    }
    void Action() {
        ElectronicVenue::getInstance().showBasicInformation(customer);
    }
};

//水果会场命令
class FruitsCmd {
private:
    Customer* customer;
public:
    FruitsCmd(Customer* cr) {
        customer = cr;
    }
    void Action() {
        FruitsVenue::getInstance().showBasicInformation(customer);
    }
};

//搜索命令
class SearchCmd {
private:
    Customer* customer;
public:
    SearchCmd(Customer* cr) {
        customer = cr;
    }
    void Action();
};

//购物车命令
class CartCmd {
private:
    Customer* customer;
public:
    CartCmd(Customer* cr) {
        customer = cr;
    }
    void Action();
};

//个人信息命令
class InfoCmd {
private:
    Customer* customer;
    ProxyPatternCustomer* proxyPatternCustomer;
public:
    InfoCmd(Customer* cr, ProxyPatternCustomer* pr) {
        customer = cr;
        proxyPatternCustomer = pr;
    }
    void Action();
};

//创建实现了上述类的实体访问者
// class ParallelVenueDisplay : ParallelVenue {
//   public:
//    void visit(ClothingVenue clothingVenue){
//        cout << "你现在所在的位置是————服装会场" << endl;
//    }
//
//    void visit(SnacksVenue snackVenue){
//        cout << "你现在所在的位置是————小吃会场" << endl;
//    }
//
//    void visit(ElectronicVenue electronicVenue) {
//        cout << "你现在所在的位置是————电器会场" << endl;
//    }
//
//    void visit(FruitsVenue fruitsVenue){
//        cout << "你现在所在的位置是————蔬果会场" << endl;
//    }
//};