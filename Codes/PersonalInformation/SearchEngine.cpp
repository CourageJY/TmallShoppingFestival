#include "SearchEngine.h"

vector<Goods> SearchAdaptor::getAllGoods(){
    vector<Goods> matchedgoods; //匹配的商品
    for(auto && i : shops){
        auto goods = i.getGoods();
        for(auto && j : goods){//遍历每个商店的商品，并加入到总商品中
            matchedgoods.push_back(j.first);
        }
    }
    for(auto iter = shops.begin();iter != shops.end();iter++){
        map<Goods,int> goods = iter->getGoods();
        for(auto mapiter=goods.begin();mapiter!=goods.end();mapiter++){     //遍历每个商店的商品，并加入到总商品中
            matchedgoods.push_back(mapiter->first);
        }
    }
    return matchedgoods;
}

void SearchEngine::searchGoods(){
    string productName("");
    while (productName==""){
        cout << endl <<"请输入商品名(输入0返回上一次搜索结果,输入1删除所有历史记录,输入2显示历史记录，输入3返回):";
        cin >> productName;
        if (productName=="0"){
            roolBack();
            continue;
        }
        if (productName=="1"){
            emptyHistory();
            continue;
        }
        if (productName=="2"){
            showHistory();
            continue;
        }
        if (productName=="3"){
            return;
        }
        if (productName.length()==1){
            cout << "至少输入两个字符" << endl;
            continue;
        }
        break;
    }
    history.push_back(productName);
    search(productName);
}

void SearchEngine::roolBack(){
    if (!history.empty()){
        string s;
        history.pop_back();
        search(s);
    }
}

void SearchEngine::showHistory(){
    cout << "搜索历史：" << endl;

    for(auto iter = history.begin();iter != history.end();iter++){
        cout << "1." << *iter << endl;
    }
    cout << endl;
}

void SearchEngine::search(string name){
    SearchAdaptor adaptor;
    /*
    vector<Goods> allGoods = adaptor.getAllGoods();
    vector<Goods> matchedGoods;
    for (auto iter = allGoods.begin();iter!= allGoods.end();iter++){
        string goodsName = iter->getName();
        if (goodsName.find(name)>=0)
        {
            matchedGoods.push_back(*iter);
        }
    }

    if (matchedGoods.size()==0){
        cout<<"抱歉，没有搜索到商品"<<endl;
        
        return;
    }
    int i=0;
    cout<<"no name/tprice/tshop"<<endl;
    for (auto iter = matchedGoods.begin();iter!= matchedGoods.end();iter++){
        i++;
        cout<<i<<" :"<<iter->getName()<<"/t"<<iter->getPrice()<<"/t"<<iter->getShop()<<endl;
    }
     */
}


