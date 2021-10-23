#pragma once
#include"customer.h"
class Goods;

class Comment{
private:
    Goods* goods;
    string content;
    Customer* customer;
};