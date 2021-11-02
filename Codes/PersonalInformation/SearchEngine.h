#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"../Shop/goods.h"
#include"../Venue/venue.h"
#include"../tools.h"
using namespace std;

class Customer;
class Shop;

//SearchEngine用于实现命令模式，将搜素功能封装成一个实体类
//一个SearchEngine和一个用户绑定
class SearchEngine{
public:
    SearchEngine(Customer* cu){
        customer = cu;
    };
    void searchGoods(Customer* customer);            //搜索功能
    void rollBack(Customer* customer);               //返回到上一个搜索结果

    void emptyHistory() { history.empty(); };   
    void showHistory();

private:
    Customer* customer;
    vector<string> history;         //搜索历史
    void search(string name,Customer* customer);     //实现搜索
};

//SearchAdaptor类用于适配不同的搜索方法
class SearchAdaptor{
public:
    SearchAdaptor() {
        auto& clothingshops = ClothingVenue::getInstance().getShops();
        auto& snackshops = SnacksVenue::getInstance().getShops();
        auto& electronicshops = ElectronicVenue::getInstance().getShops();
        auto& fruitshops = FruitsVenue::getInstance().getShops();
        shops.insert(shops.end(), clothingshops.begin(), clothingshops.end());
        shops.insert(shops.end(), snackshops.begin(), snackshops.end());
        shops.insert(shops.end(), electronicshops.begin(), electronicshops.end());
        shops.insert(shops.end(), fruitshops.begin(), fruitshops.end());
    };
    vector<Goods>  getAllGoods();   //将已有的搜索函数转变成所需要的函数
private:
    vector<Shop> shops;  //所有的商店
};