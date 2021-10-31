//利用品牌来实现享元模式，对于同一品牌的不同实体店铺，它们品牌名都相同可作为内部状态
//但是同一品牌具体店铺的地理位置不同，可作为外部状态

#pragma once
#include<string>
#include<map>
#include <utility>
using namespace std;

//地址的抽象类
class Address{
public:
    Address(string cu,string cy):country(std::move(cu)),city(std::move(cy)){};
    string getCountry()const{return country;}
    string getCity()const{return city;}

private:
    string country;
    string city;
};

//品牌类
class Brand{
public:
    Brand()= default;
    explicit Brand(string bd):brandName(std::move(bd)){}
    virtual void showAddress(const Address& ad){}

private:
    string brandName;
};

class SharedBrand:public Brand{
public:
    SharedBrand()= default;
    explicit SharedBrand(string bd):Brand(std::move(bd)){}
    void showAddress(const Address& ad) override{
        cout<<"当前品牌店铺所在的位置为3：\n"
            <<ad.getCountry()<<' '<<ad.getCity()<<'\n';
        //cout<<"333\n";
    }
};

//品牌生产工厂，这里结合了单例模式和工厂模式
class BrandFactory{
public:
    //静态获取函数
    static BrandFactory& getInstance(){
        static BrandFactory instance;
        return instance;
    };

    //pool中有则直接取，无则先创建再取
    SharedBrand* getBrand(const string& brandName){
        if(pool.count(brandName)){//有则直接返回
            cout<<"该品牌已有，已直接获取\n";
            //cout<<"111\n";
            return &pool[brandName];
        }
        else{//无则先创建再返回
            SharedBrand newBrand(brandName);
            pool.insert(map<string,SharedBrand>::value_type(brandName,newBrand));
            cout<<"该品牌暂无，现已成功创建\n";
            //cout<<"222\n";
            return &pool[brandName];
        }
    };
private:
    //私有构造函数，借用单例模式
    BrandFactory()= default;

    map<string,SharedBrand> pool;//储存已有品牌的内存池

};
