#pragma once

#ifndef __TOOL_H__
#define __TOOL_H__

#include <iostream>
#include <sstream>
#include <string>


class Page;
class Customer;
class ProxyPatternCustomer;
class AbstractCustomer;
class Shop;
class MainVenue;

using namespace std;

int getNum(string info,int range);
double str2num(string s);

bool chooseExit();
string welcome(bool&);
void testAbstractFactory();
void testBuilder(Shop*);
void testDecorator();
void testFacade();
void testFactory();
void testFilter();
void testFlyWeight();
void testNullObject();
void testObserver();
void testProxy();
void testSingleton();
void testState();
void initial();
void initPage(Page*, Customer*, ProxyPatternCustomer*,AbstractCustomer*);

#endif //__TOOL_H__