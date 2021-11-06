#include "shop.h"
#include "../Filter/filter.h"
#include "../PersonalInformation/Comment.h"
#include "../PersonalInformation/customer.h"
#include "../tools.h"
#include "../Shop/coupon.h"
using namespace std;

//添加商品
void Shop::addGoods(Goods goods, int stock) {
    this->goods.insert(pair<Goods, int>(goods, stock));
}

int getNum_shop(string info, int range) {
    string s;
    while (1) {
        cout << info;
        cin >> s;
        if (s.length() != 1) continue;
        int no = s[0] - '0';
        if (no >= 0 && no <= range) return no;
    }
    return -1;
}

//店铺统一设置所有商品的属性
void Shop::setGoods(vector<string> names, vector<double> prices,
                    vector<int> months) {
    int number = this->goods.size();
    if (names.size() != number || prices.size() != number ||
        (months.size() != 0 && months.size() != number))
        return;

    auto iter = this->goods.begin();
    for (int i = 0; i < number; i++) {
        Goods tempGoods = iter->first;
        int tempStock = iter->second;
        iter++;
        //由于map无法修改key值，所以移除旧的key-value，添加新的key-value
        this->goods.erase(tempGoods);
        tempGoods.setGoods(names[i], prices[i],
                           months.size() == 0 ? 0 : months[i]);
        this->goods.insert(pair<Goods, int>(tempGoods, tempStock));
    }
}

void Shop::showGoods(Customer* customer,AbstractCustomer* absc) {
    system("cls");  //清空屏幕
    //记录备忘录
    customer->originpage->setPage("商品列表");
    cout << "你当前所在的位置是:" << customer->originpage->care->getDescrip() << endl;
    cout << this->name << "有以下商品：" << endl << endl;
    if (this->goods.size() == 0) {
        cout << "" << endl;
        //弹出一条备忘录
        customer->originpage->care->popMeme();
        return;
    }
    int k = 0;
    cout << "-------------------------------------------" << endl << endl;
    for (auto&& i : this->goods) {
        k++;
        cout << k << "：" << i.first.getName() << endl
             << "价格: " << i.first.getPrice() << " 元" << endl
             << "生产时间: " << i.first.getOutDate() << endl
             << "店内库存: " << i.second << endl
             << endl;
    }
    cout << "-------------------------------------------" << endl << endl;

    if(absc->isNull()){
        //为游客
        cout<<"\n您目前为游客状态，只能浏览商品哟！\n";
        //system("pause");
        return;
    }
    int no, count;
    while (1) {
        cout << "请选择你要添加的商品序号(1~" << k << ",0返回)及其数量:";
        cin >> no;
        if (no == 0) {
            //弹出一条备忘录
            customer->originpage->care->popMeme();
            return;
        }
        cin >> count;
        if (no < 0 || no > k) {
            cout << "序号错误!" << endl;
            continue;
        }
        if (count <= 0) {
            cout << "数量错误!" << endl;
            continue;
        }
        int iter = 0;
        bool sus = true;
        for (auto&& i : this->goods) {
            if (++iter == no) {
                if (count > i.second) {
                    cout << "\n抱歉！添加的商品数量超过了库存需求\n";
                    sus = false;
                    break;
                }
                const Goods good = i.first;
                customer->getShoppingCart()->addGoods(good, count);
                Sleep(1000);
                cout << "\n-------------\n";
                cout << "添加成功" << endl;
                // system("pause");
                break;
            }
        }
        if (sus) break;
    }
}

//显示店铺评论
void Shop::showComments(Customer* customer,AbstractCustomer* absc) {
    system("cls");
    //记录备忘录
    customer->originpage->setPage("店铺评价");
    cout<<"=============================="<<endl;
    cout<<"迭代器模式   类名：Iterator  "<<endl;
    cout<<"=============================="<<endl;
    cout << "你当前所在的位置是:" << customer->originpage->care->getDescrip() << endl;
    cout << "本店评价：" << endl;
    commentsListIterator* cmli = ca->getIterator();
    if (cmli->first()) {
        cout << "-" << cmli->first()->getCustomer()->getName() << ":\t"
             << ctime(cmli->first()->getTime()) << endl
             << cmli->first()->getContent() << endl
             << endl;

        while (cmli->hasNext()) {
            auto temp = cmli->next();
            cout << "-" << temp->getCustomer()->getName() << ":\t"
                 << ctime(temp->getTime()) << endl
                 << temp->getContent() << endl
                 << endl;
        }
    }
    cout << "-------------------------------------------" << endl << endl;
    //弹出一条备忘录
    customer->originpage->care->popMeme();
}

