#include <iostream>
using namespace std;
class A{
	private:
		int x;
	public:
		A():x(0){}
		A(int x){
			this->x=x;
		}
		void Fun(){
			cout<<x<<endl;
		}
};

class B{
	private:
		int y;
	public:
		B():y(0){}
		B(int y){
			this->y=y;
		}
		void Hun(){
			cout<<y<<endl;
		}
};

class C{
	private:
		int z;
	public:
		C():z(0){}
		C(int z){
			this->z=z;
		}
		void Gun(){
			cout<<z<<endl;
		}
};

class My{
	private:
		A *pa;
		B *pb;
		C *pc;
	public:
		My(){
			pa=new A();
			pb=new B();
			pc=new C();
		}
		My(int x,int y,int z){
			pa=new A(x);
			pb=new B(y);
			pc=new C(z);
		}
		void Do(){
			pa->Fun();
			pb->Hun();
			pc->Gun();
		}
		~My(){
			delete pa;
			delete pb;
			delete pc;
		}
};

int main (void)
{
	My *p=new My(3,5,0);
	p->Do();
	delete p;
	return 0;
}
