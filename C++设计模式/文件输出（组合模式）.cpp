#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AbstractFile{
	protected:
		string name;
	public:
		AbstractFile(string n){
			name=n;
		}
		virtual void out()=0;
};


class Folder:public AbstractFile{
	private:
		vector <AbstractFile *> vec; 
	public:
		Folder(string n):AbstractFile(n){ }
		void add(AbstractFile *f){
			vec.push_back(f);
		}
		void out(){
			vector <AbstractFile *>:: iterator it;
			for(it=vec.begin();it!=vec.end();it++){
				cout<<name;
				(*it)->out();
			}
				
		}
};

class File:public AbstractFile{
	public:
		File(string n):AbstractFile(n){ }
		void out(){
			cout<<name<<endl;
		}
};


int main (void)
{
	Folder *root=new Folder("F:");
	File *f1=new File("1.c");
	File *f2=new File("2.c");
	File *f3=new File("3.c");
	Folder *r=new Folder("D:");
	File *f4=new File("a.c");
	root->add(f1);
	root->add(f2);
	root->add(f3);
	root->add(r);
	r->add(f4);
	root->out();
	return 0;
}
