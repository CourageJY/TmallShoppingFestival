#include"Order/order.h"
#include<iostream>
#include<ctime>

int main(){
    time_t t=time(0);
    char* dt=ctime(&t);
    cout<<dt<<'\n';
    return 0;
}