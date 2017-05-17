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
			cout<<"����App����������"<<endl; 
		}
};

//������ 
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
			cout<<"����Apadtee��������"<<endl;
		}
}; 


//�й����� 
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
			cout<<"�����й�������������"<<endl;
		}
		
};


//�й����� 
class Capp:public App{
	private:
		CS *pc;
	public:
		Capp(CS *t){
			pc=t;
			name="�й�����"; 
		} 
		void method(){
			pc->fun();
		}
		~Capp(){
			delete pc;
			cout<<"����"<<name<<"��������"<<endl;
		}
};

//������� 
class Fapp:public App{
	public:
		Fapp(string n){
			name=n;
		} 
		void method(){
			cout<<"����"<<name<<"��ʹ�á�"<<endl; 
		}
		~Fapp(){
			cout<<"����"<<name<<"��������"<<endl;
		}
};

int main(void)
{
	App *pa=new Capp(new CS(new Adaptee(new Fapp("�������"))));
	pa->method();
	delete pa;
	return 0;	
} 
