#include "venue.h"
#include "../tools.h"//需在.cpp中包含tools.h

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

void MainVenue::showInformation() {

    cout << "本次天猫购物节主会场有以下分会场：" << '\n';
    cout << "1. 服装会场" << '\n';
    cout << "2. 零食会场" << '\n';
    cout << "3. 电子会场" << '\n';
    cout << "4. 水果会场" << '\n';
    string s("");
    while (s == ""){
        string info("请选择你想去的会场(1-4, 0退出，5进入购物车，6查看个人信息)：");
        int no= getNum(info,6);
        switch (no){
        case 0:
            return;
        case 1:
            ClothingVenue::getInstance().showBasicInformation();
            return;
        case 2:
            SnacksVenue::getInstance().showBasicInformation();
            return;
        case 3:
            ElectronicVenue::getInstance().showBasicInformation();
            return;
        case 4:
            FruitsVenue::getInstance().showBasicInformation();
            return;
        case 5:
            return;
        case 6:
            return;
        }
    }
    return;
}

//显示分会场的所有商品
void ClothingVenue::showBasicInformation() {
    int count=0;
    cout << "服装会场有以下店铺及商品：" << '\n';
    for(auto && i : this->shops){
        i.showGoods();
        count++;
    }
    while (1)
    {
        cout<<"请选择你要去的商店:(1-"<<count<<",0返回)";
        int num;
        cin>> num;
    }
    


}

void SnacksVenue::showBasicInformation() {
    cout << "零食会场有以下店铺及商品：" << '\n';
    for(auto && i : this->shops)
        i.showGoods();
}

void ElectronicVenue::showBasicInformation() {
    cout << "电子会场有以下店铺及商品：" << '\n';
    for(auto && i : this->shops)
        i.showGoods();
}

void FruitsVenue::showBasicInformation() {
    cout << "水果会场有以下店铺及商品：" << '\n';
    for(auto && i : this->shops)
        i.showGoods();
}
