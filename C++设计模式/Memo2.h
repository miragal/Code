//#include <iostream>
//#include <string> 
//#include <vector>
//using namespace std;

class Memento;

class Originator{
	private:
		string state;
	public:
		void setState(string s);
		Memento *CreateMemento();
		void RestoreMemento(Memento *m);
		void show();
}; 
 
class Memento{
	private:
		string state;
	 	friend class Originator;
	 	Memento(string s);
};

class CareTaker{
	private:
		vector <Memento *> vec;
	public:
		void setMemento(Memento *m);
		Memento *getMemento(int i);
}; 
