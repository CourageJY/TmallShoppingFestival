#include"goods.h"
#include"../Shop/shop.h"
#include <algorithm>

void Goods::setGoods(string na, double pr, int mons){
	this->name = na;
	this->price = pr;
	this->outDate = mons == NULL? time(0) + month * 12 : time(0) + month * mons;
}

void Goods::attach(ShoppingCart* sc){
	this->m_observer.push_back(sc);
}

void Goods::detach(ShoppingCart* sc){
	this->m_observer.erase(remove(this->m_observer.begin(),this->m_observer.end(),sc),this->m_observer.end());
}