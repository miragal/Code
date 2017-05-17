#include <iostream>
#include <vector>
using namespace std; 


class Subject;

class Observer{
	private: 
		Subject *s; 
	public:
		Observer(Subject *s){
			this->s=s;
			//s->add(this);
		}
		virtual void Updata(int x,int y)=0;
		//virtual ~Observer()=0;
}; 

class ObserverA:public Observer{
	private:
		int x,y;
	public:
		ObserverA(Subject *s):Observer(s){
			x=y=0;
		}
		void Updata(int x,int y){
			this->x=x;
			this->y=y;
		}
		~ObserverA(){
			cout<<"ObserverA's xigou."<<endl;
		}
};


class Subject{
	protected:
		vector <Observer *> vec;
	public:
		virtual void Notify()=0;
		virtual void print()=0;
};


class ConcreteA:public Subject{
	private:
		int x,y;
	public:
		ConcreteA(){
			x=0;
			y=0;
		}
		ConcreteA(int x,int y){
			this->x=x;
			this->y=y;
		}
		void Add(Observer *t){
			vec.push_back(t);
		} 
		void Notify(){
			vector <Observer *>:: iterator it;
			for(it=vec.begin();it!=vec.end();it++)
				(*it)->Updata(x,y);
		}
		void DataChange(int x,int y){
			this->x=x;
			this->y=y;
			Notify();
		}
		void print(){
			cout<<"x="<<x<<" y="<<y<<endl;
		}
};

int main (void)
{
	ConcreteA *s=new ConcreteA();
	ObserverA *ob1=new ObserverA(s);
	ObserverA *ob2=new ObserverA(s);
	s->print();
	s->DataChange(3,5);
	s->print();
	delete ob2;
	delete ob1;
	delete s;
	return 0;
}
