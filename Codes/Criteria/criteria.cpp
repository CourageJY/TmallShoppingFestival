#include "../Criteria/criteria.h"

//输出筛选结果
void Criteria::printGoods(map<Goods, int> goods) {
	if (goods.size() == 0) {
		cout << "没有满足筛选条件的商品！" << endl << endl;
		return;
	}

	cout << "满足筛选条件的商品如下：" << endl;
	for (map<Goods, int>::iterator iter = goods.begin(); iter != goods.end(); iter++) {
		cout << "商品名称：" << iter->first.getName() << endl;
		cout << "商品价格：" << iter->first.getPrice() << "元" << endl;
		//cout << "商品保质期：" << iter->first.getOutDate() << endl;
		cout << "商品库存：" << iter->second << endl << endl;
	}
}

//&&过滤器：返回满足所有条件的商品
map<Goods, int> AndCriteria::filterGoods(map<Goods, int> goods){
	map<Goods, int> selectedGoods = criteria.filterGoods(goods);
	return otherCriteria.filterGoods(selectedGoods);
}

//价格过滤器：返回指定价格区间的商品
map<Goods, int> PriceCriteria::filterGoods(map<Goods, int> goods)
{
	map<Goods, int> selectedGoods;
	for (map<Goods, int>::iterator iter = goods.begin(); iter != goods.end(); iter++) {
		if (iter->first.getPrice() <= upperPrice && iter->first.getPrice() >= lowerPrice)
			selectedGoods.insert(pair<Goods, int>(iter->first, iter->second));
	}
	return selectedGoods;
}

//品牌过滤器：返回指定品牌的商品
map<Goods, int> BrandCriteria::filterGoods(map<Goods, int> goods)
{
	map<Goods, int> selectedGoods;
	for (map<Goods, int>::iterator iter = goods.begin(); iter != goods.end(); iter++) {
		if (iter->first.getShop()->getBrand() == standardBrand)
			selectedGoods.insert(pair<Goods,int>(iter->first,iter->second));
	}
	return selectedGoods;
}