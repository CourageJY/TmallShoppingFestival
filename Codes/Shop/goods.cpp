#include"goods.h"
#include"../Shop/shop.h"
#include <algorithm>

void Goods::setGoods(string na, double pr, time_t ti){
	this->name = na;
	this->price = pr;
	this->outDate = ti == NULL ? time(0) + 12 * month : ti;
}

void Goods::attach(ShoppingCart* sc){
	this->m_observer.push_back(sc);
}

void Goods::detach(ShoppingCart* sc){
	this->m_observer.erase(remove(this->m_observer.begin(),this->m_observer.end(),sc),this->m_observer.end());
}