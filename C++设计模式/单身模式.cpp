#include <iostream>
using namespace std;
class Singleton{
	private:
		int x;
		static Singleton *Instance;
		Singleton(int x){
			this->x=x;
		}
	public:
		static Singleton * Create(){
			if(!Instance)
				Instance=new Singleton(3);
			return Instance;
		}
		void print(){
			cout<<"x="<<x<<endl; 
		}
}; 
Singleton * Singleton::Instance=NULL; 

int main (void)
{
	Singleton *s;
	s=Singleton::Create();
	s->print();
	return 0;
}
