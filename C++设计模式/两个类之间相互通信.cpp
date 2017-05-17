#include <iostream>
using namespace std;

class B; 

class A{
	public:
		void hun(B *t);
		void gun(){
			cout<<"A's gun()."<<endl;
		}
}; 

class B{
	public:
		void fun(A *t){
			cout<<"B's fun()."<<endl;
			t->gun();
		}
};

void A::hun(B *t){
			cout<<"A's hun()."<<endl;
			t->fun(this);
		}

int main(void)
{
	A *a=new A();
	B *b=new B();
	a->hun(b);
	delete a;
	delete b;
	return 0;
}
