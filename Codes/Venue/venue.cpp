#include "venue.h"
#include "../tools.h"//需在.cpp中包含tools.h
#include "../PersonalInformation/customer.h"
void MainVenue::findShops(string name) {

}

//设置分会场中指定店铺的所有商品属性
void ClothingVenue::setGoods(string name, vector<string> names, vector<double> prices, vector<int> months) {
    for (vector<Shop>::iterator iter = shops.begin(); iter != shops.end(); iter++)
        if (iter->getName() == name) {
            iter->setGoods(names, prices, months);
            return;
        }
}

//返回分会场的所有商品
map<Goods, int> ClothingVenue::getGoods() {
    map<Goods, int> goods;
    for (vector<Shop>::iterator iter = shops.begin(); iter != shops.end(); iter++) {
        map<Goods, int> temp = iter->getGoods();
        goods.insert(temp.begin(), temp.end());
    }
    return goods;
}

//返回分会场指定店铺的所有商品
map<Goods, int> ClothingVenue::getGoods(string name) {
    for (vector<Shop>::iterator iter = shops.begin(); iter != shops.end(); iter++)
        if (iter->getName() == name)
            return iter->getGoods();
    return map<Goods,int>();
}

//设置分会场中指定店铺的所有商品属性
void SnacksVenue::setGoods(string name, vector<string> names, vector<double> prices, vector<int> months) {
    for (vector<Shop>::iterator iter = shops.begin(); iter != shops.end(); iter++)
        if (iter->getName() == name) {
            iter->setGoods(names, prices, months);
            return;
        }
}

//返回分会场的所有商品
map<Goods, int> SnacksVenue::getGoods() {
    map<Goods, int> goods;
    for (vector<Shop>::iterator iter = shops.begin(); iter != shops.end(); iter++) {
        map<Goods, int> temp = iter->getGoods();
        goods.insert(temp.begin(), temp.end());
    }
    return goods;
}

//返回分会场指定店铺的所有商品
map<Goods, int> SnacksVenue::getGoods(string name) {
    for (vector<Shop>::iterator iter = shops.begin(); iter != shops.end(); iter++)
        if (iter->getName() == name)
            return iter->getGoods();
    return map<Goods,int>();
}

//设置分会场中指定店铺的所有商品属性
void ElectronicVenue::setGoods(string name, vector<string> names, vector<double> prices, vector<int> months) {
    for (vector<Shop>::iterator iter = shops.begin(); iter != shops.end(); iter++)
        if (iter->getName() == name) {
            iter->setGoods(names, prices, months);
            return;
        }
}

//返回分会场的所有商品
map<Goods, int> ElectronicVenue::getGoods() {
    map<Goods, int> goods;
    for (vector<Shop>::iterator iter = shops.begin(); iter != shops.end(); iter++) {
        map<Goods, int> temp = iter->getGoods();
        goods.insert(temp.begin(), temp.end());
    }
    return goods;
}

//返回分会场指定店铺的所有商品
map<Goods, int> ElectronicVenue::getGoods(string name) {
    for (vector<Shop>::iterator iter = shops.begin(); iter != shops.end(); iter++)
        if (iter->getName() == name)
            return iter->getGoods();
    return map<Goods,int>();
}

//设置分会场中指定店铺的所有商品属性
void FruitsVenue::setGoods(string name, vector<string> names, vector<double> prices, vector<int> months) {
    for (vector<Shop>::iterator iter = shops.begin(); iter != shops.end(); iter++)
        if (iter->getName() == name) {
            iter->setGoods(names, prices, months);
            return;
        }
}

//返回分会场的所有商品
map<Goods, int> FruitsVenue::getGoods() {
    map<Goods, int> goods;
    for (vector<Shop>::iterator iter = shops.begin(); iter != shops.end(); iter++) {
        map<Goods, int> temp = iter->getGoods();
        goods.insert(temp.begin(), temp.end());
    }
    return goods;
}

//返回分会场指定店铺的所有商品
map<Goods, int> FruitsVenue::getGoods(string name) {
    for (vector<Shop>::iterator iter = shops.begin(); iter != shops.end(); iter++)
        if (iter->getName() == name)
            return iter->getGoods();
    return map<Goods,int>();
}


