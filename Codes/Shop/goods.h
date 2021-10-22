#pragma once
#include<string>
using namespace std;

class Goods{//商品
public:
    string getName(){return name;}
    double getPrice(){return price;}
private:
    string name;
    double price;
};