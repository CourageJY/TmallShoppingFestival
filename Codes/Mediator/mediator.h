#pragma once
#include <string>
#include "../PersonalInformation/Comment.h"
#include "../Shop/shop.h"
using namespace std;

//用户通过调用中介者向店铺发送评价，不需要显式调用店铺
class Mediator
{
public:
	Mediator(Shop* sh) :shop(sh) {}

	void sendComment(Comment* comment) { shop->receiveComment(comment); }

private:
	Shop* shop;
};
