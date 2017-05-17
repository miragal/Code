#include <iostream>
#include <string.h>
using namespace std;

class M{
	private:
		string name;
	public:
		M(){
			name="人";
		}
		virtual void method()=0;
		virtual ~M(){
			cout<<"这是"<<name<<"的虚析构。"<<endl; 
		} 
};

class P:public M{
	private:
		string name;
	public:
		P(){
			name="潘金莲";
		}
		void method(){
			cout<<"这是："<<name<<endl; 
		}
};

class J:public M{
	private:
		string name;
	public:
		J(){
			name="贾石";
		}
		void method(){
			cout<<"这是："<<name<<endl; 
		}
};

class W:public M{
	private:
		string name;
		M *base;
	public:		
		W(M *m){
			name="王婆";
			base=m;
		}
		void method(){
			cout<<"这是："<<name<<endl;
			base->method(); 
		}
		~W(){
			cout<<"这是"<<name<<"的析构函数。"<<endl;
			delete base; 
		}
		
};

int main (void)
{
	W *w=new W(new ());
	w->method();
	delete w;
	return 0;
}
