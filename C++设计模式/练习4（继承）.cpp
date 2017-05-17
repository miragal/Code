#include <iostream>
using namespace std;
class Base{
	private:int x;
	public:
		Base(){x=0;}
		Base(int x){
			this->x=x;
		}
		void Print(){
			cout<<"x="<<x<<endl;
		}
		~Base(){
			cout<<"Base des"<<endl;
		}
}; 

class Da:public Base{
	private:int y;
	public:
		Da(){y=0;}
		Da(int i,int j):Base(i){
			this->y=j;
		}
		void Print(){
			Base::Print();
			cout<<"y="<<y<<endl;
		}
		~Da(){
			cout<<"Da des"<<endl;
		}	
};

class Db:public Base{
	private:int w;
	public:
		Db(){
			w=0;
		}
		Db(int w){	//省表示不省调用 
			this->w=w;
		}
		void Print(){
			Base::Print();
			cout<<"w="<<w<<endl;
		}
		~Db(){
			cout<<"Db des"<<endl;
		}
};

int main (void)
{
	Da *pda=new Da(3,5);
	Db *pdb=new Db(1);
	pda->Print();
	pdb->Print();
	delete pda;
	delete pdb;	
}
