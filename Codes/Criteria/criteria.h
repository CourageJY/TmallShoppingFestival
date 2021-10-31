#pragma once
#include <map>
#include "../Shop/shop.h"
#include "../Shop/brand.h"

//过滤器
class Criteria
{
public:
	Criteria() {}

	virtual map<Goods, int> filterGoods(map<Goods, int> goods) { return map<Goods, int>(); }

	void printGoods(map<Goods, int> goods);

private:

};

//&&过滤器
class AndCriteria :public Criteria {
public:
	AndCriteria(Criteria c1, Criteria c2) :criteria(c1), otherCriteria(c2) {}

	map<Goods, int> filterGoods(map<Goods, int> goods);

private:
	Criteria criteria;
	Criteria otherCriteria;
};

//价格过滤器
class PriceCriteria :public Criteria {
public:
	PriceCriteria(double lp,double up):lowerPrice(lp), upperPrice(up) {}

	map<Goods, int> filterGoods(map<Goods, int> goods);

private:
	double upperPrice;
	double lowerPrice;

};

//品牌过滤器
class BrandCriteria :public Criteria {
public:
	BrandCriteria(Brand* sb) :standardBrand(sb) {}

	map<Goods, int> filterGoods(map<Goods, int> goods);

private:
	Brand* standardBrand;

};