#include <iostream> 
using namespace std;

class Base{
	private:
		int x,y;
	public:
		Base(){
			x=0;
			y=0;
			cout<<"Base's �޲ι��캯����"<<endl;
		}
		Base(int x,int y){
			this->x=x;
			this->y=y;
			cout<<"Base's ���ι��캯����"<<endl;
		}
		//���麯��
		virtual void fun()=0;
		//����������
		virtual ~Base(){
			cout<<"Base's ��������."<<endl; 
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
			cout<<"D's ���ι��캯����"<<endl;
		}
		void fun(){
			print();
			cout<<"z="<<z<<endl;
		}
		~D(){
			cout<<"D's ��������."<<endl; 
		}
};

class My{
	private:
		Base *b;
	public:
		My(Base *t){
			cout<<"My's ���ι��캯����"<<endl;
			b=t;
		}
		void dofun(){
			b->fun();
		}
		~My(){
			cout<<"My's ����������"<<endl;
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
