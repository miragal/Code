#include <iostream>
using namespace std;
class AdapterBase{
	private:
		int x;
	public:
		AdapterBase(){
			x=0;
		}
		virtual void method()=0;
		virtual ~AdapterBase(){
			cout<<"AdapterBase's xigou."<<endl;
		} 
}; 


class Adaptee{
	private:
		int x;
	public:
		Adaptee(){
			x=2;
		}
		void method(){
			cout<<"Adaptee x="<<x<<endl;
		}
};

class AdapterA:public AdapterBase{
	private:
		int x;
	public:
		AdapterA(){
			x=1;
		}
		void method(){
			cout<<"A x="<<x<<endl;
		}
};

class AdapterB:public AdapterBase{
	private:
		Adaptee *ptee;
	public:
		AdapterB(){
			ptee=new Adaptee();
		}
		void method(){
			ptee->method();
		}
		~AdapterB(){
			delete ptee;
			cout<<"B's xigou."<<endl;
		}
};

int main(void)
{
	AdapterBase *pa=new AdapterB();
	pa->method();
	delete pa;
	return 0;
}

