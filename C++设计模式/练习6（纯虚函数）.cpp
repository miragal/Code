#include <iostream>
using namespace std;
class Base{
	public:
		virtual void fun()=0;	//´¿Ðéº¯Êý 
};

class My{
	private:
		Base *pb;
	public:
		My(Base *t){
			pb=t;
		}
		void do(){
			pb->fun();
			//cout<<"my do()"<<endl; 
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

int main(void)
{
	/*Base *pb=new D1();
	pb->fun();
	*/
	D2 *d2=new D2;
	My *pm=new My(d2);
	pm->do();	
} 
