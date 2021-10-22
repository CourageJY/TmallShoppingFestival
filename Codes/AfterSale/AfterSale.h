#include<string>
#include"../PersonalInformation/customer.h"

class Order;//预声明

class Comment{
public:

private:
    string content;
    Customer* customer;
};

class AfterSale{
public:

private:
    Order* order;
    Comment comment;

};