#include <iostream>
using namespace std;

class Base{
	private:
		int x;
	public:
		Base(){
			x=0;
		}
		virtual void method()=0;
		virtual ~Base(){
			cout<<"Base's xigou."<<endl;
		}
};

class Source:public Base{
	private:
		int x;
	public:
		Source(){
			x=1;
		}
		void method(){
			cout<<"Source x="<<x<<endl;
		}
};

class Proxy:public Base{
	private:
		Base *pb;
	public:
		Proxy(Base *t){
			pb=t;
		}
		void method(){
			pb->method();
		}
		~Proxy(){
			delete pb;
			cout<<"Proxy's xigou."<<endl;
		}
};

int main(void)
{
	Proxy *pp=new Proxy(new Source());
	pp->method();
	delete pp;
	return 0;
}
