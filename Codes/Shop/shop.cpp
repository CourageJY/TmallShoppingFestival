#include "shop.h"
#include "../tools.h"
#include "../PersonalInformation/Comment.h"
#include "../PersonalInformation/customer.h"
using namespace std;

//添加商品
void Shop::addGoods(Goods goods, int stock) {
    this->goods.insert(pair<Goods, int>(goods, stock));
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

void Shop::showGoods() {
    cout << this->name << "有以下商品：" << endl << endl;
    if(this->goods.size() == 0){
        cout << "" << endl;
        return;
    }
    
    for (auto&& i : this->goods) {
        cout << "商品名字：" << i.first.getName() << endl;
        cout << "价格: " << i.first.getPrice() << "yuan" << endl;
        cout << "过期时间: " << i.first.getOutDate() << endl;
        cout << "店内库存: " << i.second << endl << endl;
    }
    cout << "-------------------------------------------" << endl << endl;
}

void Shop::showComments() {
    commentsListIterator* cmli=ca->getIterator();
    cout << "本店评价：" << endl << endl;
    // if(this->comments.size() == 0){
    //     cout << "" << endl;
    //     return;
    // }

    // for (auto&& i : this->comments) {
    //     cout << "    " << i->getCustomer()->getName() << "：" << i->getContent()
    //          << endl
    //          << endl;
    // }
    if(!cmli->first())
       { 
            cout<<"    "<<cmli->first()->getCustomer()->getName()<<":"<<cmli->first()->getContent();
            while(cmli->hasNext()){
                cout<<"    "<<cmli->next()->getCustomer()->getName()<<":"<<cmli->next()->getContent();
            }
        }
    cout << "-------------------------------------------" << endl << endl;
}

//显示店铺优惠券，内容待定
void Shop::showCoupons() {
    cout << this->name << "has: " << endl << endl;
    if(this->coupons.size() == 0){
        cout << "" << endl;
        return;
    }
    
    for (auto&& i : this->coupons) {
        
    }
    cout << "-------------------------------------------" << endl << endl;
}

//暂定为展示店铺信息，与店铺交互
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

void Shop::pullOffGoods(Goods gd){
    if(goods.count(gd)){
        //通知所有加入了该商品的的购物车
        gd.notify();

        //从上架商品map中删除该商品
        goods.erase(gd);

        cout<<"商品已下架！"<<endl;
    }else
        cout<<"商品不存在！"<<endl;
}