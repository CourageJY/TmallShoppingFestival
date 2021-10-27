#pragma once
#include <map>
#include "../Shop/shop.h"

//������
class Criteria
{
public:
	Criteria() {}

	virtual map<Goods, int> filterGoods(map<Goods, int> goods) { return map<Goods, int>(); }

	void printGoods(map<Goods, int> goods);

private:

};

//&&������
class AndCriteria :public Criteria {
public:
	AndCriteria(Criteria c1, Criteria c2) :criteria(c1), otherCriteria(c2) {}

	map<Goods, int> filterGoods(map<Goods, int> goods);

private:
	Criteria criteria;
	Criteria otherCriteria;
};

//�۸������
class PriceCriteria :public Criteria {
public:
	PriceCriteria(double lp,double up):lowerPrice(lp), upperPrice(up) {}

	map<Goods, int> filterGoods(map<Goods, int> goods);

private:
	double upperPrice;
	double lowerPrice;

};

//Ʒ�ƹ�����
class BrandCriteria :public Criteria {
public:
	BrandCriteria(string sb) :standardBrand(sb) {}

	map<Goods, int> filterGoods(map<Goods, int> goods);

private:
	string standardBrand;

};