#include<iostream>

class checkOrder{
    private:
    orderState* current;
    int ordertype;
    Customer* customer;
    public:
    checkOrder(int or,Customer* c):ordertype(or),customer(c),current(NULL){}
    void setState(orderState* o){
        current=o;
    }
    void showinformation(){
        current->showorderinformation(this);
    }
    int getordertype(){return ordertype;}
    Customer* getcustomer(){return customer;}
};

class orderState
{
public:
	virtual void showorderinformation(checkOrder* ck)=0;
};

class unpaidState:public orderState
{
public:
	void showorderinformation(checkOrder* ck)
	{
		vector<Order> vec;
		vector<Order> orders=ck->getcustomer()->getOrders();
		string str="待支付的";
		if (ck->getordertype()==1){
            for(auto od:orders){
              if(od.getState()==0){//获取对应状态的order
                vec.push_back(od);
			  }
			}
            cout<<"您查看的"+str+"订单共"<<vec.size()<<"个，分别为:\n";
            int i=1;
    		for(auto v:vec){
        	cout<<i<<".";
        	v.showOrder();
        	i++;
	        }
        }    
		else{
			ck->setState(new paidState);ck->showinformation();
		}
    
    }
};

class paidState:public orderState
{
public:
	void showorderinformation(checkOrder* ck)
	{
		vector<Order> vec;
		vector<Order> orders=ck->getcustomer()->getOrders();
		string str="已支付的";
		if (ck->getordertype()==2){
            for(auto od:orders){
              if(od.getState()==1){//获取对应状态的order
                vec.push_back(od);
			  }
			}
            cout<<"您查看的"+str+"订单共"<<vec.size()<<"个，分别为:\n";
            int i=1;
    		for(auto v:vec){
        	cout<<i<<".";
        	v.showOrder();
        	i++;
	        }
		}
		else{
			ck->setState(new paidState);ck->showinformation();
		}
	}
};

class errorState:public orderState
{
public:
	void showorderinformation(checkOrder* ck)
	{
		vector<Order> vec;
		vector<Order> orders=ck->getcustomer()->getOrders();
		string str="已支付的";
		if (ck->getordertype()==3){
            for(auto od:orders){
              if(od.getState()==2){//获取对应状态的order
                vec.push_back(od);
			  }
			}
            cout<<"您查看的"+str+"订单共"<<vec.size()<<"个，分别为:\n";
            int i=1;
    		for(auto v:vec){
        	cout<<i<<".";
        	v.showOrder();
        	i++;
	        }    
		}
		else{
			ck->setState(new paidState);ck->showinformation();
		}
	}
};