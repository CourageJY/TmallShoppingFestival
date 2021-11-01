#pragma once
#include <map>
#include "../Shop/shop.h"
#include "../Shop/brand.h"

//过滤器
class Filter
{
public:
	Filter() {}

	virtual map<Goods, int> filterGoods(map<Goods, int> goods) { return map<Goods, int>(); }

	void printGoods(map<Goods, int> goods);

private:

};

//&&过滤器
class AndFilter :public Filter {
public:
	AndFilter(Filter c1, Filter c2) :criteria(c1), otherCriteria(c2) {}

	map<Goods, int> filterGoods(map<Goods, int> goods);

private:
	Filter criteria;
	Filter otherCriteria;
};

//价格过滤器
class PriceFilter :public Filter {
public:
	PriceFilter(double lp,double up):lowerPrice(lp), upperPrice(up) {}

	map<Goods, int> filterGoods(map<Goods, int> goods);

private:
	double upperPrice;
	double lowerPrice;

};

//品牌过滤器
class BrandFilter :public Filter {
public:
	BrandFilter(Brand* sb) :standardBrand(sb) {}

	map<Goods, int> filterGoods(map<Goods, int> goods);

private:
	Brand* standardBrand;

};