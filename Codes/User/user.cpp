#include "user.h"
using namespace std;

bool TerminalExpression::interpret(string context){
    if(context==data){  //如果要翻译的文本等于该数据，就证明存在该文本（该文本符合规则）
        return true;
    }
    else{
        return false;
    }
}

bool OrExpression::interpret(string context){
    return expr1->interpret(context)||expr2->interpret(context);   //只要该文本符合一个规则就好
}