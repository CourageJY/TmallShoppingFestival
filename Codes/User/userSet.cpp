#include "user.h"
using namespace std;

//设定用户，设定一个规则，规定用户只能是user1和user2
Expression* setUsers()
{
    Expression* user1 = new TerminalExpression("user1");
    Expression* user2 = new TerminalExpression("user2");
    return new OrExpression(user1, user2);
}