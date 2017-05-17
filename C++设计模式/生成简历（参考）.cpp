#include<iostream>
#include<string>
using namespace std;

class Cloneable{
public:
	virtual Cloneable* Clone()=0;//����Clone�ӿڣ����ݲ�ͬ����������ʵ��������ʵ������ӿڡ��麯������Ҳ����������麯����д����ʵ������
};//����ֺ�һ��Ҫע�⣬���ﲻ��Java

class WorkExperience:public Cloneable{
private:
	string workDate;
	string company;
public:
	Cloneable* Clone(){
		WorkExperience *obj = new WorkExperience();
		obj->workDate=this->workDate;
		obj->company=this->company;
		return obj;
	}
	//getter setter������ԭ��Ŀû�У���ʡ���ˡ�
	void setWorkDate(string workDate){
		this->workDate = workDate;
	}
	void setCompany(string company){
		this->company=company;
	}
	string getWorkDate(){
		return workDate;
	}
	string getCompany(){
		return company;
	}
};

class Resume:public Cloneable{
private:
	string name;
	string age;
	string sex;
	WorkExperience* work;
	Resume(WorkExperience* work){
		this->work=work;
	}
public:
	Resume(string name){
		this->name=name;
		work = new WorkExperience();//��Resume��private�����У��½���workexperience * work��Ҫ��ʼ������������ָ���쳣��ԭ��Ŀ��ʡ���ˡ�
	}
	void setPersonalInfo(string sex,string age){
		this->sex=sex;
		this->age=age;
	}
	void setWorkExperience(string workDate,string company){
		work->setWorkDate(workDate);
		work->setCompany(company);
	}
	
	void getAll(){//����������ݵĴ��룬ԭ��Ŀû�У���ʡ���ˡ�
		cout<<work->getWorkDate()<<","<<work->getCompany()<<","<<age<<","<<sex<<endl;
	}
	
	Cloneable* Clone(){
		Resume *obj = new Resume(work);
		obj->name=this->name;
		obj->age=this->age;
		obj->sex=this->sex;
		return obj;
	}
};

int main(){
	Resume *a=new Resume("����");
	a->setPersonalInfo("��","29");
	a->setWorkExperience("1998-2000","XXX��˾");
	a->getAll();
	Resume *b=(Resume *)a->Clone();//�������ͨ��ǿ������ת������ƥ�����ͣ����ֲο���û��ǿ������ת���Ǵ���ģ��������޷�ͨ�����롣
	b->setWorkExperience("2001-2006", "YYY��˾");
	b->getAll();
	return 0;
}

