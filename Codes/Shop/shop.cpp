#include "shop.h"
#include "../tools.h"
#include "../PersonalInformation/Comment.h"
#include "../PersonalInformation/customer.h"
using namespace std;

//添加商品
void Shop::addGoods(Goods goods, int stock) {
    this->goods.insert(pair<Goods, int>(goods, stock));
}

int getNum_shop(string info,int range){
    string s;
    while(1){
        cout<<info;
        cin>>s;
        if (s.length()!=1)
            continue;
        int no = s[0]-'0';
        if (no>=0&&no<=range)
            return no;
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

void Shop::showGoods(Customer *customer) {
    system("cls");//清空屏幕
    cout << this->name << "有以下商品：" << endl << endl;
    if(this->goods.size() == 0){
        cout << "" << endl;
        return;
    }
    int k=0;
    for (auto&& i : this->goods) {
        k++;
        cout << k<<"：" << i.first.getName() << endl;
        cout << "价格: " << i.first.getPrice() << " 元" << endl;
        cout << "过期时间: " << i.first.getOutDate() << endl;
        cout << "店内库存: " << i.second << endl << endl;
    }
    cout << "-------------------------------------------" << endl << endl;
    
    int no,count;
    while (1)
    {
        cout<<"请选择你要添加的商品序号(1~"<<k<<",0返回)及其数量:";
        cin >> no;
        if (no==0)
            return;
        cin>>count;
        if (no<=0||no>k){
            cout<<"序号错误!"<<endl;
            continue;
        }
        if (count<=0){
            cout<<"数量错误!"<<endl;
            continue;
        }
        int iter =0;
        for (auto&& i : this->goods){
            if (++iter == no){
                const Goods good = i.first;
                customer->getShoppingCart()->addGoods(good,i.second);
                cout<<"添加成功"<<endl;
                system("pause");
                break;
            }
        }
    }
}

void Shop::showComments() {
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

    // commentsListIterator* cmli=ca->getIterator();
    // if(!cmli->first())
    //    { 
    //         cout<<"    "<<cmli->first()->getCustomer()->getName()<<":"<<cmli->first()->getContent();
    //         while(cmli->hasNext()){
    //             cout<<"    "<<cmli->next()->getCustomer()->getName()<<":"<<cmli->next()->getContent();
    //         }
    //     }
    // cout << "-------------------------------------------" << endl << endl;
}

//显示店铺优惠券，内容待定
void Shop::showCoupons(Customer* customer) {
    system("cls");
    cout << this->name << "的优惠券信息如下: " << endl << endl;
    if(this->coupons.size() == 0){
        cout << "抱歉！本店的优惠券已已被领取完毕" << endl;
        return;
    }
    //显示所有优惠券信息
    int k=1;
    for (auto&& i : this->coupons) {
        cout<<k<<endl;
        cout << "-------------------------------------------" << endl;
        i->showInformation();
        k++;
    }
    string info;
    info="请选择您想要领取的优惠券(1~";
    info+=to_string(k-1);
    info+=",0退出):";
    int od=getNum(info,k-1);

    if(od==0)return;

    //在顾客容器中加上该优惠券
    customer->getCoupons().push_back(coupons[od-1]);

    //从商店中减去该优惠券
    coupons.erase(coupons.begin()+(od-1));//?这里是指针类型，以配合多态实现

    Sleep(1000);

    cout<<"恭喜！ 你已经成功领取了该优惠券\n";
    cout << "-------------------------------------------" << endl << endl;
    //system("pause");
}

//展示店铺信息，与店铺交互
void Shop::showInformation(Customer* customer) {
    string info;
    info+="-------------------------------------------\n";
    info+="欢迎光临";
    info+=this->name;
    info+="，\n\n";
    info+="1、浏览商品\n2、查看店铺评价\n3、对店铺进行评价\n4、查看店铺优惠券\n0、退出商店\n请选择您的操作：";
    int order;
    while (true) {
        system("cls");
        order = getNum_shop(info,5);
        switch (order) {
            case 1:
                this->showGoods(customer);
                system("pause");
                continue;
            case 2:
                this->showComments();
                system("pause");
                continue;
            case 3:
                //TODO:ADDComments?
                this->addComment(customer);
                continue;
            case 4:
                this->showCoupons(customer);
                system("pause");
                continue;
            case 0:
                return;
        }
    }
}

void Shop::pullOffGoods(Goods gd){
    if(goods.count(gd)){
        //通知所有加入了该商品的的购物车
        /* cout<<"pullOffGoods()方法调用Goods的notify()方法。"<<endl; */
        gd.notify();

        int ct = this->goods.erase(gd);//测试通过

        cout<<"pullOffGoods()方法结束，"<<ct<<"个商品已下架！"<<endl;
    }else
        cout<<"商品不存在！"<<endl;
}
void Shop::addComment(Customer* cu){
    Comment* cm=new Comment(this,cu);
    Mediator* me=new Mediator(this);
    cu->writeCommment(*me,*cm);
    return;
}