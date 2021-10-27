#pragma once
#include <string>
#include <PersonalInformation/Comment.h>
#include <Shop/shop.h>
using namespace std;

//店铺用中介者类来接收评价，用户不需要调用店铺
class Mediator
{
public:
	Mediator(Shop* sh) :shop(sh) {}

	void sendComment(Comment* comment) { shop->receiverComment(comment); }

private:
	Shop* shop;
};
