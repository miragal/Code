#include <iostream>
using namespace std;

class TakeoffBehavior{
	public:
		virtual void takeoff()=0;
};

class Vertical:public TakeoffBehavior{
	public:
		void takeoff(){
			cout<<"Vertical's takeoff."<<endl;
		}
};

class LongDistance:public TakeoffBehavior{
	public:
		void takeoff(){
			cout<<"LongDistance's takeoff."<<endl;
		}
};

class FlyBehavior{
	public:
		virtual void fly()=0;
};

class SubSonic:public FlyBehavior{
	public:
		void fly(){
			cout<<"SubSonic's fly."<<endl;
		}
};

class SuperSonic:public FlyBehavior{
	public:
		void fly(){
			cout<<"SuperSonic's fly."<<endl;
		}
};

class Plane{
	private:
		TakeoffBehavior *t;
		FlyBehavior *f;
	public:
		Plane(TakeoffBehavior *t,FlyBehavior *f){
			this->t=t;
			this->f=f;
		}
		virtual void fly(){
			f->fly();
		}
		virtual void takeoff(){
			t->takeoff();
		}
		virtual ~Plane(){
			delete t;
			delete f;
			cout<<"this is Plane's xigou."<<endl;
		}
};

class Helicopter:public Plane{
	public:
		Helicopter(TakeoffBehavior *t,FlyBehavior *f):Plane(t,f){}
//		void fly(){
//			f->fly(); 
//		}
//		void takeoff(){
//			t->takeoff();
//		}
		~Helicopter(){
			cout<<"this is Helicopter's xigou."<<endl;
		}
};

int main (void)
{
	Vertical *v=new Vertical();
	SubSonic *s=new SubSonic();
	Plane *p=new Helicopter(v,s);
	p->takeoff();
	p->fly();
	delete p;
	return 0;
}


