#pragma once
#include <iostream>

using namespace std;
int getnum(string info,int range){
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