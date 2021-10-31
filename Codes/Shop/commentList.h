#pragma once
#include"../PersonalInformation/Comment.h"
#include<vector>
#include<iostream>

using namespace std;

class Iterator{

    virtual Comment* first()=0;

    virtual Comment* next()=0;

    virtual bool hasNext()=0;
};

// class Aggregate{

//     Iterator getIterator();
// };

class commentsListIterator:public Iterator{
private:
    vector<Comment*> commentsList;
    int index;
public:
    commentsListIterator(){}
    commentsListIterator(vector<Comment*> commentslist){
        commentsList=commentslist;
    }
    Comment* first(){
        if(!commentsList.empty()){
            return commentsList[0];
        }
        else 
            return nullptr;
    }
    Comment* next(){
        if(hasNext()){
            return commentsList[++index];
        }
    }
    bool hasNext(){
        return index<commentsList.size()-1;
    }

};