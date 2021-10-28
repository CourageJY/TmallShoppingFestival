#pragma once

#include<vector>
#include<iostream>
#include "../Shop/shop.h"

using namespace std;

class ClothingVenue;

class SnacksVenue;

class ElectronicVenue;

class FruitsVenue;

//定义访问者的接口
class ParallelVenue {
public:
    virtual void visit(ClothingVenue clothingVenue);

    virtual void visit(SnacksVenue snackVenue);

    virtual void visit(ElectronicVenue electronicVenue);

    virtual void visit(FruitsVenue fruitsVenue);
};


class MainVenue {
public:
    MainVenue() = default;

    virtual void showBasicInformation();

    static void showInformation();

    void findShops(string name);

    ~MainVenue() {
        cout << "destructor called!" << endl;
    }

    vector<MainVenue> &getVenues() { return venues; }

    //实现访问者模式，四大分会场都通过accept函数访问主会场，但执行不同的操作
    virtual void accept(ParallelVenue parallelVenue) = 0;

private:
    vector<MainVenue> venues;
};

//各个分会场只会存在一个且不会被继承 设计为单例模式
class ClothingVenue : public MainVenue {
public:
    void showBasicInformation() override;

    vector<Shop> &getShops() { return shops; }

    void addShop(const Shop& shop) { this->shops.push_back(shop); }

    //获取会场所有店铺的商品
    map<Goods, int> getGoods();

    //获取会场指定店铺的商品
    map<Goods, int> getGoods(string name);

    //设置指定店铺的所有商品属性
    void setGoods(string name, vector<string> names, vector<double> prices, vector<time_t> times);

    static ClothingVenue &getInstance() {
        static ClothingVenue instance;
        return instance;
    }

    void accept(ParallelVenue parallelVenue) override {
        parallelVenue.visit(*this);
    }

private:
    ClothingVenue() {
        cout << "constructor called!" << endl;
    }//单例模式要将构造函数私有

    vector<Shop> shops;//分会场中应该有一些商家
};

class SnacksVenue : public MainVenue {
public:
    void showBasicInformation() override;

    vector<Shop> &getShops() { return shops; }

    void addShop(const Shop& shop) { this->shops.push_back(shop); }

    //获取会场所有店铺的商品
    map<Goods, int> getGoods();

    //获取会场指定店铺的商品
    map<Goods, int> getGoods(string name);

    //设置指定店铺的所有商品属性
    void setGoods(string name, vector<string> names, vector<double> prices, vector<time_t> times);

    static SnacksVenue &getInstance() {
        static SnacksVenue instance;
        return instance;

    }

    void accept(ParallelVenue parallelVenue) override {
        parallelVenue.visit(*this);
    }

private:
    SnacksVenue() = default;

    vector<Shop> shops;
};

class ElectronicVenue : public MainVenue {
public:
    void showBasicInformation() override;

    vector<Shop> &getShops() { return shops; }

    void addShop(const Shop& shop) { this->shops.push_back(shop); }

    //获取会场所有店铺的商品
    map<Goods, int> getGoods();

    //获取会场指定店铺的商品
    map<Goods, int> getGoods(string name);

    //设置指定店铺的所有商品属性
    void setGoods(string name, vector<string> names, vector<double> prices, vector<time_t> times);

    static ElectronicVenue &getInstance() {
        static ElectronicVenue instance;
        return instance;

    }

    void accept(ParallelVenue parallelVenue) override {
        parallelVenue.visit(*this);
    }

private:
    ElectronicVenue() = default;

    vector<Shop> shops;
};

class FruitsVenue : public MainVenue {
public:
    void showBasicInformation() override;

    vector<Shop> &getShops() { return shops; }

    void addShop(const Shop& shop) { this->shops.push_back(shop); }

    //获取会场所有店铺的商品
    map<Goods, int> getGoods();

    //获取会场指定店铺的商品
    map<Goods, int> getGoods(string name);

    //设置指定店铺的所有商品属性
    void setGoods(string name, vector<string> names, vector<double> prices, vector<time_t> times);

    static FruitsVenue &getInstance() {
        static FruitsVenue instance;
        return instance;

    }

    void accept(ParallelVenue parallelVenue) override {
        parallelVenue.visit(*this);
    }

private:
    FruitsVenue() = default;

    vector<Shop> shops;
};


//创建实现了上述类的实体访问者
class ParallelVenueDisplay : ParallelVenue {
public:
    void visit(ClothingVenue clothingVenue) override {
        cout << "你现在所在的位置是————服装会场" << endl;
    }

    void visit(SnacksVenue snackVenue) override {
        cout << "你现在所在的位置是————小吃会场" << endl;
    }

    void visit(ElectronicVenue electronicVenue) override {
        cout << "你现在所在的位置是————电器会场" << endl;
    }

    void visit(FruitsVenue fruitsVenue) override {
        cout << "你现在所在的位置是————蔬果会场" << endl;
    }
};