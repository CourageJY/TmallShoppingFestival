#include "SearchEngine.h"

int getNum2(string info,int range){
    string s;
    while(1){
        cout<<info;
        cin>>s;
        if (s.length()!=1)
            continue;
        int no = s[0]-'0';
        if (no>=0&&no<=range)
            return no;
    }
    return -1;
}

vector<Goods> SearchAdaptor::getAllGoods(){
    vector<Goods> matchedgoods; //匹配的商品
    for(auto && i : shops){
        auto goods = i.getGoods();
        for(auto && j : goods){//遍历每个商店的商品，并加入到总商品中
            matchedgoods.push_back(j.first);
        }
    }
    return matchedgoods;
}

void SearchEngine::searchGoods(){
    string productName("");
    while (1){
        cout << endl <<"请输入商品名(0返回上一次搜索结果,1删除所有历史记录,2显示历史记录，3返回):";
        cin >> productName;
        if (productName=="0"){
            rollBack();
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
        search(productName);
        history.push_back(productName);
        return;
    }
    return;
}

void SearchEngine::rollBack(){
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
    vector<Goods> allGoods = adaptor.getAllGoods();
    for (auto iter = allGoods.begin();iter!= allGoods.end();iter++){
        cout<<iter->getName()<<endl;
    }
    vector<Goods> matchedGoods;
    for (auto iter = allGoods.begin();iter!= allGoods.end();iter++){
        string goodsName = iter->getName();
        if (goodsName.find(name)!=goodsName.npos)
        {
            matchedGoods.push_back(*iter);
        }
    }

    if (matchedGoods.size()==0){
        cout<<"抱歉，没有搜索到商品"<<endl;
        searchGoods();
        return;
    }
    int i=0;
    cout<<"no name\t\tprice\tshop"<<endl;
    for(auto iter = matchedGoods.begin();iter!=matchedGoods.end();iter++){
        i++;
        cout<<i<<" :"<<iter->getName()<<"\t"<<iter->getPrice()<<"\t"<<iter->getShop()->getName()<<endl;
    }
    cout<<"---到这里是成功的---------------"<<endl;
    string info = "请选择操作(0返回，1-n跳转至对应商铺)";
    int no = getNum2(info,i);
    if (no>0){
        matchedGoods[no-1].getShop()->showInformation(customer);
    }
}


