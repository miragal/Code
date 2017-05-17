#include <iostream>
#include <string.h>
using namespace std;

class Cal{
	protected: 
		double a,b;
		char c;
	public:
		virtual void method()=0;
};

class Add:public Cal{
	public:
		Add(double a,char c,double b){
			this->a=a;
			this->c=c;
			this->b=b;
		}
		void method(){
			cout<<a<<""<<c<<""<<b<<"="<<(a+b)<<endl; 
		}
};

class Del:public Cal{
	public:
		Del(double a,char c,double b){
			this->a=a;
			this->c=c;
			this->b=b;
		}
		void method(){
			cout<<a<<""<<c<<""<<b<<"="<<(a-b)<<endl; 
		}
};

class Mul:public Cal{
	public:
		Mul(double a,char c,double b){
			this->a=a;
			this->c=c;
			this->b=b;
		}
		void method(){
			cout<<a<<""<<c<<""<<b<<"="<<(a*b)<<endl; 
		}
};

class Div:public Cal{
	public:
		Div(double a,char c,double b){
			this->a=a;
			this->c=c;
			this->b=b;
		}
		void method(){
			cout<<a<<""<<c<<""<<b<<"="<<(a/b)<<endl; 
		}
};

class Do{
	private:
		Cal *p;
	public:
		Do(double a,char c,double b){
			switch(c){
				case '+':p=new Add(a,c,b);break;
				case '-':p=new Del(a,c,b);break;
				case '*':p=new Mul(a,c,b);break;
				case '/':p=new Div(a,c,b);break;
			}
		}
		void fun(){
			p->method();
		}
		~Do(){
			cout<<"Do's 析构。"<<endl;
			delete p; 
		}
};

int main (void)
{
	int a,b;
	char c;
	cout<<"请输入一个算式:"<<endl;
	cin>>a>>c>>b; 
	Do *pd=new Do(a,c,b);
	pd->fun();
	delete pd;
	return 0;
}