void MainVenue::showBasicInformation(Customer* customer) {
    cout << "本次天猫购物节主会场有以下分会场：" << '\n';
    cout << "1. 服装会场" << '\n';
    cout << "2. 零食会场" << '\n';
    cout << "3. 电子会场" << '\n';
    cout << "4. 水果会场" << '\n';
}

void MainVenue::showInformation(Customer* customer) {
    string info("请选择你想去的会场(1-4, 0退出，5搜索商品，6进入购物车，7查看个人信息)：");
    while (1){
        system("cls");
        cout << "本次天猫购物节主会场有以下分会场：" << '\n';
        cout << "1. 服装会场" << '\n';
        cout << "2. 零食会场" << '\n';
        cout << "3. 电子会场" << '\n';
        cout << "4. 水果会场" << '\n';
        int no= getNum(info,7);
        switch (no){
        case 0:
            return;
        case 1:
            ClothingVenue::getInstance().showBasicInformation(customer);
            continue;
        case 2:
            SnacksVenue::getInstance().showBasicInformation(customer);
            continue;
        case 3:
            ElectronicVenue::getInstance().showBasicInformation(customer);
            continue;
        case 4:
            FruitsVenue::getInstance().showBasicInformation(customer);
            continue;
        case 5:    
            customer->getSearchEngine()->searchGoods();         
            continue;
        case 6:
            customer->getShoppingCart()->showAllGoods();
            continue;
        case 7:
            customer->viewBasicInformation();
            continue;
        }
    }
    return;
}

//显示分会场的所有商品
void ClothingVenue::showBasicInformation(Customer* customer) {
    int count=this->shops.size();
    while (1)
    {
        system("cls");
        cout << "服装会场有以下店铺及商品：" << '\n';
        for(auto && i : this->shops){
            i.showGoods();
        }
        string info;
        info="请选择你要去的商店:(1-";
        info+=to_string(count);
        info+="，0返回)";
        int no = getNum(info,count);
        if (no==0){
            MainVenue mainvenue;
            mainvenue.showInformation(customer);
            return;        
        }
        if (no<=count){
            vector<Shop> shops = getShops();
            shops[no-1].showInformation(customer);
            continue;
        }
    }
}

void SnacksVenue::showBasicInformation(Customer* customer) {
    int count=this->shops.size();
    while (1)
    {
        system("cls");
        cout << "零食会场有以下店铺及商品：" << '\n';
        for(auto && i : this->shops){
            i.showGoods();
        }
        string info;
        info="请选择你要去的商店:(1-";
        info+=to_string(count);
        info+="，0返回)";
        int no = getNum(info,count);
        if (no==0){
            MainVenue mainvenue;
            mainvenue.showInformation(customer);
            return;        
        }
        if (no<=count){
            vector<Shop> shops = getShops();
            shops[no-1].showInformation(customer);
            continue;
        }
    }
}

void ElectronicVenue::showBasicInformation(Customer* customer) {
    int count=this->shops.size();
    while (1)
    {
        system("cls");
        cout << "电器会场有以下店铺及商品：" << '\n';
        for(auto && i : this->shops){
            i.showGoods();
        }
        string info;
        info="请选择你要去的商店:(1-";
        info+=to_string(count);
        info+="，0返回)";
        int no = getNum(info,count);
        if (no==0){
            MainVenue mainvenue;
            mainvenue.showInformation(customer);
            return;        
        }
        if (no<=count){
            vector<Shop> shops = getShops();
            shops[no-1].showInformation(customer);
            continue;
        }
    }
}

void FruitsVenue::showBasicInformation(Customer* customer) {
    int count=this->shops.size();
    while (1)
    {
        system("cls");
        cout << "水果会场有以下店铺及商品：" << '\n';
        for(auto && i : this->shops){
            i.showGoods();
        }
        string info;
        info="请选择你要去的商店:(1-";
        info+=to_string(count);
        info+="，0返回)";
        int no = getNum(info,count);
        if (no==0){
            MainVenue mainvenue;
            mainvenue.showInformation(customer);
            return;        
        }
        if (no<=count){
            vector<Shop> shops = getShops();
            shops[no-1].showInformation(customer);
            continue;
        }
    }
}
