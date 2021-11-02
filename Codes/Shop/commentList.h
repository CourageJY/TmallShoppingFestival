#pragma once
#include"../PersonalInformation/Comment.h"
#include<vector>
#include<iostream>

using namespace std;

class Iterator {

public:
    virtual Comment* first() = 0;

    virtual Comment* next() = 0;

    virtual bool hasNext() = 0;
};


class commentsListIterator :public Iterator {
private:
    vector<Comment*> commentsList;
    int index;
public:
    commentsListIterator() {}
    commentsListIterator(vector<Comment*> commentslist) {
        commentsList = commentslist;
    }
    Comment* first() {
        if (!commentsList.empty()) {
            return commentsList[0];
        }
        else
            return nullptr;
    }
    Comment* next() {
        if (hasNext()) {
            return commentsList[++index];
        }
    }
    bool hasNext() {
        return index < commentsList.size() - 1;
    }

};

class Aggregate {

public:
    virtual void add(Comment* cm) = 0;
    virtual commentsListIterator* getIterator()=0;
};


class ConcreteAggregate :public Aggregate {
private:
    vector<Comment*>* commentsList;
public:
    ConcreteAggregate(){
        vector<Comment*>* cm=new vector<Comment*>();
        commentsList=cm;
    }
    void add(Comment* cm) {
        commentsList->push_back(cm);
    }
    int getLength(){
        return commentsList->size();
    }
    commentsListIterator* getIterator() {
        commentsListIterator* cmlt= new commentsListIterator(*commentsList);
        return cmlt;
    }
};