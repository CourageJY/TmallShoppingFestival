#pragma once
#include"../PersonalInformation/Comment.h"
#include<vector>
#include<iostream>

using namespace std;

class Iterator{

    Comment* first();

    Comment* next();

    virtual bool hasNext();
};

// class Aggregate{

//     Iterator getIterator();
// };

class goodsListIterator:public Iterator{
private:
    vector<Comment*> commentsList;
    vector<Comment*>::iterator it;
public:
    goodsListIterator(){
        commentsList.clear();
    }
    goodsListIterator(vector<Comment*> commentslist){
        commentsList=commentslist;
    }
    Comment* first(){
        if(!commentsList.empty()){
            it=commentsList.begin();
            return commentsList[0];
        }
    }
    Comment* next(){
        if(hasNext()){
            return *(++it);
        }
    }
    bool hasNext(){
        if(it==commentsList.end()||it==commentsList.end()--||it==commentsList.end()-2){
            return false;
        }
        return true;
    }
    void addComments(Comment* comment){
        commentsList.push_back(comment);
    }

};