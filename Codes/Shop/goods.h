#pragma once
#include<ctime>
#include"shop.h"
#include"Comment.h"
#include<vector>
class Goods{
private:
    string name;
    double price;
    time_t date;
    Shop* shop;
    vector<Comment> comment;
};