#include "tools.h"

int getNum(string info, int range) {
    string s;
    while (1) {
        s.clear();
        cout << info;
        while (s == "") cin >> s;
        bool f = false;
        for (auto&& i : s) {
            if (!isdigit(i)) {
                f = true;
                break;
            }
        }
        if (f) {
            cout << "检测到无效输入，请重试" << endl;
            continue;
        }
        return str2num(s);
    }
    return -1;
}

double str2num(string s) {
    stringstream ss;
    double d = 0.0;
    ss << s;
    ss >> d;
    return d;
}