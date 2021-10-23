#include"Order/order.h"
//#include"ShoppingCart/shoppingCart.cpp"
#include<iostream>
#include<ctime>
#include<map>

int main() {
    time_t time1 = time(0);

    time_t time2 = time1 + 2592000;

    char *dt1 = ctime(&time1);
    cout << dt1 << '\n';
    char *dt2 = ctime(&time2);
    cout << dt2 << '\n';

    map<string,int> m;
    map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){

    }
    return 0;
}