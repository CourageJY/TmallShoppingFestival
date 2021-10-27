#pragma once

#include<vector>
#include<iostream>
#include "../Shop/shop.h"

using namespace std;

class MainVenue {
public:
    MainVenue() = default;

    void showBasicInformation();

    void findShops(string name);

    ~MainVenue() {
        cout << "destructor called!" << endl;
    }

    vector<MainVenue> &getVenues() { return venues; }

private:
    vector<MainVenue> venues;
};

//各个分会场只会存在一个且不会被继承 设计为单例模式
class ClothingVenue : public MainVenue {
public:
    void showBasicInformation();

    vector<Shop> &getShops() { return shops; }

    void addShop(Shop shop) { this->shops.push_back(shop); }

    //获取会场所有店铺的商品
    map<Goods, int> getGoods();

    //获取会场指定店铺的商品
    map<Goods, int> getGoods(string name);

    //设置指定店铺的所有商品属性
    void setGoods(string name, vector<string> names, vector<double> prices, vector<time_t> times);

    static ClothingVenue& getInstance() {
        static ClothingVenue instance;
        return instance;

    }

private:
    ClothingVenue() {
        cout << "constructor called!" << endl;
    }//单例模式要将构造函数私有

    vector<Shop> shops;//分会场中应该有一些商家
};

class SnacksVenue : public MainVenue {
public:
    void showBasicInformation();

    vector<Shop>& getShops() { return shops; }

    void addShop(Shop shop) { this->shops.push_back(shop); }

    //获取会场所有店铺的商品
    map<Goods, int> getGoods();

    //获取会场指定店铺的商品
    map<Goods, int> getGoods(string name);

    //设置指定店铺的所有商品属性
    void setGoods(string name, vector<string> names, vector<double> prices, vector<time_t> times);

    static SnacksVenue& getInstance() {
        static SnacksVenue instance;
        return instance;

    }

private:
    SnacksVenue() = default;

    vector<Shop> shops;
};

class ElectronicVenue : public MainVenue {
public:
    void showBasicInformation();

    vector<Shop>& getShops() { return shops; }

    void addShop(Shop shop) { this->shops.push_back(shop); }

    //获取会场所有店铺的商品
    map<Goods, int> getGoods();

    //获取会场指定店铺的商品
    map<Goods, int> getGoods(string name);

    //设置指定店铺的所有商品属性
    void setGoods(string name, vector<string> names, vector<double> prices, vector<time_t> times);

    static ElectronicVenue& getInstance() {
        static ElectronicVenue instance;
        return instance;

    }


private:
    ElectronicVenue() = default;

    vector<Shop> shops;
};

class FruitsVenue : public MainVenue {
public:
    void showBasicInformation();

    vector<Shop>& getShops() { return shops; }

    void addShop(Shop shop) { this->shops.push_back(shop); }

    //获取会场所有店铺的商品
    map<Goods, int> getGoods();

    //获取会场指定店铺的商品
    map<Goods, int> getGoods(string name);

    //设置指定店铺的所有商品属性
    void setGoods(string name, vector<string> names, vector<double> prices, vector<time_t> times);

    static FruitsVenue& getInstance() {
        static FruitsVenue instance;
        return instance;

    }

private:
    FruitsVenue() = default;

    vector<Shop> shops;
};