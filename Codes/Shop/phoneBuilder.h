/// 实现建造者模式和模板模式的主要头文件
#pragma once

#ifndef __PHONEBUILDER_H__
#define __PHONEBUILDER_H__

#include <iostream>
#include <string>

#include "goods.h"

using namespace std;

class Phone : public Goods{
   public:
    Phone(string na, double pr, Shop* sh):Goods(na,pr,sh) {
        mStrMemory = "4GB";
        mStrStorage = "64GB";
    }
    void setStorage(const string& storage) { mStrStorage = storage; }
    void setMemory(const string& memory) { mStrMemory = memory; }
    void ShowDetails() {
        cout << "Storage size : " << mStrStorage.c_str() << endl;
        cout << "Memory size : " << mStrMemory.c_str() << endl;
    }

   private:
    string mStrStorage;
    string mStrMemory;
};

//模板模式，豪华建造者和建议建造者都继承自模板建造者
class Builder {
   public:
    virtual void buildStorage() = 0;
    virtual void buildMemory() = 0;
    virtual Phone* GetResult() = 0;
};

//创建指挥者，通过使用不同的建造者建造不同的产品
class Director {
   public:
    void Construct(Builder* builder) {
        builder->buildMemory();
        builder->buildStorage();
    }
};

//豪华版建造者
class LuxuryBuilder : public Builder {
   public:
    LuxuryBuilder(string na, double pr, Shop* sh) { product = new Phone(na, pr, sh); }
    Phone* GetResult() { return product; }
    void buildStorage() { product->setStorage("512GB"); }
    void buildMemory() { product->setMemory("12GB"); }

   private:
    Phone* product;
};

//简易版建造者
class SimpleBuilder : public Builder {
   public:
    SimpleBuilder(string na, double pr, Shop* sh) { product = new Phone(na, pr, sh); }
    Phone* GetResult() { return product; }
    void buildStorage() { product->setStorage("64GB"); }
    void buildMemory() { product->setMemory("4GB"); }

   private:
    Phone* product;
};

/*
void builder_test_main() {
    // 创建指挥者
    Director director;

    // 创建豪华版建造者
    Builder* lbuilder = new LuxuryBuilder();

    // 创建豪华版手机
    director.Construct(lbuilder);

    // 获得产品
    cout << "This is iphone 12 pro." << endl;
    Phone* luxuryPhone = lbuilder->GetResult();
    luxuryPhone->ShowDetails();

    cout << "----------------------" << endl;

    // 创建简单版建造者
    Builder* sbuilder = new SimpleBuilder();

    // 创建豪华版手机
    director.Construct(sbuilder);

    // 获得产品
    cout << "This is iphone 5." << endl;
    Phone* simplePhone = sbuilder->GetResult();
    simplePhone->ShowDetails();
}
*/
#endif  //__PHONEBUILDER_H__