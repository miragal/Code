#include <iostream>
#include <D:\C++\A.h>

class B{
	public:
		void fun(A *t){
			cout<<"B's fun()."<<endl;
			t->gun();
		}
};
