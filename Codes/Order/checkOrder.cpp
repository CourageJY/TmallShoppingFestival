#include "checkOrder.h"
void checkOrder::setState(orderState* o){
    current=o;
}
void checkOrder::showInformation(){
    current->showOrderInformation(this);
}

