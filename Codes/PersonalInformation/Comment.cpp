#include"Comment.h"
#include"iostream"

//评论价格的实现
string Comment::priceComment(){
        string result="";
        int choice=-1;
        diffAspect* pri=new price();
        cout<<"价格是否令您满意？"<<endl;
        cout<<"0.满意"<<"\t"<<"1.不满意"<<endl;
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
//评论物流的实现
string Comment::logisticsComment(){
        string result="";
        int choice=-1;
        diffAspect* logis=new logistics();
        cout<<"物流是否令您满意？"<<endl;
        cout<<"0.满意"<<"\t"<<"1.不满意"<<endl;
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
//评论服务的实现
string Comment::serviceComment(){
    string result="";
    int choice=-1;
    diffAspect* ser=new service();
    cout<<"服务是否令您满意?"<<endl;
    cout<<"0.满意"<<"\t"<<"1.不满意"<<endl;
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