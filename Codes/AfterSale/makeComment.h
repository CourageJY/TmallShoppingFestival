#pragma once
#include<string>
#include<iostream>

using namespace std;

class diffAspect{
public:
    virtual string selectAspect()=0;
};

class price:public diffAspect{
public:
    string selectAspect(){
        return "价格";
    }
};

class logistics:public diffAspect{
public:
    string selectAspect(){
        return "物流";
    }
};

class service:public diffAspect{
public:
    string selectAspect(){
        return "服务";
    }
};

class goodOrBad{
public:
    virtual string makeTotalComment()=0;

};
class goodComment:public goodOrBad{
public:
    goodComment(diffAspect* diff){
        _diff=diff;
    }
    string makeTotalComment(){
        string s="满意";
        return _diff->selectAspect().c_str()+s;
    }
private:
    diffAspect* _diff;
};

class badComment:public goodOrBad{
public:
    badComment(diffAspect* diff){
        _diff=diff;
    }
    string makeTotalComment(){
        string s="不满意";
        return _diff->selectAspect().c_str()+s;
    }

private:
    diffAspect* _diff;
};

class test{

};




