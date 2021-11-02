#pragma once

#include <iostream>
#include <vector>
#include "../Shop/shop.h"
#include <string>

//#include "../tools.h"


using namespace std;

class ClothingVenue;
class SnacksVenue;
class ElectronicVenue;
class FruitsVenue;
class Customer;
//定义访问者的接口
//class ParallelVenue {
//   public:
//    virtual void visit(ClothingVenue *clothingVenue);
//    virtual void visit(SnacksVenue *snackVenue);
//    virtual void visit(ElectronicVenue *electronicVenue);
//    virtual void visit(FruitsVenue *fruitsVenue);
//};

class MainVenue {
   public:
    MainVenue() = default;
    virtual void showBasicInformation(Customer* customer);
    static void showInformation(Customer* customer);
    void findShops(string name);
    ~MainVenue() { cout << "destructor called!" << endl; }
    vector<MainVenue>& getVenues() { return venues; }

    //实现访问者模式，四大分会场都通过accept函数访问主会场，但执行不同的操作
//   virtual void accept(ParallelVenue parallelVenue);

   private:
    vector<MainVenue> venues;
};

//各个分会场只会存在一个且不会被继承 设计为单例模式
class ClothingVenue : public MainVenue {
   public:
    void showBasicInformation(Customer* customer) override;
    void addShop(Shop shop) { this->shops.push_back(shop); }
    vector<Shop>& getShops() { return shops; }

    //获取会场所有店铺的商品
    map<Goods, int> getGoods();

    //获取会场指定店铺的商品
    map<Goods, int> getGoods(string name);

    //设置指定店铺的所有商品属性
    void setGoods(string name, vector<string> names, vector<double> prices,
                  vector<int> months);

    static ClothingVenue& getInstance() {
        static ClothingVenue instance;
        return instance;
    }

//   void accept(ParallelVenue parallelVenue) override {
//        parallelVenue.visit(this);
//    }

    //责任链模式：在分会场中搜索商店，若搜索不到则交由下一会场处理
    void setNext(SnacksVenue* next) { this->next = next; }

    SnacksVenue* getNext() { return this->next; }

   private:
    ClothingVenue() {
        cout << "constructor called!" << endl;
    }  //单例模式要将构造函数私有

    vector<Shop> shops;  //分会场中应该有一些商家
    SnacksVenue* next;
};

class SnacksVenue : public MainVenue {
   public:
    void showBasicInformation(Customer* customer) override;
    void addShop(Shop shop) { this->shops.push_back(shop); }
    vector<Shop>& getShops() { return shops; }

    //获取会场所有店铺的商品
    map<Goods, int> getGoods();

    //获取会场指定店铺的商品
    map<Goods, int> getGoods(string name);

    //设置指定店铺的所有商品属性
    void setGoods(string name, vector<string> names, vector<double> prices,
                  vector<int> months);

    static SnacksVenue& getInstance() {
        static SnacksVenue instance;
        return instance;
    }

//    void accept(ParallelVenue parallelVenue) override {
//        parallelVenue.visit(this);
//    }

    //责任链模式：在分会场中搜索商店，若搜索不到则交由下一会场处理
    void setNext(ElectronicVenue* next) { this->next = next; }

    ElectronicVenue* getNext() { return this->next; }

   private:
    SnacksVenue() = default;
    vector<Shop> shops;
    ElectronicVenue* next;
};

class ElectronicVenue : public MainVenue {
   public:
    void showBasicInformation(Customer* customer) override;
    void addShop(Shop shop) { this->shops.push_back(shop); }
    vector<Shop>& getShops() { return shops; }

    //获取会场所有店铺的商品
    map<Goods, int> getGoods();

    //获取会场指定店铺的商品
    map<Goods, int> getGoods(string name);

    //设置指定店铺的所有商品属性
    void setGoods(string name, vector<string> names, vector<double> prices,
                  vector<int> months);

    static ElectronicVenue& getInstance() {
        static ElectronicVenue instance;
        return instance;
    }

//    void accept(ParallelVenue parallelVenue) override {
//        parallelVenue.visit(this);
//    }

    //责任链模式：在分会场中搜索商店，若搜索不到则交由下一会场处理
    void setNext(FruitsVenue* next) { this->next = next; }

    FruitsVenue* getNext() { return this->next; }

   private:
    ElectronicVenue() = default;
    vector<Shop> shops;
    FruitsVenue* next;
};

class FruitsVenue : public MainVenue {
   public:
    void showBasicInformation(Customer* customer) override;
    void addShop(Shop shop) { this->shops.push_back(shop); }
    vector<Shop>& getShops() { return shops; }

    //获取会场所有店铺的商品
    map<Goods, int> getGoods();

    //获取会场指定店铺的商品
    map<Goods, int> getGoods(string name);

    //设置指定店铺的所有商品属性
    void setGoods(string name, vector<string> names, vector<double> prices,
                  vector<int> months);

    static FruitsVenue& getInstance() {
        static FruitsVenue instance;
        return instance;
    }

//    void accept(ParallelVenue parallelVenue) override {
//        parallelVenue.visit(this);
//    }

    //责任链模式：在分会场中搜索商店，若搜索不到则交由下一会场处理
    void setNext(ClothingVenue* next) { this->next = next; }

    ClothingVenue* getNext() { return this->next; }

   private:
    FruitsVenue() = default;
    vector<Shop> shops;
    ClothingVenue* next;
};

//创建实现了上述类的实体访问者
//class ParallelVenueDisplay : ParallelVenue {
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