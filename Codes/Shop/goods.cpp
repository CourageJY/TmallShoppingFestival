#include"goods.h"
#include"../Shop/shop.h"
#include "../ShoppingCart/shoppingCart.h"
#include <algorithm>

void Goods::setGoods(string na, double pr, int mons){
	this->name = na;
	this->price = pr;
	this->outDate = mons == 0? time(0) + month * 12 : time(0) + month * mons;
}

void Goods::attach(ShoppingCart* sc){
    /* cout<<"商品"<<this->getName()<<"新增一个观察者："<<sc<<endl; */
	this->m_observer->push_back(sc);
}

void Goods::detach(ShoppingCart* sc){
	vector<ShoppingCart *>::iterator iter = m_observer->begin();
        while (iter != m_observer->end())
        {
            if ((*iter) == sc)
            {
                m_observer->erase(iter);
            }
            iter++;
        }
}

void Goods::notify(){
	vector<ShoppingCart *>::iterator iter;
    /* cout<<"打印现有观察者："<<endl;
    for(iter = m_observer->begin();iter!=m_observer->end();++iter){
        cout<<"观察者："<<(*iter)<<endl;
    }
    cout<<"通知动作："<<endl; */
    for(iter = m_observer->begin();iter!=m_observer->end();++iter){
        Goods gd = *this;
        (*iter)->update(gd);
    }
    m_observer->clear();
}