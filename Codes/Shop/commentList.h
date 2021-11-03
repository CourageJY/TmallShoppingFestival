#pragma once
#include"../PersonalInformation/Comment.h"
#include<vector>
#include<iostream>

using namespace std;

//抽象类Iterator
class Iterator {
public:
    virtual Comment* first() = 0;
    virtual Comment* next() = 0;
    virtual bool hasNext() = 0;
};

//迭代器的实现
class commentsListIterator :public Iterator {
private:
    vector<Comment*>* commentsList;
    int index;
public:
    commentsListIterator() {}
    commentsListIterator(vector<Comment*>* commentslist) {
        commentsList = commentslist;
    }
    Comment* first() {
        index=0;
        if (!commentsList->empty()) {
            return commentsList->at(index);
        }
        else
            return nullptr;
    }
    Comment* next() {
        if (hasNext()) {
            return commentsList->at(++index);
        }
        return nullptr;
    }
    bool hasNext() {
        return index < commentsList->size() - 1;
    }
    vector<Comment*>* getVector(){
        return commentsList;
    }

};

//抽象类存储容器
class Aggregate {
public:
    virtual void add(Comment* cm) = 0;
    virtual commentsListIterator* getIterator()=0;
};

//存储容器的实现
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
        commentsListIterator* cmlt= new commentsListIterator(commentsList);
        return cmlt;
    }
};