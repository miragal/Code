#include <iostream>
#include <vector>
using namespace std; 

class Observer{
	private:
		int x,y;
	public:
		void Updata(int x,int y){
			this->x=x;
			this->y=y;
		}
};

class Subject{
	private:
		int x,y;
		vector <Observer *> vec;
	public:
		Subject(){
			x=0;
			y=0;
			Notify();
		}
		Subject(int x,int y){
			this->x=x;
			this->y=y;
			Notify();
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
	Subject *s=new Subject();
	Observer *ob1=new Observer();
	Observer *ob2=new Observer();
	s->Add(ob1);
	s->Add(ob2);
	s->print();
	s->DataChange(3,5);
	s->print();
	return 0;
}
