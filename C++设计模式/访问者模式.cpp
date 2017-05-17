#include <iostream>
#include <vector> 
using namespace std;

class LibraryVisitor;

class LibraryInterface{
	public:
		virtual void accept(LibraryVisitor *lv)=0;
		virtual void fun()=0;
		~LibraryInterface(){
			cout<<"this is LibraryInterface's xigou."<<endl;
		}
};

class Book:public LibraryInterface{
	public:
		void accept(LibraryVisitor *lv);
		void fun(){
			cout<<"this is a book."<<endl;
		}
		~Book(){
			cout<<"this is book's xigou."<<endl;
		}
};

class Article:public LibraryInterface{
	public:
		void accept(LibraryVisitor *lv);
		void fun(){
			cout<<"this is an article."<<endl;
		}
		~Article(){
			cout<<"this is article's xigou."<<endl;
		}
};

class LibraryVisitor{
	public:
		virtual void visit(LibraryInterface *t)=0;
		~LibraryVisitor(){
			cout<<"this is LibraryVisitor's xigou."<<endl;
		}
};

class LibrarySumPrintVisitor:public LibraryVisitor{
	public:
		void visit(LibraryInterface *t){
			t->fun();
		}
		~LibrarySumPrintVisitor(){
			cout<<"this is lspv's xigou."<<endl;
		}
};

class Manager{
	private:
		vector <LibraryInterface *> vec;
	public:
		void add(LibraryInterface *l){
			vec.push_back(l);
		}
		void request(LibraryVisitor *plv);
};

void LibraryInterface::accept(LibraryVisitor *lv){
	lv->visit(this);
}

void Manager::request(LibraryVisitor *plv){
	vector <LibraryInterface *> :: iterator it;
	for(it=vec.begin();it!=vec.end();it++)
		(*it)->accept(plv); 
}

int main (void)
{
	LibrarySumPrintVisitor *pl=new LibrarySumPrintVisitor();
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
