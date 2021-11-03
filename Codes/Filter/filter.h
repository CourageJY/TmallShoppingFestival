#pragma once
#include <map>
#include "../Shop/goods.h"
// #include "../Shop/brand.h"

//过滤器
class Filter
{
public:
	Filter() {}

	virtual map<Goods, int> filterGoods(map<Goods, int> goods) { return map<Goods, int>(); }

private:

};

//&&过滤器
class AndFilter :public Filter {
public:
	AndFilter(Filter f1, Filter f2) :filter(f1), otherFilter(f2) {}

	map<Goods, int> filterGoods(map<Goods, int> goods);

private:
	Filter filter;
	Filter otherFilter;
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

// //品牌过滤器
// class BrandFilter :public Filter {
// public:
// 	BrandFilter(Brand* sb) :standardBrand(sb) {}

// 	map<Goods, int> filterGoods(map<Goods, int> goods);

// private:
// 	Brand* standardBrand;

// };