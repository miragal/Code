#include <iostream> 
using namespace std;

class Base{
	private:
		int x,y;
	public:
		Base(){
			x=0;
			y=0;
			cout<<"Base's 无参构造函数。"<<endl;
		}
		Base(int x,int y){
			this->x=x;
			this->y=y;
			cout<<"Base's 带参构造函数。"<<endl;
		}
		//纯虚函数
		virtual void fun()=0;
		//虚析构函数
		virtual ~Base(){
			cout<<"Base's 析构函数."<<endl; 
		} 
		void print(){
			cout<<"x="<<x<<",y="<<y<<endl;
		}
};

class D:public Base{
	private:
		int z;
	public:
		D():Base(){
			z=0;
		}
		D(int x):Base(x+1,x-1){
			z=x;
			cout<<"D's 带参构造函数。"<<endl;
		}
		void fun(){
			print();
			cout<<"z="<<z<<endl;
		}
		~D(){
			cout<<"D's 析构函数."<<endl; 
		}
};

class My{
	private:
		Base *b;
	public:
		My(Base *t){
			cout<<"My's 带参构造函数。"<<endl;
			b=t;
		}
		void dofun(){
			b->fun();
		}
		~My(){
			cout<<"My's 析构函数。"<<endl;
		}
};

int main (void)
{
	D *d=new D(2);
	My *my=new My(d);
	my->dofun();
	delete d;
	delete my; 
	return 0; 
}
