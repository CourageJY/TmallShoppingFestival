#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "../Page/page.h"
#include "../Shop/shop.h"

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
    public:
        string getVisitorName(){return name;};
        void setVisitorName(string s){name = s;};
    private:
        string name;
};

class MainVenue: public Visitor {
   public:
    MainVenue(){lastVisit = "无";};
    void showInformation(Customer* customer,
                         ProxyPatternCustomer* proxyPatternCustomer,
                         Page* page);
    void showBasicInformation();

    virtual void showBasicInformation(Customer* customer);
    virtual void addShop(Shop* shop) { this->shops.push_back(shop); }
    virtual void setGoods(string name, vector<string> names,
                          vector<double> prices,
                          vector<int> months);  //设置指定店铺的所有商品属性
    virtual void setName(string name) { this->name = name; }
    virtual vector<Shop*>& getShops() { return shops; }
    virtual vector<MainVenue>& getVenues() { return venues; }
    virtual map<Goods, int> getGoods();  //获取会场所有店铺的商品
    virtual map<Goods, int> getGoods(string name);  //获取会场指定店铺的商品

    //责任链模式
    virtual vector<Shop*> listfind(string name, int t);
    virtual void setNext(MainVenue* next) { this->next = next; }
    virtual MainVenue* getNext() { return this->next; }

   protected:
    vector<MainVenue> venues;
    vector<Shop*> shops;
    MainVenue* next;
    string name;
    string lastVisit;
    //实现访问者模式，四大分会场都通过accept函数访问主会场，但执行不同的操作
    virtual void accept(){};
};

//各个分会场只会存在一个且不会被继承 设计为单例模式
class ClothingVenue : public MainVenue{
   public:
    static ClothingVenue& getInstance() {
        static ClothingVenue instance;
        return instance;
    }
    void accept() {
        lastVisit = getVisitorName();
    }

   private:
    ClothingVenue() {
        cout << "constructor called!" << endl;
        setVisitorName("服装会场");
    }  //单例模式要将构造函数私有
};

class SnacksVenue : public MainVenue{
   public:
    static SnacksVenue& getInstance() {
        static SnacksVenue instance;
        return instance;
    }
    void accept() {
        lastVisit = getVisitorName();
    }

   private:
    SnacksVenue(){setVisitorName("零食会场");};
};

class ElectronicVenue : public MainVenue {
   public:
    static ElectronicVenue& getInstance() {
        static ElectronicVenue instance;
        return instance;
    }
    void accept() {
        lastVisit = getVisitorName();
    }

   private:
    ElectronicVenue(){setVisitorName("电器会场");};
};

class FruitsVenue : public MainVenue {
   public:
    static FruitsVenue& getInstance() {
        static FruitsVenue instance;
        return instance;
    }
    void accept() {
        lastVisit = getVisitorName();
    }

   private:
    FruitsVenue(){setVisitorName("水果会场");};
};

//零食会场命令
class SnacksCmd {
   private:
    Customer* customer;

   public:
    SnacksCmd(Customer* cr) { customer = cr; }
    void Action() { SnacksVenue::getInstance().showBasicInformation(customer); }
};

//组合模式
//服装会场命令
class ClothingCmd {
   private:
    Customer* customer;

   public:
    ClothingCmd(Customer* cr) { customer = cr; }
    void Action() {
        ClothingVenue::getInstance().showBasicInformation(customer);
    }
};

//电子会场命令
class ElectronicCmd {
   private:
    Customer* customer;

   public:
    ElectronicCmd(Customer* cr) { customer = cr; }
    void Action() {
        ElectronicVenue::getInstance().showBasicInformation(customer);
    }
};

//水果会场命令
class FruitsCmd {
   private:
    Customer* customer;

   public:
    FruitsCmd(Customer* cr) { customer = cr; }
    void Action() { FruitsVenue::getInstance().showBasicInformation(customer); }
};

//搜索命令
class SearchCmd {
   private:
    Customer* customer;

   public:
    SearchCmd(Customer* cr) { customer = cr; }
    void Action();
};

//购物车命令
class CartCmd {
   private:
    Customer* customer;

   public:
    CartCmd(Customer* cr) { customer = cr; }
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