//显示店铺优惠券，内容待定
void Shop::showCoupons(Customer* customer,AbstractCustomer* absc) {
    system("cls");
    //记录备忘录
    customer->originpage->setPage("优惠券");
    cout << "你当前所在的位置是:" << customer->originpage->care->getDescrip() << endl;
    cout << this->name << "的优惠券信息如下: " << endl << endl;
    if (this->coupons.size() == 0) {
        cout << "抱歉！本店的优惠券已被领取完毕" << endl;
        return;
    }
    //显示所有优惠券信息
    int k = 1;
    for (auto&& i : this->coupons) {
        cout << k << endl
             << "-------------------------------------------" << endl;
        i->showInformation();
        k++;
    }
    if(absc->isNull()){
        cout<<"\n您目前为游客状态，只能查看优惠券哟！";
        system("pause");
        return;
    }

    string info;
    info = "请选择您想要领取的优惠券(1~";
    info += to_string(k - 1);
    info += ",0退出):";
    int od = getNum(info, k - 1);

    if (od == 0) {
        //弹出一条备忘录
        customer->originpage->care->popMeme();
        return;
    }

    //在顾客容器中加上该优惠券
    customer->getCoupons().push_back(coupons[od - 1]->clone());


    // //从商店中减去该优惠券
    // coupons.erase(coupons.begin() +
    //               (od - 1));  //?这里是指针类型，以配合多态实现

    Sleep(1000);

    cout << "恭喜！ 你已经成功领取了该优惠券\n"
         << "-------------------------------------------" << endl
         << endl;
    // system("pause");
    //弹出一条备忘录
    customer->originpage->care->popMeme();
}

void Shop::showFilterGoods(Customer* customer,AbstractCustomer* absc) {
    system("cls");
    //记录备忘录
    customer->originpage->setPage("筛选商品");
    cout<<"=============================="<<endl;
    cout<<"过滤器模式   类名：Filter  "<<endl;
    cout<<"=============================="<<endl;
    cout << "你当前所在的位置是:" << customer->originpage->care->getDescrip() << endl;
    double low, up;
    cout << "本店仅支持从商品价格上筛选，输出所有位于价格区间内的商品。" << endl
         << endl;
    cout << "请输入筛选最低价：";
    cin >> low;
    cout << "请输入筛选最高价：";
    cin >> up;
    PriceFilter filter(low, up);
    map<Goods, int> filterGoods = filter.filterGoods(this->goods);

    cout << endl
         << "价格位于 [" << low << "," << up << "] 的有以下商品：" << endl
         << endl;
    if (this->goods.size() == 0) {
        cout << "" << endl;
        //弹出一条备忘录
        customer->originpage->care->popMeme();
        return;
    }
    int k = 0;
    for (auto&& i : filterGoods) {
        k++;
        cout << k << "：" << i.first.getName() << endl
             << "价格: " << i.first.getPrice() << " 元" << endl
             << "过期时间: " << i.first.getOutDate() << endl
             << "店内库存: " << i.second << endl
             << endl;
    }
    cout << "-------------------------------------------" << endl << endl;

    if(absc->isNull()){
        cout<<"\n您目前为游客状态，只能查看商品哟！";
        system("pause");
        return;
    }
    int no, count;
    while (1) {
        cout << "请选择你要添加的商品序号(1~" << k << ",0返回)及其数量:";
        cin >> no;
        if (no == 0) {
            //弹出一条备忘录
            customer->originpage->care->popMeme();
            return;
        }
        cin >> count;
        if (no < 0 || no > k) {
            cout << "序号错误!" << endl;
            continue;
        }
        if (count <= 0) {
            cout << "数量错误!" << endl;
            continue;
        }
        int iter = 0;
        bool sus = true;
        for (auto&& i : filterGoods) {
            if (++iter == no) {
                if (count > i.second) {
                    cout << "\n抱歉！添加的商品数量超过了库存需求\n";
                    sus = false;
                    break;
                }
                const Goods good = i.first;
                customer->getShoppingCart()->addGoods(good, count);
                Sleep(1000);
                cout << "\n-------------\n"
                     << "添加成功" << endl;
                // system("pause");
                break;
            }
        }
        if (sus) break;
    }
}

