#include <iostream>
using namespace std;

class Abstract{
	public:
		void templatedMethod(){
			this->primitivel();
		}
	protected:
		virtual void primitivel()=0;
		virtual void primitive()=0;
}; 

class ConcreteA:public Abstract{
	protected:
		void primitivel(){
			cout<<"A's primitivel."<<endl;
		}
		void primitive(){
			cout<<"A's primitive."<<endl;
		}
};

class ConcreteB:public Abstract{
	protected:
		void primitivel(){
			cout<<"B's primitivel."<<endl;
		}
		void primitive(){
			cout<<"B's primitive."<<endl;
		}
};

int main (void)
{
	Abstract *pa=new ConcreteA();
	pa->templatedMethod();
	delete pa; 
	return 0;
}

