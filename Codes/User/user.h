#pragma once
#include<string>
using namespace std;

//表达式类
class Expression{
public:
    virtual bool interpret(string context) = 0;  //翻译功能用虚函数实现
};

//实体表达式类
class TerminalExpression:public Expression{
private:
    string data;  //该表达式所代表的数据
public:
    TerminalExpression(string data){
        this->data=data;
    }
    bool interpret(string context);  //表达式翻译
};

//用实体表达式类实现的操作（或操作）
class OrExpression:public Expression{
private:
    Expression* expr1;
    Expression* expr2;
public:
    OrExpression(Expression* expr1,Expression* expr2){
        this->expr1 = expr1;
        this->expr2 = expr2;
    }
    OrExpression():expr1(NULL),expr2(NULL){};
    bool interpret(string context);  //操作翻译
};

//设定用户的函数
Expression* setUsers();