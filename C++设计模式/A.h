#include <iostream>
#include <D:\C++\B.h>

class A{
	public:
		void hun(B *t){
			cout<<"A's hun()."<<endl;
			t->fun(this);
		}
		void gun(){
			cout<<"A's gun()."<<endl;
		}
}; 
