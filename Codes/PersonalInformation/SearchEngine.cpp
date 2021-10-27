#include "SearchEngine.h"

vector<Goods> SearchAdaptor::getAllGoods(){
    vector<Goods> matchedgoods; //匹配的商品
    for(vector<Shop>::iterator iter = shops.begin();iter != shops.end();iter++){
        map<Goods,int> goods = iter->getGoods();
        for(map<Goods,int>::iterator mapiter=goods.begin();mapiter!=goods.end();mapiter++){     //遍历每个商店的商品，并加入到总商品中
            matchedgoods.push_back(mapiter->first);
        }
    }
    return matchedgoods;
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


