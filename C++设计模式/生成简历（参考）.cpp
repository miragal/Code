#include<iostream>
#include<string>
using namespace std;

class Cloneable{
public:
	virtual Cloneable* Clone()=0;//定义Clone接口，根据不同的派生类来实例化对象（实现这个接口、虚函数），也就是在这个虚函数中写语言实现它！
};//这个分号一定要注意，这里不是Java

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
	//getter setter方法，原题目没有，被省略了。
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
		work = new WorkExperience();//在Resume中private声明中，新建的workexperience * work需要初始化。否则会出现指针异常，原题目被省略了。
	}
	void setPersonalInfo(string sex,string age){
		this->sex=sex;
		this->age=age;
	}
	void setWorkExperience(string workDate,string company){
		work->setWorkDate(workDate);
		work->setCompany(company);
	}
	
	void getAll(){//用来输出数据的代码，原题目没有，被省略了。
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
	Resume *a=new Resume("张三");
	a->setPersonalInfo("男","29");
	a->setWorkExperience("1998-2000","XXX公司");
	a->getAll();
	Resume *b=(Resume *)a->Clone();//这里必须通过强制类型转换才能匹配类型，部分参考答案没有强制类型转化是错误的，根本就无法通过编译。
	b->setWorkExperience("2001-2006", "YYY公司");
	b->getAll();
	return 0;
}

