#include <iostream>
using namespace std;
class Base{
	public:
		virtual void fun(){
			cout<<"Base fun()"<<endl;
		}
}; 

class D1:public Base{
	public:
		void fun(){
			cout<<"D1 fun()"<<endl;
		}
};

class D2:public Base{
	public:
		void fun(){
			cout<<"D2 fun()"<<endl;
		}
};

int main (void)
{
	Base *pb=new Base();
	pb->fun();
	Base *pb1=new D1();
	pb1->fun();
	Base *pb2=new D2();
	pb2->fun();
	delete pb;
	delete pb1;
	delete pb2;
}
