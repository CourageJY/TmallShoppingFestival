#include "venue.h"

#include "../PersonalInformation/customer.h"
#include "../tools.h"  //需在.cpp中包含tools.h

//设置分会场中指定店铺的所有商品属性
void MainVenue::setGoods(string name, vector<string> names,
                         vector<double> prices, vector<int> months) {
    for (auto&& i : shops) {
        if (i->getName() == name) {
            i->setGoods(names, prices, months);
            return;
        }
    }
}

//返回分会场的所有商品
map<Goods, int> MainVenue::getGoods() {
    map<Goods, int> goods;
    for (auto&& i : shops) {
        map<Goods, int> temp = i->getGoods();
        goods.insert(temp.begin(), temp.end());
    }
    return goods;
}

//返回分会场指定店铺的所有商品
map<Goods, int> MainVenue::getGoods(string name) {
    for (auto&& i : shops)
        if (i->getName() == name) return i->getGoods();
    return map<Goods, int>();
}

void MainVenue::showBasicInformation(Customer* customer) {
    cout << "本次天猫购物节主会场有以下分会场：" << '\n';
    cout << "1. 服装会场" << '\n';
    cout << "2. 零食会场" << '\n';
    cout << "3. 电子会场" << '\n';
    cout << "4. 水果会场" << '\n';
}

void MainVenue::showInformation(Customer* customer,
                                ProxyPatternCustomer* proxyPatternCustomer) {
    string info(
        "请选择你想去的会场(1-4, "
        "0退出，5搜索商品，6进入购物车，7查看个人信息)：");
    while (1) {
        system("cls");  //清空屏幕
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
                proxyPatternCustomer->giveRealCustomer(customer);
                // The profile will be loaded from disk
                proxyPatternCustomer->viewBasicInformation();
                cout << "\n";
                cout << "The profile has initialized ,does not need to be "
                        "loaded from disk"
                     << endl;
                proxyPatternCustomer->viewBasicInformation();
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
void ClothingVenue::showBasicInformation(Customer* customer) {
    int count = this->shops.size();
    while (1) {
        system("cls");
        cout << "服装会场有以下店铺：" << '\n';
        int k = 1;
        for (auto&& i : this->shops) {
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
            vector<Shop*> shops = getShops();
            shops[no - 1]->showInformation(customer);
            continue;
        }
    }
}

void SnacksVenue::showBasicInformation(Customer* customer) {
    int count = this->shops.size();
    while (1) {
        system("cls");
        cout << "零食会场有以下店铺：" << '\n';
        int k = 1;
        for (auto&& i : this->shops) {
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
            vector<Shop*> shops = getShops();
            shops[no - 1]->showInformation(customer);
            continue;
        }
    }
}

void ElectronicVenue::showBasicInformation(Customer* customer) {
    int count = this->shops.size();
    while (1) {
        system("cls");
        cout << "电器会场有以下店铺：" << '\n';
        int k = 1;
        for (auto&& i : this->shops) {
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
            vector<Shop*> shops = getShops();
            shops[no - 1]->showInformation(customer);
            continue;
        }
    }
}

void FruitsVenue::showBasicInformation(Customer* customer) {
    int count = this->shops.size();
    while (1) {
        system("cls");
        cout << "水果会场有以下店铺：" << '\n';
        int k = 1;
        for (auto&& i : this->shops) {
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
        info += "，0返回，*进行店铺搜索)";
        string ss;
        while (ss == "") cin >> ss;
        int no = 0;
        if (ss == "*") {
            cout << "搜索店铺" << endl;
            // 这里还没写完
        }
        else if (isdigit(ss[0])){
            no = ss[0] - '0';
        }
        if (no == 0) {
            // MainVenue mainvenue;
            // mainvenue.showInformation(customer);
            return;
        }
        if (no <= count) {
            vector<Shop*> shops = getShops();
            shops[no - 1]->showInformation(customer);
            continue;
        }
    }
}
