#include <iostream>
using namespace std;
class A{
	private:
		int x,y;
	public:
		A()
		{
			x=0;
			y=0;
			cout<<"A cons1"<<endl;
		}
		A(int x,int y)
		{
			this->x=x;
			this->y=y;
			cout<<"A cons2"<<endl;
		}
		void Print()
		{
			cout<<"x="<<x<<",y="<<y<<endl;
		}
		~A()
		{
			cout<<"A des1"<<endl;
		}
};

class B{
	private:
		A objA;
		int z;
	public:
		B()
		{
			z=0;
			cout<<"B cons2"<<endl; 
		}
		B(int i,int j)
		{
			z=i+j;
			cout<<"B cons1"<<endl;
		}
		void Print()
		{
			objA.Print();
			cout<<"z="<<z<<endl;
		}
		~B()
		{
			cout<<"B des1"<<endl;
		}
};

class C{
	private:
		B objB;
		A objA;
	public:
		C(){
		} 
		C(int i):objA(i+3,i-1){}
		void Print()
		{
			objB.Print();
			objA.Print();
		}
		~C(){
			cout<<"C des"<<endl;
		}
};

int main (void)
{
	B myb(3,5);
	C myc(4);
	myb.Print();
	myc.Print(); 
}
