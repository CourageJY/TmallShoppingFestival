#include "shop.h"

#include "../PersonalInformation/Comment.h"
#include "../PersonalInformation/customer.h"
using namespace std;

//添加商品
void Shop::addGoods(Goods goods, int stock) {
    this->goods.insert(pair<Goods, int>(goods, stock));
}

//店铺统一设置所有商品的属性
void Shop::setGoods(vector<string> names, vector<double> prices,
                    vector<time_t> times) {
    int number = this->goods.size();
    if (names.size() != number || prices.size() != number ||
        (times.size() != 0 && times.size() != number))
        return;

    auto iter = this->goods.begin();
    for (int i = 0; i < number; i++) {
        Goods tempGoods = iter->first;
        int tempStock = iter->second;
        iter++;
        //由于map无法修改key值，所以移除旧的key-value，添加新的key-value
        this->goods.erase(tempGoods);
        tempGoods.setGoods(names[i], prices[i],
                           times.size() == 0 ? NULL : times[i]);
        this->goods.insert(pair<Goods, int>(tempGoods, tempStock));
    }
}

void Shop::showGoods() {
    cout << this->name << "有以下商品：" << endl << endl;
    /*
    for (auto iter = this->goods.begin(); iter != this->goods.end(); iter++) {
        cout << "商品名称：" << iter->first.getName() << endl;
        cout << "商品价格：" << iter->first.getPrice() << "元" << endl;
        //cout << "商品保质期：" << iter->first.getOutDate() << endl;
        cout << "商品库存：" << iter->second << endl << endl;
    }
    */
    for (auto&& i : this->goods) {
        cout << "商品名称：" << i.first.getName() << endl;
        cout << "商品价格：" << i.first.getPrice() << "元" << endl;
        // cout << "商品保质期：" << i.first.getOutDate() << endl;
        cout << "商品库存：" << i.second << endl << endl;
    }
    cout << "-------------------------------------------" << endl << endl;
}

void Shop::showComments() {
    cout << "本店评价：" << endl << endl;
    /*
    for (auto iter = this->comments.begin(); iter != this->comments.end();
    iter++) { cout <<"    "<< (*iter)->getCustomer()->getName() << "：" <<
    (*iter)->getContent() << endl << endl;
    }
    */
    for (auto&& i : this->comments) {
        cout << "    " << i->getCustomer()->getName() << "：" << i->getContent()
             << endl
             << endl;
    }
    cout << "-------------------------------------------" << endl << endl;
}

//展示店铺信息，与店铺交互
void Shop::showInformation() {
    cout << "-------------------------------------------" << endl;
    cout << "欢迎光临" << this->name << "，请选择您的操作：" << endl << endl;
    cout << "1、浏览商品" << endl;
    cout << "2、查看店铺评价" << endl;
    cout << "3、退出商店" << endl;
    int order;
    while (true) {
        cin >> order;
        switch (order) {
            case 1:
                this->showGoods();
                return;
            case 2:
                this->showComments();
                return;
            case 3:
                return;
            default:
                cout << "错误选项！请重新选择：";
                break;
        }
    }
}