#pragma once
#include<string>
using namespace std;

class Order{
public:
    Order():name("It's a new order!"),price(0){}
    double getPrice(){return price;}
    string getName(){return name;}

private:
    string name;
    double price;
};