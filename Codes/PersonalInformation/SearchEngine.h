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
    Goods *roolBack();               //返回到上一个搜索结果
    void emptyHistory() { history.empty(); };   
    void showHistory();

private:
    vector<string> history;         //搜索历史
    Goods *search(string name);     //实现搜索
};