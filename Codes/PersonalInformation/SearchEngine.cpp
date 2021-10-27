#include "SearchEngine.h"

vector<Goods> SearchAdaptor::getAllGoods(){
    vector<Shop> clothingshops = ClothingVenue::getInstance().getShops();
    vector<Shop> snackshops = SnacksVenue::getInstance().getShops();
    vector<Shop> electronicshops = ElectronicVenue::getInstance().getShops();
    vector<Shop> fruitshops = FruitsVenue::getInstance().getShops();
    vector<Shop> shops;
    vector<Goods> matchedgoods; //匹配的商品
    shops.insert(shops.end(), clothingshops.begin(), clothingshops.end());
    shops.insert(shops.end(), snackshops.begin(), electronicshops.end());
    shops.insert(shops.end(), electronicshops.begin(), electronicshops.end());
    shops.insert(shops.end(), fruitshops.begin(), fruitshops.end());
    for(vector<Shop>::iterator iter = shops.begin();iter != shops.end();iter++)
    {
        //TODO
        //遍历商店中的商品并进行字符串匹配
    }
}

Goods* SearchEngine::searchGoods(){
    string productName("");
    cout << endl;
    cout << "请输入商品名(输入0返回上一次搜索结果,输入1删除所有历史记录):";
    while (productName==""){
        cin >> productName;
        if (productName=="0"){
            return roolBack();
        }
        if (productName=="1"){
            emptyHistory();
            return 0;
        }
        if (productName.length()==1){
            cout << "至少输入两个字符" << endl;
        }
    }
    history.push_back(productName);
    return search(productName);
}

Goods* SearchEngine::roolBack(){
    if (!history.empty()){
        string s;
        history.pop_back();
        return search(s);
    }
    return NULL;
}

void SearchEngine::showHistory(){
    cout << "搜索历史：" << endl;
    for(vector<string>::iterator iter = history.begin();iter != history.end();iter++){
        cout << "1." << *iter << endl;
    }
    cout << endl;
}

Goods* SearchEngine::search(string name){

}


