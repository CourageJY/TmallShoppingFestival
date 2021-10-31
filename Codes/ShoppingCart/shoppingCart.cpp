#include "shoppingCart.h"
#include "../PersonalInformation/customer.h"
#include"../Order/order.h"

//添加商品数据
bool CartData::add(Goods gd) {
    if (goods.count(gd)){ //判断是否已有该商品
        goods[gd]++;
        return true;
    }
    else{
        goods.insert(map<Goods, int>::value_type(gd, 1));
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

void ShoppingCart::addGoods(Goods gd){
    if(!goodsData->add(gd)) {
        //将购物车绑定为商品的Observer
        gd.attach(this);
    }        
}

bool ShoppingCart::removeGoods(Goods gd){
    if(goodsData->remove(gd)) {        
        //将购物车从商品的Observer列表中删除
        gd.detach(this);
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
        cout<<"error! 不设置的商品数量不能小于1\n";
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
        if(0){//店铺中已没有该商品
            sus=false;
            break;
        }
    }
    if(!sus){
        cout<<"抱歉！订单中的"<<it->first.getName()
            <<"商品已售罄，请重新核对订单\n";
        return false;
    }
    for(it=gds.begin();it!=gds.end();it++){//购物车中减去对应商品
        goodsData->remove(it->first);
    }
    for(it=gds.begin();it!=gds.end();it++){//从店铺中减去对应商品
           
    }
    //新建订单并将其加入到customer的order容器中
    Order* newOd=new Order(this->customer);
    for(it=gds.begin();it!=gds.end();it++){
        for(int i=0;i<it->second;it++){
            newOd->getGoods().push_back(it->first);
        }
    }
    this->customer->getOrders().push_back(*newOd);
    return true;
}

void ShoppingCart::update(Goods* gd){
    //当商品对象被删除时，同步清除购物车里的对应商品，并打印通知
    removeGoods(*gd);
    cout<<"Observers updated: Some goods in the shopping-cart have been pulled off by the shops！"<<endl;
}

//注意！在这里实现了Goods类的通知Observer的方法
void Goods::notify(){
	for(auto iter:m_observer){
		//头文件问题所致
		iter->update(this);
	}
}