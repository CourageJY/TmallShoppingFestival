#include"customer.h"
#include"../Order/orderState.h"
#include "../Order/checkOrder.h"
#include "../AfterSale/AfterSale.h"

void Customer::viewBasicInformation() {
    //记录备忘录
    originpage->setPage("个人中心");
    string info("请选择你的操作(0:返回，1:查看优惠券，2:查看购物车，3：查看未支付订单，4：查看所有订单)");
    int order;
    static bool first = true;
    while (1) {
        system("cls");
        cout<<"======================================="<<endl;
        cout<<"代理者模式   类名：ProxyPatternCustomer  "<<endl;
        cout<<"状态模式   类名：orderState  "<<endl;
        cout<<"工厂模式   类名：Payment  "<<endl;
        cout<<"策略模式   类名：Payment  "<<endl;
        cout<<"======================================="<<endl;
        cout << "你当前所在的位置是:" << originpage->care->getDescrip() << endl;
        cout << "以下是您的基本信息：\n";
        cout << "姓名：" << name << '\n';
        cout << "电话号码：" << tel << '\n';
        cout << "居住地址：" << addr << '\n';
        cout << "性别：" << (gender == male ? "男" : "女") << '\n';
        cout << "头像：" << profile << '\n';
        cout << "您剩余的金额为：" << money << '\n';
        cout << "--------------------------\n\n";
        if (!first)
            order = getNum(info, 4);
        else {
            order = 0;
            first = false;
        }
        if (order == 0) {            
            //弹出一条备忘录
            originpage->care->popMeme();
            return;
        }
        if (order == 1) {
            showCoupons();
            continue;
        }
        if (order == 2) {
            showShoppingCart();
            continue;
        }
        if (order == 3) {
            payOrder();
            system("pause");
            continue;
        }
        if (order == 4) {
            check();
            system("pause");
            continue;
        }
        continue;
    }
    system("pause");

//    cout<<"It's your basic Information:\n";
//    cout<<"name: "<<name<<'\n';
//    cout<<"tel: "<<tel<<'\n';
//    cout<<"address: "<<addr<<'\n';
//    cout<<"gender: "<<(gender==male?"male":"female")<<'\n';
//    cout<<"profile: " + profile<<'\n';
//    cout<<"your current money is: "<<money<<"\n\n";
}

void Customer::check() {
    cout << "请输入您想查看的订单类型（1/2/3）：1为待支付，2为已支付，3为已取消:\n";
    int orderType;
    cin >> orderType;
    while (orderType < 1 || orderType > 3) {
        cout << "抱歉，您的输入不符合要求，请重新输入：";
        cin >> orderType;
    }
    checkOrder *ck = new checkOrder(orderType, this);
    ck->showInformation();
}

void Customer::showCoupons() {
    cout << "您目前拥有以下优惠券：\n\n";
    //显示所有优惠券信息
    int k = 1;
    for (auto &&i: this->coupons) {
        cout << k << endl;
        cout << "-------------------------------------------\n" << endl;
        i->showInformation();
        k++;
    }
    system("pause");
}

bool Customer::payOrder() {
    vector<Order> vec;
    vector<int> id;//记录未支付订单的id
    int j = 0;
    for (auto od: orders) {
        if (od.getState() == unpaid) {
            vec.push_back(od);
            id.push_back(j);
        }
        j++;
    }
    if (vec.size() == 0) {
        cout << "\n您当前还没有待支付订单，快去购物车生成订单吧\n";
        return false;
    }
    cout << "当前您未支付的订单共" << vec.size() << "个，分别为：\n";
    cout << "-------------------";
    int i = 1;
    for (auto v: vec) {
        cout << i << '\n';
        v.showOrder();
        cout<<endl;
        i++;
    }
    cout << "-------------------";
    cout << "请选择您想要操作的订单id(1~" << vec.size() << ")\n";
    int x;
    cin >> x;
    if (x < 1 || x > vec.size()) {
        cout << "您输入的订单不存在！\n";
        return false;
    } else {
        if (money >= vec[x - 1].getSum() && vec[x - 1].pay()) {
            money -= vec[x - 1].getSum();
            orders[id[x - 1]].setState(paid);//修改订单状态
            return true;
        } else {
            cout << "支付失败！金额不足或订单未处于待支付状态！\n";
            orders[id[x - 1]].setState(error);//修改订单状态
            return false;
        }
    }
}

void ProxyPatternCustomer::giveRealCustomer(Customer *customer) {
    cout << "使用了父类的给予指针函数，调用错误" << endl;
}

void Customer::showShoppingCart() {
    //记录备忘录
    originpage->setPage("购物车");
    ShoppingCart *cart = this->getShoppingCart();
    map<Goods, int> goods = cart->getGoodsMap();

    int order;
    string info = "请选择您的操作(0返回，1清空购物车，2修改一项商品的数量，3生成订单并购买，4退货)";
    while (1) {
        system("cls");
        cout<<"================================="<<endl;
        cout<<"数据访问对象模式   类名：CartData  "<<endl;
        cout<<"外观模式          类名：AfterSale  "<<endl;
        cout<<"================================="<<endl;
        cout << "你当前所在的位置是:" << originpage->care->getDescrip() << endl;
        cart->showAllGoods();
        cout << "---------------------" << endl;
        order = getNum(info, 4);
        if (order == 0) {
            //弹出一条备忘录
            originpage->care->popMeme();
            return;
        }
        if (order == 1) {
            for (auto &&i: goods) {
                cart->removeGoods(i.first);
                cout << "\n---------------------------------\n";
                cout << "\n购物车清除成功，快去重新采购商品吧！\n";
                system("pause");
            }
        }
        if (order == 2) {
            cout << "请输入商品的序号和修改后的数量(0返回):";
            int no, count;
            cin >> no >> count;
            if (no == 0) {
                return;
            }
            if (count < 0) {
                cout << "数量错误!" << endl;
                continue;
            }
            int k = 0;
            for (auto &&i: goods) {
                k++;
                if (k == no) {
                    if (cart->setGoodsNum(i.first, count)) {
                        cout << "\n修改成功" << endl;
                    } else {
                        cout << "\n修改失败" << endl;
                    }
                    break;
                }
            }
            if (k != no)
                cout << "序号不存在！\n";
            system("pause");
        }
        if (order == 3) {
            if (cart->getGoodsMap().empty()) {
                cout << "\n抱歉！目前购物车已没有商品了呢\n\n请重新在商铺里面添加商品吧\n\n";
                return;
            }
            if (cart->generateOrder(cart->getGoodsMap())) {//订单生成成功则直接返回
                system("pause");
                return;
            }
        }
        if (order == 4) {
            AfterSale *afterSale = new AfterSale(this);
            afterSale->returned();
            break;
        }
    }
}