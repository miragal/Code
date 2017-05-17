#include <iostream>
#include <string>
using namespace std;

class Mediator;

class Base{
	protected:
		Mediator *mediator;
	public:
		void set(Mediator *m){
			mediator=m;
		} 
		virtual void send(string msg)=0;
		virtual void show(string msg)=0;
};

class Boy:public Base{
	public:
		void send(string msg);
		void show(string msg);
};

class Girl:public Base{
	public:
		void send(string msg);
		void show(string msg);
};

class Mediator{
	private:
		Base *pb,*pg;
	public:
		void set(Base *b,Base *g){
			pb=b;
			pg=g;
		} 
		void send(string msg,Base *t){
			if(t!=pg)
				pg->show(msg);
			else pb->show(msg);
		}
};


void Boy::send(string msg){
	cout<<"男孩发出信息：";
	mediator->send(msg,this);
}

void Boy::show(string msg){
	cout<<msg<<endl;
	cout<<"男孩收到信息。"<<endl;
}

void Girl::send(string msg){
	cout<<"女孩发出信息：";
	mediator->send(msg,this);
}

void Girl::show(string msg){
	cout<<msg<<endl;
	cout<<"女孩收到信息。"<<endl;
	
}

int main (void)
{
	Mediator *m=new Mediator();
	Boy *boy=new Boy();
	Girl *girl=new Girl();
	boy->set(m);
	girl->set(m);
	m->set(boy,girl);
	boy->send("hi girl!");
	girl->send("hi boy!");
	boy->send("nice to meet you"); 
	return 0;
	
}
