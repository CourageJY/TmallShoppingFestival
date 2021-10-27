#include"goods.h"
#include"../Shop/shop.h"

void Goods::setGoods(string na, double pr, time_t ti){
	this->name = na;
	this->price = pr;
	this->outDate = ti == NULL ? time(0) + 12 * month : ti;
}
