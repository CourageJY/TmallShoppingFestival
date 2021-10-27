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
        return "price";
    }
};

class logistics:public diffAspect{
public:
    string selectAspect(){
        return "logistics";
    }
};

class service:public diffAspect{
public:
    string selectAspect(){
        return "service";
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
        string s=" is good";
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
        string s=" is bad";
        return _diff->selectAspect().c_str()+s;
    }

private:
    diffAspect* _diff;
};

class test{

};