void Shop::showGoods_pullOff(Customer* customer){
    system("cls");  //清空屏幕
    //记录备忘录
    customer->originpage->setPage("下架商品");
    cout<<"=============================="<<endl;
    cout<<"过滤器模式   类名：Filter    "<<endl;
    cout<<"原型模式     类型：Coupon    "<<endl;
    cout<<"=============================="<<endl;
    cout << "你当前所在的位置是:" << customer->originpage->care->getDescrip() << endl;
    cout << this->name << "有以下商品：" << endl << endl;
    if (this->goods.size() == 0) {
        cout << "" << endl;
        //弹出一条备忘录
        customer->originpage->care->popMeme();
        return;
    }
    int k = 0;
    for (auto&& i : this->goods) {
        k++;
        cout << k << "：" << i.first.getName() << endl
             << "价格: " << i.first.getPrice() << " 元" << endl
             << "生产时间: " << i.first.getOutDate() << endl
             << "店内库存: " << i.second << endl
             << endl;
    }
    cout << "-------------------------------------------" << endl << endl;

    int no;
    while (1) {
        cout << "请选择要下架的商品序号(1~" << k << ",0返回):";
        cin >> no;
        if (no == 0) {
            //弹出一条备忘录
            customer->originpage->care->popMeme();
            return;
        }
        if (no < 0 || no > k) {
            cout << "序号错误!" << endl;
            continue;
        }
        int iter = 0;
        bool sus = true;
        for (auto&& i : this->goods) {
            if (++iter == no) {
                const Goods good = i.first;
                this->pullOffGoods(good);
                Sleep(1000);
                cout << "\n-------------\n";
                cout << "商品下架成功" << endl;
                // system("pause");
                break;
            }
        }
        if (sus) break;
    }
}

//展示店铺信息，与店铺交互
void Shop::showInformation(Customer* customer,AbstractCustomer* absc) {
    //记录备忘录
    customer->originpage->setPage(this->name);
    string info;
    info += "-------------------------------------------\n";
    info += "欢迎光临";
    info += this->name;
    info += "，\n\n";
    info +=
        "1、浏览商品\n2、查看店铺评价\n3、对店铺进行评价\n4、查看店铺优惠券\n"
        "5、筛选商品\n6、下架商品\n0、退出商店\n请选择您的操作：";
    int order;
    while (true) {
        system("cls");
        cout << "你当前所在的位置是:" << customer->originpage->care->getDescrip() << endl;
        order = getNum_shop(info, 6);
        if(absc->isNull()&&order==3){
            //为游客登录
            cout<<"\n抱歉，您为游客，无法对店铺做出评价\n";
            system("pause");
            continue;
        }
        switch (order) {
            case 1:
                this->showGoods(customer,absc);
                system("pause");
                continue;
            case 2:
                this->showComments(customer,absc);
                system("pause");
                continue;
            case 3:
                this->addComment(customer);
                continue;
            case 4:
                this->showCoupons(customer,absc);
                system("pause");
                continue;
            case 5:
                this->showFilterGoods(customer,absc);
                system("pause");
                continue;
            case 6:
                this->showGoods_pullOff(customer);
                system("pause");
                continue;
            case 0:
                //弹出一条备忘录
                customer->originpage->care->popMeme();
                return;
        }
    }
}

void Shop::pullOffGoods(Goods gd) {
    if (goods.count(gd)) {
        //通知所有加入了该商品的的购物车
        /* cout<<"pullOffGoods()方法调用Goods的notify()方法。"<<endl; */
        gd.notify();

        int ct = this->goods.erase(gd);  //测试通过

        /* cout<<"pullOffGoods()方法结束，"<<ct<<"个商品已下架！"<<endl; */
    } else
        cout << "商品不存在！" << endl;
}

void Shop::addComment(Customer* cu) {
    system("cls");
    //记录备忘录
    cout<<"=============================="<<endl;
    cout<<"桥接模式     类名：Comment、diffAspect  "<<endl;
    cout<<"中介者模式   类名：Mediator  "<<endl;
    cout<<"=============================="<<endl;
    cu->originpage->setPage("添加评论");
    cout << "你当前所在的位置是:" << cu->originpage->care->getDescrip() << endl;
    Comment* cm = new Comment(this, cu);
    Mediator* me = new Mediator(this);
    cu->writeCommment(me, cm);
    //弹出一条备忘录
    cu->originpage->care->popMeme();
    return;
}