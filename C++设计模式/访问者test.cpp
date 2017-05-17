#include <iostream>
using namespace std;

class Your;

class My{
	private:
		Your *your;
	public:
		My(Your *t);
		void fun(); 
		void dofun();
};

class Your{
	public:
		void Notify(My *t);
};

My::My(Your *t){
	this->your=t;
}

void  My::fun(){
	this->your->Notify(this);
}

void My::dofun(){
	cout<<"this is my's dofun."<<endl;
}

void Your::Notify(My *t){
	t->dofun();
}

int main (void)
{
	Your *your=new Your();
	My *my=new My(your);
	my->fun();
	delete your;
	delete my;
	return 0;	
} 
