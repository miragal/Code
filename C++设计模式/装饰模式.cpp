#include <iostream>
using namespace std;

class Base{
	protected:
		Base *next;
	public:
		virtual void fun()=0;
};

class A1:public Base{
	public:
		A1(){
			next=NULL;
		}
		A1(Base *t){
			next=t;
		}
		void fun(){
			if(next)
				next->fun();	
		}
		~A1(){
			cout<<"A1'S 析构。"<<endl;
		}
};
class A2:public Base{
	public:
		A2(){
			next=NULL;
		}
		A2(Base *t){
			next=t;
		}
		void fun(){
			if(next)
				next->fun();	
		}
		~A2(){
			cout<<"A2'S 析构。"<<endl;
		}
};

class Decorate:public Base{
	public:
		virtual void fun()=0;
};

class D1:public Decorate{
	public:
		D1(){
			next=NULL;
		}
		D1(Base *t){
			next=t;
		}
		void fun(){
			if(next){
				next->fun();
			}
		}
		~D1(){
			cout<<"D1'S 析构。"<<endl;
		}
};

class D2:public Decorate{
	public:
		D2(){
			next=NULL;
		}
		D2(Base *t){
			next=t;
		}
		void fun(){
			if(next){
				next->fun();
			}
		}	
		~D2(){
			cout<<"D2'S 析构。"<<endl;
		}
};

class D3:public Decorate{
	public:
		D3(){
			next=NULL;
		}
		D3(Base *t){
			next=t;
		}
		void fun(){
			if(next){
				next->fun();
			}
		}
		~D3(){
			cout<<"D3'S 析构。"<<endl;
		}
};

class My{
	private:
		Base *t;
	public:
		My(Base *t){
			this->t=t;
		}
		void dofun(){
			t->fun();
		}
		~My(){
			cout<<"My'S 析构。"<<endl;
		}
};

int main (void)
{
	D3 *d3=new D3();
	D1 *d1=new D1(d3);
	A1 *a=new A1(d1);
	My *my=new My(a);
	my->dofun();
	delete d3;
	delete d1;
	delete a;
	delete my;
	return 0;
}
