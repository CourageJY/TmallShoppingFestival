#include"Comment.h"
#include"iostream"
#include"../AfterSale/makeComment.h"

string Comment::priceComment(){
        string result="";
        int choice=-1;
        diffAspect* pri=new price();
        cout<<"is price good or bad?"<<endl;
        cout<<"0.good"<<"\t"<<"1.bad"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 0:
        {
            goodOrBad* com1=new goodComment(pri);
            result+=com1->makeTotalComment();
        }
            break;
        case 1:
        {
            goodOrBad* com2=new badComment(pri);
            result+=com2->makeTotalComment();
        }
            break;
        default:
            break;
        }
        return result;
}

string Comment::logisticsComment(){
        string result="";
        int choice=-1;
        diffAspect* logis=new logistics();
        cout<<"is logistics good or bad?"<<endl;
        cout<<"0.good"<<"\t"<<"1.bad"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 0:
        {
            goodOrBad* com1=new goodComment(logis);
            result+=com1->makeTotalComment();
        }
            break;
        case 1:
        {
            goodOrBad* com2=new badComment(logis);
            result+=com2->makeTotalComment();
        }
            break;
        default:
            break;
        }
        return result;
}

string Comment::serviceComment(){
    string result="";
    int choice=-1;
    diffAspect* ser=new service();
    cout<<"is service good or bad?"<<endl;
    cout<<"0.good"<<"\t"<<"1.bad"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 0:
    {
        goodOrBad* com1=new goodComment(ser);
        result+=com1->makeTotalComment();
    }
        break;
    case 1:
    {
        goodOrBad* com2=new badComment(ser);
        result+=com2->makeTotalComment();
    }
        break;
    default:
        break;
    }
    return result;
}