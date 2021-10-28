#include "venue.h"

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


void MainVenue::showBasicInformation() {

    cout << "本次天猫购物节主会场有以下分会场：" << '\n';
    cout << "1. 服装会场" << '\n';
    cout << "2. 零食会场" << '\n';
    cout << "3. 电子会场" << '\n';
    cout << "4. 水果会场" << '\n';
}

//显示分会场的所有商品
void ClothingVenue::showBasicInformation() {
    cout << "服装会场有以下店铺及商品：" << '\n';
    for (vector<Shop>::iterator iter = this->shops.begin(); iter != this->shops.end(); iter++)
        iter->showGoods();
}

void SnacksVenue::showBasicInformation() {
    cout << "零食会场有以下店铺及商品：" << '\n';
    for (vector<Shop>::iterator iter = this->shops.begin(); iter != this->shops.end(); iter++)
        iter->showGoods();
}

void ElectronicVenue::showBasicInformation() {
    cout << "电子会场有以下店铺及商品：" << '\n';
    for (vector<Shop>::iterator iter = this->shops.begin(); iter != this->shops.end(); iter++)
        iter->showGoods();
}

void FruitsVenue::showBasicInformation() {
    cout << "水果会场有以下店铺及商品：" << '\n';
    for (vector<Shop>::iterator iter = this->shops.begin(); iter != this->shops.end(); iter++)
        iter->showGoods();
}
