#include "shoppingCart.h"
#include "../PersonalInformation/customer.h"
#include"../Order/order.h"

void ShoppingCart::addGoods(Goods gd){
    if (goods.count(gd)){ //判断是否已有该商品
        goods[gd]++;
    }
    else{
        goods.insert(map<Goods, int>::value_type(gd, 1));

        //将购物车绑定为商品的Observer
        gd.attach(this);
    }
}

bool ShoppingCart::removeGoods(Goods gd){
    if (goods.count(gd)){
        goods[gd]--;
        if (goods[gd] == 0){
            goods.erase(gd);
            
            //将购物车从商品的Observer列表中删除
            gd.detach(this);
        }
        return true;
    }
    else{
        cout << "error! 购物车中不存在该商品\n";
        return false;
    }
}

bool ShoppingCart::getGoods(string name,Goods& gd){
    map<Goods,int>::iterator it=goods.begin();
    for(it=goods.begin();it!=goods.end();it++){
        if(it->first.getName()==name){
            gd=it->first;
            return true;
        }
    }
    cout<<"error! 不存在该商品\n";
    return false;
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
        goods[it->first]-=it->second;
        if(goods[it->first]==0){
            goods.erase(it->first);
        }
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
    //当商品对象被删除时，同步清除购物车里的商品
    cout<<"Observer模式：观察者更新！"<<endl;
    removeGoods(*gd);
}

//注意！在这里实现了Goods类的通知Observer的方法
void Goods::notify(){
	for(auto iter:m_observer){
		//头文件问题所致
		iter->update(this);
	}
}