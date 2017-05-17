#include <iostream>
using namespace std;
class A{
	private:
		int x;
		A *next;
	public:
		A():x(0){}
		A(int x){
			this->x=x;
		}
		void set(A *b){
			next=b;
		}
		void Print(){
			A *p;
			p=this;
			while(p){
				cout<<p->x<<endl;
				p=p->next; 
			}
		} 
}; 

int main (void)
{
	A *p,*h=NULL;
	int i,x;
	for(i=0;i<3;i++){
		cin>>x;
		p=new A(x);
		p->set(h);
		h=p;
	}
	h->Print();
	return 0;
}
