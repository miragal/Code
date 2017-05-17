#include <iostream>
using namespace std; 
class A{
	public:
	virtual void fun()=0;
};

class A1:public A{
	public:
	void fun(){
		cout<<"A1"<<endl;
	}
};


class A2:public A{
	public:
	void fun(){
		cout<<"A2"<<endl;
	}
};

class My{
	private :
		A *pa;
	public:
		My(A *t){
			pa=t;
		}
		void dofun(){
			pa->fun(); 
		}
};

int main(void)
{
	My *m=new My(new A2());
	m->dofun();	
} 
