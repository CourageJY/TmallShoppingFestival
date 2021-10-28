#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"../Shop/goods.h"
#include"../Venue/venue.h"
using namespace std;

//SearchEngine用于实现命令模式，将搜素功能封装成一个实体类
//一个SearchEngine和一个用户绑定
class SearchEngine{
public:
    SearchEngine(){};
    Goods* searchGoods();            //搜索功能
    Goods *rollBack();               //返回到上一个搜索结果
    void emptyHistory() { history.empty(); };   
    void showHistory();

private:
    vector<string> history;         //搜索历史
    Goods *search(string name);     //实现搜索
};

//SearchAdaptor类用于适配不同的搜索方法
class SearchAdaptor{
public:
    SearchAdaptor(){
        vector<Shop> clothingshops = ClothingVenue::getInstance().getShops();
        vector<Shop> snackshops = SnacksVenue::getInstance().getShops();
        vector<Shop> electronicshops = ElectronicVenue::getInstance().getShops();
        vector<Shop> fruitshops = FruitsVenue::getInstance().getShops();
        shops.insert(shops.end(), clothingshops.begin(), clothingshops.end());
        shops.insert(shops.end(), snackshops.begin(), electronicshops.end());
        shops.insert(shops.end(), electronicshops.begin(), electronicshops.end());
        shops.insert(shops.end(), fruitshops.begin(), fruitshops.end());
    };
    vector<Goods>  getAllGoods();   //将已有的搜索函数转变成所需要的函数
private:
    vector<Shop> shops;  //所有的商店
};