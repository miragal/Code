#include <iostream>
#include <vector> 
using namespace std;

class Library;//被访问者 

class Visitor{//访问者 
	public:
		virtual void visit(Library *t)=0;
		~Visitor(){
			cout<<"this is Visitor's xigou."<<endl;
		}
};


class Library{//被访问者 
	public:
		void accept(Visitor *lv){
			lv->visit(this);
		} 
		virtual void fun()=0;
		~Library(){
			cout<<"this is Library's xigou."<<endl;
		}
};


class LibraryVisitor:public Visitor{
	public:
		void visit(Library *t){
			t->fun();
		}
		~LibraryVisitor(){
			cout<<"this is LibraryVisitor's xigou."<<endl;
		}
};

class Book:public Library{
	public:
		void fun(){
			cout<<"this is a book."<<endl;
		}
		~Book(){
			cout<<"this is book's xigou."<<endl;
		}
};

class Article:public Library{
	public:
		void fun(){
			cout<<"this is an article."<<endl;
		}
		~Article(){
			cout<<"this is article's xigou."<<endl;
		}
};


class Manager{
	private:
		vector <Library *> vec;
	public:
		void add(Library *l){
			vec.push_back(l);
		}
		void request(Visitor *pv);
};

void Manager::request(Visitor *pv){
	vector <Library *> :: iterator it;
	for(it=vec.begin();it!=vec.end();it++)
		(*it)->accept(pv); 
}

int main (void)
{
	LibraryVisitor *pl=new LibraryVisitor();
	Manager *pm=new Manager(); 
	Book *pb=new Book();
	Article *pa=new Article();
	pm->add(pb);
	pm->add(pa);
	pm->request(pl);
	delete pa;
	delete pb;
	delete pm;
	delete pl;
	return 0;	
} 
