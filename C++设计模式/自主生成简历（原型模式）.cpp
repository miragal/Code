#include <iostream>
using namespace std;

class Cloneable{
	public:
		virtual Cloneable *clone()=0;
};

class WorkExperience:public Cloneable{
	private:
		string workdate;
		string company;
	public:
		Cloneable *clone(){
			WorkExperience *obj; 
			obj->workdate=this->workdate;
			obj->company=this->company;
			return obj;
		}
		void setW(string w){
			this->workdate=w;
		} 
		void setC(string c){
			this->company=c;
		}
		string getW(){
			return workdate;
		}
		string getC(){
			return company;
		}
}; 

class Resume:public Cloneable{
	private:
		string name,sex,age;
		WorkExperience *work;
		Resume(WorkExperience *work){
			this->work=work;
		}
	public:
		Resume(string name){
			this->name=name;
			work=new WorkExperience();
		}
		void setPersonalInfo(string sex,string age){
			this->sex=sex;
			this->age=age;
		}
		void setWork(string workdate,string company){
			work->setW(workdate);
			work->setC(company);
		}
		Cloneable *clone(){
			Resume *obj=new Resume(work); 
			obj->name=this->name;
			obj->sex=this->sex;
			obj->age=this->age;
			return obj;
		}
		void print(){
			cout<<"������"<<name<<"\t�Ա�"<<sex<<"\t���䣺"<<age<<endl; 
			cout<<"���ڣ�"<<work->getW()<<"\t��˾��"<<work->getC()<<endl; 
		}
};

int main (void)
{
	Resume *a=new Resume("����");
	a->setPersonalInfo("��","22");
	a->setWork("1998-2000","XXX��˾");
	a->print();
	Resume *b=(Resume *)a->clone();
	b->setWork("2-3","�ߺ߹���");
	b->print();
	delete a;
	delete b;
	return 0;
}
