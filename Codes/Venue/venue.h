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

    ~MainVenue() = default;

    vector<MainVenue> &getVenues() { return venues; }

private:
    vector<MainVenue> venues;
};

//各个分会场只会存在一个且不会被继承 设计为单例模式
class ClothingVenue : public MainVenue {
public:
    void showBasicInformation();

    vector<Shop> &getShops() { return shops; }

    static ClothingVenue getClothingVenue() { return clothingVenue; } //获得唯一对象的方法

    static void initialize();//初始化唯一对象的手段

private:
    ClothingVenue() = default;//单例模式要将构造函数私有

    static ClothingVenue clothingVenue;//静态变量定义唯一对象

    vector<Shop> shops;//分会场中应该有一些商家
};

class SnacksVenue : public MainVenue {
public:
    void showBasicInformation();

    vector<Shop> &getShops() { return shops; }

    static SnacksVenue getSnackVenue() { return snacksVenue; }

    static void initialize();

private:
    SnacksVenue() = default;

    static SnacksVenue snacksVenue;
    vector<Shop> shops;
};

class ElectronicVenue : public MainVenue {
public:
    void showBasicInformation();

    vector<Shop> &getShops() { return shops; }

    static ElectronicVenue getElectronicVenue() { return electronicVenue; }

    static void initialize();

private:
    ElectronicVenue() = default;

    static ElectronicVenue electronicVenue;
    vector<Shop> shops;
};

class FruitsVenue : public MainVenue {
public:
    void showBasicInformation();

    vector<Shop> &getShops() { return shops; }

    static FruitsVenue getFruitsVenue() { return fruitsVenue; }

    static void initialize();

private:
    FruitsVenue() = default;

    static FruitsVenue fruitsVenue;
    vector<Shop> shops;
};