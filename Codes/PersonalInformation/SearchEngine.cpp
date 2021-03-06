#include "SearchEngine.h"
#include "../PersonalInformation/customer.h"
#include "../Shop/shop.h"
#include<iomanip>
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

void SearchEngine::searchGoods(Customer* customer,AbstractCustomer* absc){
    //记录备忘录
    customer->originpage->setPage("商品搜索");
    string productName("");
    while (1){
        system("cls");
        cout<<"=============================="<<endl;
        cout<<"命令模式     类名：SearchEngine  "<<endl;
        cout<<"适配器模式   类名：SearchAdaptor "<<endl;
        cout<<"=============================="<<endl;
        cout << "你当前所在的位置是:" << customer->originpage->care->getDescrip() << endl;
        cout <<"请输入商品名(0:返回,1:查看上一次搜索结果,2:清空历史记录,3:显示历史记录):";
        cin >> productName;
        if (productName=="0"){
            //弹出一条备忘录
            customer->originpage->care->popMeme();
            return;
        }
        if (productName=="1"){
            rollBack(customer,absc);
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
        search(productName,customer,absc);
        history.push_back(productName);
        continue;
    }
    return;
}

void SearchEngine::rollBack(Customer* customer,AbstractCustomer* absc){
    if (!history.empty()){
        string s = *(history.end()-1);
        history.pop_back();
        search(s,customer,absc);
    }
}

void SearchEngine::showHistory(){
    cout<<"-------------------------------------"<<endl;
    cout << "搜索历史：" << endl;
    int count =0;
    for(auto iter = history.begin();iter != history.end();iter++){
        count++;
        cout << count<<"." << *iter << endl;
    }
    if (count==0)
        cout<<"无"<<endl;
    cout<<"-------------------------------------"<<endl;
    system("pause");
}

void SearchEngine::search(string name,Customer* customer,AbstractCustomer* absc){
    SearchAdaptor adaptor;
    vector<Goods> allGoods = adaptor.getAllGoods();
    vector<Goods> matchedGoods;
    cout<<"-------------------------------"<<endl;
    for (auto iter = allGoods.begin();iter!= allGoods.end();iter++){
        string goodsName = iter->getName();
        if (goodsName.find(name)!=goodsName.npos)
        {
            matchedGoods.push_back(*iter);
        }
    }

    if (matchedGoods.size()==0){
        cout<<"抱歉，没有搜索到商品"<<endl;
        cout<<"-------------------------------"<<endl;
        system("pause");
        return;
    }
    int i=0;
    cout<<"   "<<left<<setw(15)<<"name"<<setw(10)<<"price"<<setw(10)<<"shop"<<endl;
    for(auto && j : matchedGoods){
        i++;
        cout<<i<<" :"<<setw(15)<<j.getName()<<setw(10)<<j.getPrice()<<setw(10)<<j.getShop()->getName()<<endl;
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
            matchedGoods[i-1].getShop()->showInformation(customer,absc);
            return;
        }
    }
    return;
}


