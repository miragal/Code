#include <iostream>
using namespace std;

class A{
	private:
		A *next;
		int x;
	public:
		A(){
			x=0;
			this->next=NULL;
		}
		A(A *t,int x){
			this->next=t;
			this->x=x;
		}
		virtual void fun()=0;
		void hun(){
			cout<<"x="<<x<<endl;
			if(next)
				next->fun();
		}
};

class A1:public A{
	public:
		A1(){
		} 
		A1(A *t,int x):A(t,x){
		}
		void fun(){
			cout<<"A1 ";
			hun(); 
		}
};

class A2:public A{
	public:
		A2(){
		} 
		A2(A *t,int x):A(t,x){
		}
		void fun(){
			cout<<"A2 ";
			hun(); 
		}
};

class A3:public A{
	public:
		A3(){
		} 
		A3(A *t,int x):A(t,x){
		}
		void fun(){
			cout<<"A3 ";
			hun(); 
		}
};

int main(void)
{
	A3 *p3=new A3();
	A2 *p2=new A2(p3,3);
	A *p1=new A1(p2,5);
	p1->fun();
	delete p3;
	delete p2;
	delete p1;
	return 0;	
} 
