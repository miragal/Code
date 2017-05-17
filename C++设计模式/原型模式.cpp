#include <iostream>
using namespace std;

class Prototype{
	protected:
		int x,y;
	public:
		virtual Prototype *clone()=0;
		virtual void print()=0;
}; 

class ConcretePrototype:public Prototype{
	public:
		ConcretePrototype(){
			x=0;
			y=0;
		}
		ConcretePrototype(int x,int y){
			this->x=x;
			this->y=y;
		}
		ConcretePrototype(ConcretePrototype &t){
			*this=t;
		} 
		Prototype *clone(){
			return new ConcretePrototype(*this);
		}
		void print(){
			cout<<"x="<<x<<" y="<<y<<endl;
		}
};

int main (void)
{
	Prototype *p=new ConcretePrototype(3,5);
	p->print();
	Prototype *p1=p->clone();
	p1->print();
	delete p;
	return 0;
}
