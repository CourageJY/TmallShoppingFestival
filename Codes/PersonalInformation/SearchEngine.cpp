#include "SearchEngine.h"
#include "../PersonalInformation/customer.h"
#include "../Shop/shop.h"

vector<Goods> SearchAdaptor::getAllGoods(){
    vector<Goods> matchedgoods; //匹配的商品
    for(auto && i : shops){
        auto goods = i->getGoods();
        for(auto && j : goods){//遍历每个商店的商品，并加入到总商品中
            matchedgoods.push_back(j.first);
        }
    }

    return matchedgoods;
}

void SearchEngine::searchGoods(Customer* customer){
    string productName("");
    while (1){
        system("cls");
        cout <<"请输入商品名(0:返回,1:查看上一次搜索结果,2:清空历史记录,3:显示历史记录):";
        cin >> productName;
        if (productName=="0"){
            return;
        }
        if (productName=="1"){
            rollBack(customer);
            continue;
        }
        if (productName=="2"){
            emptyHistory();
            cout<<"历史记录已清除.."<<endl;
            system("pause");
            continue;
            
        }
        if (productName=="3"){
            showHistory();
            continue;
            
        }
        if (productName.length()==1){
            cout << "至少输入两个字符" << endl;
            system("pause");
            continue;
        }
        search(productName,customer);
        history.push_back(productName);
        continue;
    }
    return;
}

void SearchEngine::rollBack(Customer* customer){
    if (!history.empty()){
        string s = *(history.end()-1);
        history.pop_back();
        search(s,customer);
    }
}

void SearchEngine::showHistory(){
    cout << "搜索历史：" << endl;
    int count =0;
    for(auto iter = history.begin();iter != history.end();iter++){
        count++;
        cout << count<<"." << *iter << endl;
    }
    cout<<"-------------------------"<<endl;
    system("pause");
}

void SearchEngine::search(string name,Customer* customer){
    SearchAdaptor adaptor;
    vector<Goods> allGoods = adaptor.getAllGoods();
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
        system("pause");
        return;
    }
    int i=0;
    cout<<"No"<<"\t\t"<<"name"<<"\t\t"<<" price"<<"\t\t"<<"shop"<<endl;
    for(auto && j : matchedGoods){
        i++;
        cout<<i<<"\t\t"<<j.getName()<<"\t\t"<<j.getPrice()<<"\t\t"<<j.getShop()->getName()<<endl;
    }
    string info("请选择你要进行的操作(0返回，1~");
    info+=to_string(i);
    info+="进入商店所在店铺)：";
    int order;
    while(1){
        order = getNum(info,i);
        if(order==0)
            return;
        if(order<=i){
            matchedGoods[i-1].getShop()->showInformation(customer);
            return;
        }
    }
    return;
}


