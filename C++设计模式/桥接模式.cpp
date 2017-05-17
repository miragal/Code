#include <iostream>
using namespace std;

class AbstractionImp{
	public:
		virtual void Operation()=0;
		virtual ~AbstractionImp(){
			cout<<"AbstractionImp's xigou."<<endl;
		} 
}; 

class ConcreteA:public AbstractionImp{
	public:
		void Operation(){
			cout<<"ConcreteA's Operation."<<endl; 
		}
		~ConcreteA(){
			cout<<"ConcreteA's xigou."<<endl; 
		}
};

class ConcreteB:public AbstractionImp{
	public:
		void Operation(){
			cout<<"ConcreteB's Operation."<<endl; 
		}
		~ConcreteB(){
			cout<<"ConcreteB's xigou."<<endl; 
		}
};

class Abstraction{
	private:
		AbstractionImp *pb;
	public:
		Abstraction(AbstractionImp *t){
			pb=t;
		}
		virtual void Operation(){
			pb->Operation();
		}
		~Abstraction(){
			delete pb;
			cout<<"Abstraction's xigou."<<endl;
		}
};

class DefinedAbstractionA:public Abstraction{
	public:
		DefinedAbstractionA(AbstractionImp *t):Abstraction(t){}
		~DefinedAbstractionA(){
			cout<<"DefinedAbstractionA's xigou."<<endl;
		}
}; 

class DefinedAbstractionB:public Abstraction{
	public:
		DefinedAbstractionB(AbstractionImp *t):Abstraction(t){}
		~DefinedAbstractionB(){
			cout<<"DefinedAbstractionB's xigou."<<endl;
		}
}; 

int main (void)
{
	Abstraction *p=new DefinedAbstractionA(new ConcreteB());
	p->Operation();
	delete p;
	return 0;
}
