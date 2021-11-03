#include "../Filter/filter.h"

//&&过滤器：返回满足所有条件的商品
map<Goods, int> AndFilter::filterGoods(map<Goods, int> goods){
	map<Goods, int> selectedGoods = filter.filterGoods(goods);
	return otherFilter.filterGoods(selectedGoods);
}

//价格过滤器：返回指定价格区间的商品
map<Goods, int> PriceFilter::filterGoods(map<Goods, int> goods)
{
	map<Goods, int> selectedGoods;
	for (map<Goods, int>::iterator iter = goods.begin(); iter != goods.end(); iter++) {
		if (iter->first.getPrice() <= upperPrice && iter->first.getPrice() >= lowerPrice)
			selectedGoods.insert(pair<Goods, int>(iter->first, iter->second));
	}
	return selectedGoods;
}

// //品牌过滤器：返回指定品牌的商品
// map<Goods, int> BrandFilter::filterGoods(map<Goods, int> goods)
// {
// 	map<Goods, int> selectedGoods;
// 	for (map<Goods, int>::iterator iter = goods.begin(); iter != goods.end(); iter++) {
// 		if (iter->first.getShop()->getBrand() == standardBrand)
// 			selectedGoods.insert(pair<Goods,int>(iter->first,iter->second));
// 	}
// 	return selectedGoods;
// }