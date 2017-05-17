#include <iostream>
#include <string.h>
using namespace std;

class M{
	private:
		string name;
	public:
		M(){
			name="��";
		}
		virtual void method()=0;
		virtual ~M(){
			cout<<"����"<<name<<"����������"<<endl; 
		} 
};

class P:public M{
	private:
		string name;
	public:
		P(){
			name="�˽���";
		}
		void method(){
			cout<<"���ǣ�"<<name<<endl; 
		}
};

class J:public M{
	private:
		string name;
	public:
		J(){
			name="��ʯ";
		}
		void method(){
			cout<<"���ǣ�"<<name<<endl; 
		}
};

class W:public M{
	private:
		string name;
		M *base;
	public:		
		W(M *m){
			name="����";
			base=m;
		}
		void method(){
			cout<<"���ǣ�"<<name<<endl;
			base->method(); 
		}
		~W(){
			cout<<"����"<<name<<"������������"<<endl;
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
