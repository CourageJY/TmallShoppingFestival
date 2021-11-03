#include "venue.h"
<<<<<<< Updated upstream
=======
#include "../tools.h"//需在.cpp中包含tools.h
#include "../PersonalInformation/customer.h"

void MainVenue::findShops(string name) {
>>>>>>> Stashed changes

#include "../PersonalInformation/customer.h"
#include "../tools.h"  //需在.cpp中包含tools.h

//设置分会场中指定店铺的所有商品属性
<<<<<<< Updated upstream
void MainVenue::setGoods(string name, vector<string> names,
                         vector<double> prices, vector<int> months) {
    for (auto&& i : shops) {
=======
void ClothingVenue::setGoods(string name, vector<string> names, vector<double> prices, vector<int> months) {
    // for (vector<Shop*>::iterator iter = shops.begin(); iter != shops.end(); iter++)
    //     if ((*iter)->getName() == name) {
    //         iter->setGoods(names, prices, months);
    //         return;
    //     }
    for (auto &&i: shops) {
>>>>>>> Stashed changes
        if (i->getName() == name) {
            i->setGoods(names, prices, months);
            return;
        }
    }
}

//返回分会场的所有商品
<<<<<<< Updated upstream
map<Goods, int> MainVenue::getGoods() {
    map<Goods, int> goods;
    for (auto&& i : shops) {
        map<Goods, int> temp = i->getGoods();
=======
map<Goods, int> ClothingVenue::getGoods() {
    map<Goods, int> goods;
    for (auto &&iter: shops) {
        map<Goods, int> temp = iter->getGoods();
        goods.insert(temp.begin(), temp.end());
    }
    return goods;
}

//返回分会场指定店铺的所有商品
map<Goods, int> ClothingVenue::getGoods(string name) {
    for (auto &&iter: shops)
        if (iter->getName() == name)
            return iter->getGoods();
    return map<Goods, int>();
}

//设置分会场中指定店铺的所有商品属性
void SnacksVenue::setGoods(string name, vector<string> names, vector<double> prices, vector<int> months) {
    for (auto &&iter: shops)
        if (iter->getName() == name) {
            iter->setGoods(names, prices, months);
            return;
        }
}

//返回分会场的所有商品
map<Goods, int> SnacksVenue::getGoods() {
    map<Goods, int> goods;
    for (auto &&iter: shops) {
        map<Goods, int> temp = iter->getGoods();
        goods.insert(temp.begin(), temp.end());
    }
    return goods;
}

//返回分会场指定店铺的所有商品
map<Goods, int> SnacksVenue::getGoods(string name) {
    for (auto &&iter: shops)
        if (iter->getName() == name)
            return iter->getGoods();
    return map<Goods, int>();
}

//设置分会场中指定店铺的所有商品属性
void ElectronicVenue::setGoods(string name, vector<string> names, vector<double> prices, vector<int> months) {
    for (auto &&iter: shops)
        if (iter->getName() == name) {
            iter->setGoods(names, prices, months);
            return;
        }
}

//返回分会场的所有商品
map<Goods, int> ElectronicVenue::getGoods() {
    map<Goods, int> goods;
    for (auto &&iter: shops) {
        map<Goods, int> temp = iter->getGoods();
        goods.insert(temp.begin(), temp.end());
    }
    return goods;
}

//返回分会场指定店铺的所有商品
map<Goods, int> ElectronicVenue::getGoods(string name) {
    for (auto &&iter: shops)
        if (iter->getName() == name)
            return iter->getGoods();
    return map<Goods, int>();
}

//设置分会场中指定店铺的所有商品属性
void FruitsVenue::setGoods(string name, vector<string> names, vector<double> prices, vector<int> months) {
    for (auto &&iter: shops)
        if (iter->getName() == name) {
            iter->setGoods(names, prices, months);
            return;
        }
}

//返回分会场的所有商品
map<Goods, int> FruitsVenue::getGoods() {
    map<Goods, int> goods;
    for (auto &&iter: shops) {
        map<Goods, int> temp = iter->getGoods();
>>>>>>> Stashed changes
        goods.insert(temp.begin(), temp.end());
    }
    return goods;
}

//返回分会场指定店铺的所有商品
<<<<<<< Updated upstream
map<Goods, int> MainVenue::getGoods(string name) {
    for (auto&& i : shops)
        if (i->getName() == name) return i->getGoods();
    return map<Goods, int>();
}

void MainVenue::showBasicInformation(Customer* customer) {
=======
map<Goods, int> FruitsVenue::getGoods(string name) {
    for (auto &&iter: shops)
        if (iter->getName() == name)
            return iter->getGoods();
    return map<Goods, int>();
}


void MainVenue::showBasicInformation(Customer *customer) {
>>>>>>> Stashed changes
    cout << "本次天猫购物节主会场有以下分会场：" << '\n';
    cout << "1. 服装会场" << '\n';
    cout << "2. 零食会场" << '\n';
    cout << "3. 电子会场" << '\n';
    cout << "4. 水果会场" << '\n';
}

<<<<<<< Updated upstream
void MainVenue::showInformation(Customer* customer) {
    string info(
        "请选择你想去的会场(1-4, "
        "0退出，5搜索商品，6进入购物车，7查看个人信息)：");
    while (1) {
        system("cls");  //清空屏幕
=======
void MainVenue::showInformation(Customer *customer, ProxyPatternCustomer *proxyPatternCustomer) {
    string info("请选择你想去的会场(1-4, 0退出，5搜索商品，6进入购物车，7查看个人信息)：");
    while (1) {
        system("cls");//清空屏幕
>>>>>>> Stashed changes
        cout << "本次天猫购物节主会场有以下分会场：" << '\n' << endl;
        cout << "1. 服装会场" << '\n';
        cout << "2. 零食会场" << '\n';
        cout << "3. 电子会场" << '\n';
        cout << "4. 水果会场" << '\n';
        cout << endl;
        int no = getNum(info, 7);
        switch (no) {
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
                customer->getSearchEngine()->searchGoods(customer);
                continue;
            case 6:
                customer->showShoppingCart();
                continue;
            case 7:
<<<<<<< Updated upstream
                customer->viewBasicInformation();
=======
                proxyPatternCustomer->giveRealCustomer(customer);
                // The profile will be loaded from disk
                proxyPatternCustomer->viewBasicInformation();
                cout << "\n";
                cout << "The profile has initialized ,does not need to be loaded from disk" << endl;
                proxyPatternCustomer->viewBasicInformation();
>>>>>>> Stashed changes
                continue;
        }
    }
    return;
}

void MainVenue::listfind(string name, int t) {
    vector<Shop*> matchedShops;

    for (auto&& i : shops) {
        string sname = i->getName();
        if (sname.find(name) != sname.npos) {
            matchedShops.push_back(i);
        }
    }
    if (matchedShops.size() == 0) {
        cout << "在" << this->name << "中没有搜索到该店铺，进入下一会场搜索。"
             << endl;
        system("pause");
        if (t == 4)
            cout << "在所有会场中没有搜索到该店铺。" << endl;
        else
            this->getNext()->listfind(name, t + 1);
        return;
    } else {
        int k = 1;
        for (auto&& i : matchedShops) {
            cout << '\n' << k;
            k++;
            cout << "\n-----------------\n";
            cout << i->getName();
            cout << endl;
            cout << "-----------------\n";
        }
    }
}

//显示分会场的所有商品
<<<<<<< Updated upstream
void ClothingVenue::showBasicInformation(Customer* customer) {
=======
void ClothingVenue::showBasicInformation(Customer *customer) {
>>>>>>> Stashed changes
    int count = this->shops.size();
    while (1) {
        system("cls");
        cout << "服装会场有以下店铺：" << '\n';
        int k = 1;
<<<<<<< Updated upstream
        for (auto&& i : this->shops) {
=======
        for (auto &&i: this->shops) {
>>>>>>> Stashed changes
            cout << '\n' << k;
            k++;
            cout << "\n-----------------\n";
            cout << i->getName();
            cout << endl;
            cout << "-----------------\n";
        }
        string info;
        info = "请选择你要去的商店:(1-";
        info += to_string(count);
        info += "，0返回)";
        int no = getNum(info, count);
        if (no == 0) {
            // MainVenue mainvenue;
            // mainvenue.showInformation(customer);
            return;
        }
        if (no <= count) {
<<<<<<< Updated upstream
            vector<Shop*> shops = getShops();
=======
            vector<Shop *> shops = getShops();
>>>>>>> Stashed changes
            shops[no - 1]->showInformation(customer);
            continue;
        }
    }
}

<<<<<<< Updated upstream
void SnacksVenue::showBasicInformation(Customer* customer) {
=======
void SnacksVenue::showBasicInformation(Customer *customer) {
>>>>>>> Stashed changes
    int count = this->shops.size();
    while (1) {
        system("cls");
        cout << "零食会场有以下店铺：" << '\n';
        int k = 1;
<<<<<<< Updated upstream
        for (auto&& i : this->shops) {
=======
        for (auto &&i: this->shops) {
>>>>>>> Stashed changes
            cout << '\n' << k;
            k++;
            cout << "\n-----------------\n";
            cout << i->getName();
            cout << endl;
            cout << "-----------------\n";
        }
        string info;
        info = "请选择你要去的商店:(1-";
        info += to_string(count);
        info += "，0返回)";
        int no = getNum(info, count);
        if (no == 0) {
            // MainVenue mainvenue;
            // mainvenue.showInformation(customer);
            return;
        }
        if (no <= count) {
<<<<<<< Updated upstream
            vector<Shop*> shops = getShops();
=======
            vector<Shop *> shops = getShops();
>>>>>>> Stashed changes
            shops[no - 1]->showInformation(customer);
            continue;
        }
    }
}

<<<<<<< Updated upstream
void ElectronicVenue::showBasicInformation(Customer* customer) {
=======
void ElectronicVenue::showBasicInformation(Customer *customer) {
>>>>>>> Stashed changes
    int count = this->shops.size();
    while (1) {
        system("cls");
        cout << "电器会场有以下店铺：" << '\n';
        int k = 1;
<<<<<<< Updated upstream
        for (auto&& i : this->shops) {
=======
        for (auto &&i: this->shops) {
>>>>>>> Stashed changes
            cout << '\n' << k;
            k++;
            cout << "\n-----------------\n";
            cout << i->getName();
            cout << endl;
            cout << "-----------------\n";
        }
        string info;
        info = "请选择你要去的商店:(1-";
        info += to_string(count);
        info += "，0返回)";
        int no = getNum(info, count);
        if (no == 0) {
            // MainVenue mainvenue;
            // mainvenue.showInformation(customer);
            return;
        }
        if (no <= count) {
<<<<<<< Updated upstream
            vector<Shop*> shops = getShops();
=======
            vector<Shop *> shops = getShops();
>>>>>>> Stashed changes
            shops[no - 1]->showInformation(customer);
            continue;
        }
    }
}

<<<<<<< Updated upstream
void FruitsVenue::showBasicInformation(Customer* customer) {
=======
void FruitsVenue::showBasicInformation(Customer *customer) {
>>>>>>> Stashed changes
    int count = this->shops.size();
    while (1) {
        system("cls");
        cout << "水果会场有以下店铺：" << '\n';
        int k = 1;
<<<<<<< Updated upstream
        for (auto&& i : this->shops) {
=======
        for (auto &&i: this->shops) {
>>>>>>> Stashed changes
            cout << '\n' << k;
            k++;
            cout << "\n-----------------\n";
            cout << i->getName();
            cout << endl;
            cout << "-----------------\n";
        }
        string info;
        info = "请选择你要去的商店:(1-";
        info += to_string(count);
<<<<<<< Updated upstream
        info += "，0返回，*进行店铺搜索)";
        string ss;
        while (ss == "") cin >> ss;
        if (ss == "*") {
            cout << "搜索店铺" << endl;
            // 这里还没写完
        }
=======
        info += "，0返回)";
>>>>>>> Stashed changes
        int no = getNum(info, count);
        if (no == 0) {
            // MainVenue mainvenue;
            // mainvenue.showInformation(customer);
            return;
        }
        if (no <= count) {
<<<<<<< Updated upstream
            vector<Shop*> shops = getShops();
=======
            vector<Shop *> shops = getShops();
>>>>>>> Stashed changes
            shops[no - 1]->showInformation(customer);
            continue;
        }
    }
}
