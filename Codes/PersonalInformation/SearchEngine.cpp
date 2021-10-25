#include "SearchEngine.h"

Goods* SearchEngine::searchGoods(string name){
    //搜索商品并展示结果，由用户选择是否跳转页面
}

Goods* SearchEngine::roolBack(){
    if (!history.empty()){
        searchGoods(*history.end());
        history.pop_back();
    }
}

void SearchEngine::showHistory(){
    cout << "搜索历史：" << endl;
    for(vector<string>::iterator iter = history.begin();iter != history.end();iter++){
        cout << "1." << *iter << endl;
    }
    cout << endl;
}
