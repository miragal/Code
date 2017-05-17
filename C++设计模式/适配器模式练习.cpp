#include <iostream>
#include <string.h>
using namespace std;

class App{
	protected:
		string name;
	public:
		App(){
			name="App";
		} 
		virtual void method()=0;
		virtual ~App(){
			cout<<"这是App的虚析构。"<<endl; 
		}
};

//适配器 
class Adaptee{
	private:
		App *f;
	public:
		Adaptee(App *t){
			f=t;
		}
		void dofun(){
			f->method();
		}
		~Adaptee(){
			delete f;
			cout<<"这是Apadtee的析构。"<<endl;
		}
}; 


//中国插座 
class CS{
	private:
		Adaptee *pa;
	public:
		CS(Adaptee * t){
			pa=t;
		}
		void fun(){
			pa->dofun();
		}
		~CS(){
			delete pa;
			cout<<"这是中国插座的析构。"<<endl;
		}
		
};


//中国电器 
class Capp:public App{
	private:
		CS *pc;
	public:
		Capp(CS *t){
			pc=t;
			name="中国电器"; 
		} 
		void method(){
			pc->fun();
		}
		~Capp(){
			delete pc;
			cout<<"这是"<<name<<"的析构。"<<endl;
		}
};

//外国电器 
class Fapp:public App{
	public:
		Fapp(string n){
			name=n;
		} 
		void method(){
			cout<<"这是"<<name<<"的使用。"<<endl; 
		}
		~Fapp(){
			cout<<"这是"<<name<<"的析构。"<<endl;
		}
};

int main(void)
{
	App *pa=new Capp(new CS(new Adaptee(new Fapp("外国电器"))));
	pa->method();
	delete pa;
	return 0;	
} 
