#pragma once
#include<string>
#include"../PersonalInformation/customer.h"

class Order;//预声明
class AfterSale{
public:
    void repair();
    void exchange();

private:
    Goods* goods;
};