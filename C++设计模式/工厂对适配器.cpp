#include <iostream>
using namespace std;

class Adapter{
	public:
		virtual void fun()=0;
}; 

class Ad1:public Adapter{
	private:
		int x;
	public:
		Ad1(){
			x=0;
		}
		void fun(){
			cout<<"Ad1's x="<<x<<endl;
		}
};

class Ad2:public Adapter{
	private:
		int x;
	public:
		Ad2(){
			x=1;
		}
		void fun(){
			cout<<"Ad2's x="<<x<<endl;
		}
};

class Factory{
	public:
		virtual Adapter *create()=0;	
};

class Fa:public Factory{
	public:
		Adapter *create(){
			return new Ad1();
		}
};

class Fb:public Factory{
	public:
		Adapter *create(){
			return new Ad2();
		}
};

class Base{
	public:
	virtual void hun()=0;	
};

class A:public Base{
	private:
		Adapter *pa;
		Factory *f;
	public:
		A(Factory *t){
			f=t;
		}
		void hun(){
			pa=f->create();
			pa->fun();
		}
		~A(){
			delete pa;
			delete f;
			cout<<"this is A's xigou."<<endl; 
		}
};

class B:public Base{
	private:
		Adapter *pb;
		Factory *f;
	public:
		B(Factory *t){
			f=t;
		}
		void hun(){
			pb=f->create();
			pb->fun();
		}
		~B(){
			delete pb;
			delete f;
			cout<<"this is B's xigou."<<endl; 
		}
};

int main (void)
{
	Base *pb1=new A(new Fa());
	pb1->hun();
	
	Base *pb2=new B(new Fb());
	pb2->hun();
	
	delete pb1;
	delete pb2;  
	return 0;
}
