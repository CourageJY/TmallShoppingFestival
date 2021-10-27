#pragma once
#include <string>
#include "../PersonalInformation/Comment.h"
#include "../Shop/shop.h"
using namespace std;

//�������н��������������ۣ��û�����Ҫ���õ���
class Mediator
{
public:
	Mediator(Shop* sh) :shop(sh) {}

	void sendComment(Comment* comment) { shop->receiverComment(comment); }

private:
	Shop* shop;
};
