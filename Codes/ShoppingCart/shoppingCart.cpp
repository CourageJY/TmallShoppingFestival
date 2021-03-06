#include "shoppingCart.h"
#include "../PersonalInformation/customer.h"
#include"../Order/order.h"

//添加商品数据
bool CartData::add(Goods gd, int num) {
    if (goods.count(gd)){ //判断是否已有该商品
        goods[gd] += num;
        return true;
    }
    else{
        goods.insert(map<Goods, int>::value_type(gd, num));
        return false;
    }
}

//删除商品数据
bool CartData::remove(Goods gd) {
    if (goods.count(gd)){
        goods.erase(gd);     
        return true;
    }
    else{
        return false;
    }
};

//设置商品数量
bool CartData::setNum(Goods gd, int n) {
    if (goods.count(gd)){
        goods[gd] = n;
        return true;
    }
    else{
        return false;
    }    
}

//获取商品数据
bool CartData::get(string name,Goods& gd) {
    map<Goods,int>::iterator it=goods.begin();
    for(it=goods.begin();it!=goods.end();it++){
        if(it->first.getName()==name){
            gd=it->first;
            return true;
        }
    }
    return false;
}

map<Goods,int>& CartData::getMap() {
    return goods;
}

void ShoppingCart::addGoods(Goods gd, int num){
    if(!goodsData->add(gd, num)) {
        //将购物车绑定为商品的Observer
        gd.attach(this);
    }        
}

bool ShoppingCart::removeGoods(Goods gd){
    if(goodsData->remove(gd)) {
        //gd.detach(this);        
        return true;
    }
    else {        
        cout << "error! 购物车中不存在该商品\n";
        return false;
    }
}

bool ShoppingCart::getGoods(string name,Goods& gd){
    if(!goodsData->get(name,gd)) {
        cout<<"error! 不存在该商品\n";
        return false;
    }
    return true;
}

bool ShoppingCart::setGoodsNum(Goods gd, int n){
    if(n < 1) {
        cout<<"error! 设置的商品数量不能小于1\n";
        return false;
    }
    if(!goodsData->setNum(gd, n)) {
        cout<<"error! 不存在该商品\n";
        return false;
    }
    return true;
}

map<Goods,int>& ShoppingCart::getGoodsMap() {
    return goodsData->getMap();
}

bool ShoppingCart::generateOrder(map<Goods,int> gds){
    bool sus=true;
    map<Goods,int>::iterator it;
    for(it=gds.begin();it!=gds.end();it++){
        if(it->first.getShop()->getGoods()[it->first]-gds[it->first]<0){//店铺中已没有该商品
            sus=false;
            break;
        }
    }
    if(!sus){
        cout<<"抱歉！订单中的"<<it->first.getName()
            <<"商品已售罄，请重新核对订单\n";
        return false;
    }
    for(it=gds.begin();it!=gds.end();it++){//从店铺中减去对应商品
        it->first.getShop()->getGoods()[it->first]-=gds[it->first];
    }
    for(it=gds.begin();it!=gds.end();it++){//购物车中减去对应商品
        goodsData->remove(it->first);
    }
    //新建订单并将其加入到customer的order容器中
    Order* newOd=new Order(this->customer);
    for(it=gds.begin();it!=gds.end();it++){
        for(int i=0;i<it->second;i++){
            newOd->getGoods().push_back(it->first);
            newOd->getSum()+=it->first.getPrice();
        }
    }
    this->customer->getOrders().push_back(*newOd);

    cout<<"\nOK, 您已成功生成了订单，请及时在个人信息界面完成支付吧\n";
    return true;
}

void ShoppingCart::update(Goods gd){
    //当商品对象被下架时，同步改变购物车里的商品信息，向下架列表中加入该商品
    this->offShelfGoods.push_back(gd);
    this->removeGoods(gd);
    this->isUpdate = true;
    //cout<<"Observers updated: Some goods in the shopping-cart have been pulled off by the shops！"<<endl;
}

void ShoppingCart::showAllGoods() {
    if(this->isUpdate){
        cout<<"\n您有新的通知：\n\n";
        vector<Goods>::iterator iter = offShelfGoods.begin();
        for(int cnt=1;iter!=offShelfGoods.end();++iter){
            cout<<"    "<<cnt++<<". 商品 "<<iter->getName()<<" 已被店家下架！\n";
        }
        //通知后改变更新标记，清空下架商品列表
        isUpdate = false;
        offShelfGoods.clear();
        cout<<endl;
    }

    map<Goods,int>::iterator it;
    cout<<"当前购物车有如下商品：\n\n";
    int k=1;
    for(it=goodsData->getMap().begin();it!=goodsData->getMap().end();it++){
        cout<<k<<endl;
        cout<<"----------------\n";
        cout<<it->first.getName()<<"\n价格："<<it->first.getPrice()<<" 元"
            <<"\n数量："<<it->second<<endl<<endl;
    }
}