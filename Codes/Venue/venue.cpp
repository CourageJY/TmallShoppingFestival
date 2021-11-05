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

void MainVenue::showBasicInformation() {
    cout << "本次天猫购物节主会场有以下分会场：" << '\n';
    cout <<"==================================" << '\n'
         << "|           0. 退出会场           |" << '\n'
         << "|           1. 服装会场           |" << '\n'
         << "|           2. 零食会场           |" << '\n'
         << "|           3. 电子会场           |" << '\n'
         << "|           4. 水果会场           |" << '\n'
         << "================================="
         << endl;
}

void MainVenue::showInformation(Customer* customer,
                                ProxyPatternCustomer* proxyPatternCustomer,
                                Page* page) {
    string info(
        "请选择你想去的会场(1-4, "
        "0退出，5搜索商品，6进入购物车，7查看个人信息)：");
    while (1) {
        system("cls");  //清空屏幕
        cout<<"=============================="<<endl;
        cout<<"备忘录模式   类名：Page  "<<endl;
        cout<<"组合模式     类名：FruitsCmd 、SearchCmd、InfoCmd"<<endl;
        cout<<"组合实体模式 类名：MainVenue"<<endl;
        cout<<"访问者模式   类名：Visitor "<<endl;
        cout<<"=============================="<<endl;
        cout << "你当前所在的位置是:" << customer->originpage->care->getDescrip() << endl;
        cout<<"你上次进入的分会场是："<<lastVisit<<endl;
        this->showBasicInformation();
        int no = getNum(info, 7);
        switch (no)
        {
        case 1:
            lastVisit = "服装会场";
            break;
        case 2:
            lastVisit = "零食会场";
            break;
        case 3:
            lastVisit = "电器会场";
            break;
        case 4:
            lastVisit = "水果会场";
            break;
        default:
            break;
        }
        if(no) {    //非返回操作时
            page->execute(no);
        } else {
            return;
        }
        /* switch (no) {
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
        } */
    }
    return;
}

void MainVenue::showBasicInformation(Customer* customer) {
    //记录备忘录
    customer->originpage->setPage(this->name);
    accept();
    int count = this->shops.size();
    while (1) {
        system("cls");
        cout<<"=============================="<<endl;
        cout<<"责任链模式   类名：MainVenue  "<<endl;
        cout<<"单例模式     类名：ClothingVenue,SnacksVenue,ElectronicVenue,FruitsVenue"<<endl;
        cout<<"=============================="<<endl;
        cout << "你当前所在的位置是:" << customer->originpage->care->getDescrip() << endl;
        cout << this->name << "有以下店铺：" << '\n';
        int k = 1;
        cout<< "\n---------------------\n";
        for (auto&& i : this->shops) {
            cout << '\n'
                 << k
                 << i->getName() << endl
                 << '\n';
            k++;
        }
        cout<< "\n---------------------\n";
        string info;
        info = "请选择你要去的商店:(1-";
        info += to_string(count);
        info += "，0返回，*进行店铺搜索)";
        string ss;
        cout << info;
        while (ss == "") cin >> ss;
        int no = 0;
        if (ss == "*") {
            cout << "搜索店铺" << endl;
            cout << "请输入需要搜索的店铺的名字：";
            string s;
            while (s == "") cin >> s;
            auto rs = this->listfind(s, 1);
            if (!rs.empty()) {
                k = 1;
                for (auto&& i : rs) {
                    cout << '\n'
                         << k << "\n-----------------\n"
                         << i->getName() << endl
                         << "-----------------\n";
                    k++;
                }
                info = "请选择你要去的商店:(1-";
                info += to_string(rs.size());
                info += "，0返回)";
                while (1) {
                    int no = getNum(info, rs.size());
                    if (no == 0) break;
                    if (no <= rs.size()) {
                        rs[no - 1]->showInformation(customer);
                        break;
                    }
                    if (no > rs.size())
                        cout << "检测到无效输入，请重试" << endl;
                }
                continue;
            }
            continue;
        } else if (isdigit(ss[0])) {
            no = ss[0] - '0';
        }
        if (no == 0) {
            // MainVenue mainvenue;
            // mainvenue.showInformation(customer);
            //弹出一条备忘录
            customer->originpage->care->popMeme();
            return;
        }
        if (no <= count) {
            vector<Shop*> shops = getShops();
            shops[no - 1]->showInformation(customer);
            continue;
        }
    }
}

vector<Shop*> MainVenue::listfind(string name, int t) {
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
        if (t == 4) {
            cout << "在所有会场中没有搜索到该店铺，即将返回到原来的分会场。"
                 << endl;
            system("pause");
            return {};
        } else {
            cout << "在" << this->getNext()->name << "中搜索店铺。" << endl;
            return this->getNext()->listfind(name, t + 1);
        }
    }
    return matchedShops;
}

void SearchCmd::Action() { customer->getSearchEngine()->searchGoods(customer); }

void CartCmd::Action() { customer->showShoppingCart(); }
void InfoCmd::Action() {
    proxyPatternCustomer->giveRealCustomer(customer);
    // The profile will be loaded from disk
    proxyPatternCustomer->viewBasicInformation();
    cout << "\n";
    cout << "The profile has initialized ,does not need to be "
            "loaded from disk"
         << endl;
    proxyPatternCustomer->viewBasicInformation();
}