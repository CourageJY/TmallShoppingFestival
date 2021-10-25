#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"../Shop/goods.h"
using namespace std;

class SearchEngine{
public:
    SearchEngine(){};
    Goods* searchGoods(string name);
    Goods *roolBack();
    void emptyHistory() { history.empty(); };
    void showHistory();

private:
    vector<string> history;
};